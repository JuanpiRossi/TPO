#include "serialport.h"
#include <qdebug.h>
#define estimatedInfoTransfer 200

QString baud[]={"115200","57600","38400","19200","9600","4800","2400","1200"};


int total_bits;
int timeTimer;

serialPort::serialPort()
{
    serial = new QSerialPort(this);
    flowControlGlobal = QSerialPort::NoFlowControl;
    QString fileContent = file.readFile();
    QRegExp rx("playTime:([0-9]*)\n"
               "portName:([^\n]*)\n"
               "baudios:([^\n]*)\n"
               "paridad:([^\n]*)\n"
               "bitsDatos:([^\n]*)\n"
               "bitStop:([^\n]*)");
    rx.indexIn(fileContent);

    portNameString = rx.capturedTexts()[2];
    baudsString = rx.capturedTexts()[3];
    parityString = rx.capturedTexts()[4];
    dataBitsString = rx.capturedTexts()[5];
    stopBitsString = rx.capturedTexts()[6];

    timer = new QTimer(this);
    timerConfirmacion = new QTimer(this);
    timerReenvio = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(enviarMsgTimer()));
    QObject::connect(timerConfirmacion,SIGNAL(timeout()),this,SLOT(envioConfirmacionTimer()));
    QObject::connect(timerReenvio,SIGNAL(timeout()),this,SLOT(envioReenvioTimer()));
    connect(serial, &QSerialPort::readyRead, this, serialPort::readData);
}

serialPort::~serialPort() {
    timer->stop();
    delete timer;
}

void serialPort::write(QByteArray sendQByteArray){
    qDebug() << "send: " << sendQByteArray.toHex();
    serial->write(sendQByteArray);
}

bool serialPort::isOpen(){
    return serial->isOpen();
}

void serialPort::open(bool isDefault){
    int c;
    serial->setPortName(portNameString);
    if(isDefault)
        setDefaultConfig();
    else{
        setLoadedConfig();
    }
    for(c=0;c<_players_total_;c++)
        idRetrys[c] = 0;
    serial->open(QIODevice::ReadWrite);
}
void serialPort::setDefaultConfig(){
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity( QSerialPort::EvenParity);
    serial->setStopBits(QSerialPort::TwoStop);
    serial->setFlowControl(flowControlGlobal);
    timeTimer=((estimatedInfoTransfer*(8+1+3)*1000/115200))+1;
}
void serialPort::loadConfig(){
    QString fileContent = file.readFile();
    QRegExp rx("playTime:([0-9]*)\n"
               "portName:([^\n]*)\n"
               "baudios:([^\n]*)\n"
               "paridad:([^\n]*)\n"
               "bitsDatos:([^\n]*)\n"
               "bitStop:([^\n]*)");
    rx.indexIn(fileContent);

    portNameString = rx.capturedTexts()[2];
    baudsString = rx.capturedTexts()[3];
    parityString = rx.capturedTexts()[4];
    dataBitsString = rx.capturedTexts()[5];
    stopBitsString = rx.capturedTexts()[6];
    if(baudsString=="1200")
        baudRateGlobal = QSerialPort::Baud1200;
    else if(baudsString=="2400")
        baudRateGlobal = QSerialPort::Baud2400;
    else if(baudsString=="4800")
        baudRateGlobal = QSerialPort::Baud4800;
    else if(baudsString=="9600")
        baudRateGlobal = QSerialPort::Baud9600;
    else if(baudsString=="19200")
        baudRateGlobal = QSerialPort::Baud19200;
    else if(baudsString=="38400")
        baudRateGlobal = QSerialPort::Baud38400;
    else if(baudsString=="57600")
        baudRateGlobal = QSerialPort::Baud57600;
    else
        baudRateGlobal = QSerialPort::Baud115200;

    if(parityString=="Impar")
        parityGlobal = QSerialPort::OddParity;
    else if(parityString=="Sin paridad")
        parityGlobal = QSerialPort::NoParity;
    else
        parityGlobal = QSerialPort::EvenParity;

    if(dataBitsString=="7")
        dataBitsGlobal = QSerialPort::Data7;
    else
        dataBitsGlobal = QSerialPort::Data8;

    if(stopBitsString=="1")
        stopBitsGlobal = QSerialPort::OneStop;
    else
        stopBitsGlobal = QSerialPort::TwoStop;
}
void serialPort::setLoadedConfig(){
    serial->setBaudRate(baudRateGlobal);
    serial->setDataBits(dataBitsGlobal);
    serial->setParity(parityGlobal);
    serial->setStopBits(stopBitsGlobal);
    serial->setFlowControl(flowControlGlobal);
    long BR;

    if(baudRateGlobal==QSerialPort::Baud1200)
        BR=1200;
    else if(baudRateGlobal==QSerialPort::Baud2400)
        BR = 2400;
    else if(baudRateGlobal==QSerialPort::Baud4800)
        BR = 4800;
    else if(baudRateGlobal==QSerialPort::Baud9600)
        BR = 9600;
    else if(baudRateGlobal==QSerialPort::Baud19200)
        BR = 19200;
    else if(baudRateGlobal==QSerialPort::Baud38400)
        BR = 38400;
    else if(baudRateGlobal==QSerialPort::Baud57600)
        BR = 57600;
    else
        BR = 115200;
    total_bits=0;
    if(parityGlobal!=QSerialPort::NoParity)
        total_bits+=1;
    total_bits+=7;
    if(dataBitsGlobal==QSerialPort::Data8)
        total_bits+=1;

    total_bits+=2;
    if(stopBitsGlobal==QSerialPort::TwoStop)
        total_bits+=1;
    timeTimer=(((estimatedInfoTransfer*total_bits*1000/BR)))+1;
}
void serialPort::close(){
    serial->close();
}

void serialPort::createMsg(preguntas *pregArray){
    int cont,maxPreg,auxcont;
    QByteArray tmpQByte;
    msgArray.clear();

    for(cont=0;cont<7;cont++)
    {
        pregArrayBuffer[cont] = pregArray[cont];
    }

    for(cont=0,maxPreg=0;cont!=7;cont++){
        if(pregArray[cont].getCantResp()>0)
            maxPreg++;
    }
    if(maxPreg!=0){
        int baudValue;
        loadConfig();
        for(cont=0;cont<8;cont++)
        {
            if(baud[cont] == baudsString){
                baudValue=cont;
            }
        }
        for(auxcont=0;auxcont<_repeat_message_;auxcont++)
        {
            tmpQByte = generateMsg(255,'S','B',baudValue+1);
            msgArray << tmpQByte;
        }
        for(auxcont=0;auxcont<_repeat_message_;auxcont++)
        {
            tmpQByte = generateMsg(255,'X','X',maxPreg);
            msgArray << tmpQByte;
        }

        for(auxcont=0;auxcont<_repeat_message_;auxcont++)
        {
            for(cont=0;cont!=(maxPreg+1);cont++){
                if(pregArray[cont].getCantResp()>0){
                    tmpQByte = generateMsg(255,'P',cont+1,pregArray[cont].getPregunta());
                    msgArray << tmpQByte;
                    tmpQByte = generateMsg(255,'N',cont+1,pregArray[cont].getCantResp());
                    msgArray << tmpQByte;
                    switch(pregArray[cont].getCantResp()){
                    case 4:
                        tmpQByte = generateMsg(255,'D',cont+1,pregArray[cont].getRespuestaD());
                        msgArray << tmpQByte;
                    case 3:
                        tmpQByte = generateMsg(255,'C',cont+1,pregArray[cont].getRespuestaC());
                        msgArray << tmpQByte;
                    case 2:
                        tmpQByte = generateMsg(255,'A',cont+1,pregArray[cont].getRespuestaA());
                        msgArray << tmpQByte;
                        tmpQByte = generateMsg(255,'B',cont+1,pregArray[cont].getRespuestaB());
                        msgArray << tmpQByte;
                        break;
                    }
                }
            }
        }
    }
}

QByteArray serialPort::generateMsg(int id, char accion1, char accion2, QByteArray msg){
    QByteArray tmp;
    int msgSize,cont,XoR;

    msgSize = msg.size();

    tmp.resize(7+msgSize);

    tmp[0] = '<';
    tmp[1] = msgSize;
    tmp[2] = id;
    tmp[3] = accion1;
    tmp[4] = accion2;
    tmp[6+msgSize] = '>';

    for(cont=0,XoR=0;cont!=msgSize;cont++){
        tmp[5+cont] = msg[cont];
        XoR = XoR ^ msg[cont];
    }
    if(XoR==0)
        XoR++;
    tmp[5+cont] = XoR;

    return tmp;
}

QByteArray serialPort::generateMsg(int id, char accion1, char accion2, int msg){
    QByteArray tmp;

    tmp.resize(8);
    tmp[0] = '<';
    tmp[1] = 1;
    tmp[2] = id;
    tmp[3] = accion1;
    tmp[4] = accion2;
    tmp[5] = msg;
    tmp[6] = msg;
    tmp[7] = '>';

    return tmp;
}

void serialPort::enviarMsg(){
    timer->start(timeTimer);
}

void serialPort::enviarMsgTimer(){
    static int cont=0;

    write(msgArray[cont]);
    cont++;
    if(cont==_repeat_message_){
        this->close();
        this->open(false);
        timer->stop();
        timer->start(timeTimer);
    }
    if(cont>=msgArray.size()){
        for(cont=0;cont<_players_total_;cont++)
            idRetrys[cont] = 0;
        cont=0;
        timer->stop();
        envioConfirmacion();
    }
}


void serialPort::envioConfirmacion(){
    timerConfirmacion->start(timeTimer);
}

void serialPort::envioConfirmacionTimer(){
    static int id=0, retry=0;
    QByteArray tmp;

    if(id<_players_total_){
        static int c=0;
        while(idRetrys[id]==-1&&id<_players_total_){
            id++;
            c=0;
        }
        if(id<_players_total_)
        {
            if(c<_repeat_message_){
                tmp = generateMsg(id+1,'G',1,63);
                write(tmp);
                c++;
                if(c>=_repeat_message_){
                    c=0;
                    id++;
                }
            }
        }
    }   else    {
        int retryflag=0,i;
        timerConfirmacion->stop();
        for(id=0;id<_players_total_;id++){
            if(idRetrys[id]!=-1){
                idRetrys[id]++;
            }
        }
        id = 0;
        for(i=0;i<_players_total_;i++){
            if(idRetrys[i]==-1)
                retryflag++;
        }
        if(retryflag!=0){
            retry++;
            if(retry<_repeat_message_){
                createMsgReenvio();
            }
            else{
                id=0;
                retry=0;
                emit(beginGame());
            }
        }   else    {
            id=0;
            retry=0;
            emit(beginGame());
        }
    }
}

void serialPort::readData(){
    int cont,XoR;
    static QByteArray info=serial->readAll();
    QByteArray read = serial->readAll();
    info=info+read;
    qDebug() << "Recibido: " << read.toHex();
    qDebug() << "Recibido2: " << info.toHex();
    for(cont=0;cont<info.size();cont++){
        QByteArray msg;
        int cont2;
        for(cont2=0;cont<info.size();cont2++){
            if(info[cont2]=='<')
                break;
        }
        if(info[cont2]!='<'){
            info.clear();
            cont=0;
            return;
        }
        info=info.right(info.size()-cont2);
        for(cont2=0;cont2<info.size();cont2++){
            if(info[cont2]=='>')
                break;
        }
        msg=info.left(cont2+1);
        qDebug() << "RecibidoParsed: " << msg.toHex();
        info=info.right(info.size()-cont2-1);
        cont=0;
        qDebug() << "NewInfo: " << info.toHex();

        if(msg.size()>=8){
            if(msg[0]=='<'&&msg[1]==char(1)&&msg[3]=='R'&&msg[4]=='O'&&msg[5]==msg[6]&&msg[7]=='>'){
                if(msg[2]>=char(1)&&msg[2]<=char(8)){
                    idRetrys[msg[2]-1] = -1;
                }
            }
            if(msg[0]=='<'&&msg[3]=='R'&&msg[4]=='M'){
                if(msg[2]>=char(1)&&msg[2]<=char(8)){
                    if(msg[6+msg[1]]=='>'){
                        idRetryInfo[msg[2]-1].resize(msg[1]);
                        for(cont=0;cont!=msg[1];cont++)
                            idRetryInfo[msg[2]-1][cont] = msg[cont+5];
                        for(cont=0,XoR=0;cont!=msg[1];cont++)
                            XoR = XoR^msg[cont+5];
                        if(XoR==0)
                            XoR=1;
                        if(!(XoR==msg[5+msg[1]]))
                            idRetryInfo[msg[2]-1].clear();
                    }
                }
            }
            if(msg[0]=='<'&&msg[3]=='R'&&msg[4]=='F'&&msg[5]=='P'&&msg[6]==char(1)&&
                    msg[8]=='P'&&msg[9]==char(2)&&msg[11]=='P'&&msg[12]==char(3)&&msg[14]=='P'&&msg[15]==char(4)&&
                    msg[17]=='P'&&msg[18]==char(5)&&msg[20]=='P'&&msg[21]==char(6)&&msg[23]=='P'&&msg[24]==char(7)){
                if(msg[2]>=char(1)&&msg[2]<=char(8)){
                    if(msg[6+msg[1]]=='>'){
                        response[msg[2]-1].resize(msg[1]);
                        for(cont=0;cont<msg[1];cont++)
                            response[msg[2]-1][cont] = msg[cont+5];
                        for(cont=0,XoR=0;cont<msg[1];cont++)
                            XoR ^= msg[cont+5];
                        if(XoR==0)
                            XoR=1;
                        if(!(XoR==msg[5+msg[1]]))
                            response[msg[2]-1].clear();
                    }
                }
            }
        }
    }
}

void serialPort::createMsgReenvio(){
    int idRetrySize[_players_total_],cont,cont2,cont3;
    QByteArray tmp;
    tmp.clear();
    for(cont3=0;cont3<_repeat_message_;cont3++){
        for(cont=0;cont<=_players_total_;cont++){
            idRetrySize[cont] = idRetryInfo[cont].size()/2;
        }
        retryList.clear();
        for(cont2=0;cont2<_players_total_;cont2++){
            for(cont=0;cont<=idRetrySize[cont2];cont++){
                tmp.clear();
                tmp.resize(2);
                tmp[0] = idRetryInfo[cont2][cont];
                cont++;
                tmp[1] = idRetryInfo[cont2][cont];
                if(tmp[0]!=char(0)&&tmp[1]!=char(0)&&!retryList.contains(tmp))
                    retryList << tmp;
            }
        }
        qDebug() << retryList.indexOf("XX");
        if(retryList.indexOf("XX")!=-1){
            retryList.clear();
            createRetryListFull();
        }
    }
    timerReenvio->start(timeTimer);
}

void serialPort::envioReenvioTimer(){
    int size = retryList.size();
    int maxPreg,contMax;
    static int cont=0,contrepeatmsg=0;
    QByteArray tmp;

    qDebug() << "Retry list: " << retryList << "Size> " << size;
    if(!retryList.isEmpty()){
        switch(retryList[cont][0]){
        case 'P':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'P',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getPregunta());
                    write(tmp);
                }
            }
            break;
        case 'A':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'A',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaA());
                    write(tmp);
                }
            }
            break;
        case 'B':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'B',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaB());
                    write(tmp);
                }
            }
            break;
        case 'C':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'C',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaC());
                    write(tmp);
                }
            }
            break;
        case 'D':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'D',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaD());
                    write(tmp);
                }
            }
            break;
        case 'N':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'N',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getCantResp());
                    write(tmp);
                }
            }
            break;
        case 'X':
            if(retryList[cont][1]=='X'){
                for(contMax=0,maxPreg=0;contMax!=7;contMax++){
                    if(pregArrayBuffer[contMax].getCantResp()>0)
                        maxPreg++;
                }
                tmp = generateMsg(255,'X','X',maxPreg);
                write(tmp);
            }
            break;
        }
    }
    if(contrepeatmsg<_repeat_message_){
        contrepeatmsg++;
        if(contrepeatmsg>=_repeat_message_){
            cont++;
            contrepeatmsg=0;
        }
    }
    if(cont>=size){
        cont=0;
        timerReenvio->stop();
        envioConfirmacion();
    }
}

void serialPort::createRetryListFull(){
    int cont = 1;
    QByteArray tmpArray;

    tmpArray.clear();
    tmpArray.resize(2);
    tmpArray[0] = 'X';
    tmpArray[1] = 'X';

    retryList << tmpArray;

    for(cont=0;cont!=7;cont++){
        if(pregArrayBuffer[cont].getCantResp()!=0){
            tmpArray.clear();
            tmpArray.resize(2);
            tmpArray[0] = 'P';
            tmpArray[1] = cont+1;
            retryList << tmpArray;

            tmpArray.clear();
            tmpArray.resize(2);
            tmpArray[0] = 'N';
            tmpArray[1] = cont+1;
            retryList << tmpArray;

            tmpArray.clear();
            tmpArray.resize(2);
            tmpArray[0] = 'A';
            tmpArray[1] = cont+1;
            retryList << tmpArray;

            tmpArray.clear();
            tmpArray.resize(2);
            tmpArray[0] = 'B';
            tmpArray[1] = cont+1;
            retryList << tmpArray;

            if(pregArrayBuffer[cont].getCantResp()>2){
                tmpArray.clear();
                tmpArray.resize(2);
                tmpArray[0] = 'C';
                tmpArray[1] = cont+1;
                retryList << tmpArray;
            }

            if(pregArrayBuffer[cont].getCantResp()>3){
                tmpArray.clear();
                tmpArray.resize(2);
                tmpArray[0] = 'D';
                tmpArray[1] = cont+1;
                retryList << tmpArray;
            }
        }
    }
}

