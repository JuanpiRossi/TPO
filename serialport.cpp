#include "serialport.h"
#include <qdebug.h>


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

void serialPort::open(){
    int c;
    serial->setPortName(portNameString);
    loadConfig();
    for(c=0;c<_players_total_;c++)
        idRetrys[c] = 0;
    serial->open(QIODevice::ReadWrite);
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
    else if(baudsString=="115200")
        baudRateGlobal = QSerialPort::Baud115200;
    else
        baudRateGlobal = QSerialPort::Baud115200;

    if(parityString=="Par")
        parityGlobal = QSerialPort::EvenParity;
    else if(parityString=="Impar")
        parityGlobal = QSerialPort::OddParity;
    else if(parityString=="Sin paridad")
        parityGlobal = QSerialPort::NoParity;
    else
        parityGlobal = QSerialPort::EvenParity;

    if(dataBitsString=="7")
        dataBitsGlobal = QSerialPort::Data7;
    else if(dataBitsString=="8")
        dataBitsGlobal = QSerialPort::Data8;
    else
        dataBitsGlobal = QSerialPort::Data8;

    if(stopBitsString=="1")
        stopBitsGlobal = QSerialPort::OneStop;
    else if(stopBitsString=="2")
        stopBitsGlobal = QSerialPort::TwoStop;
    else
        stopBitsGlobal = QSerialPort::OneStop;

    serial->setBaudRate(baudRateGlobal);
    serial->setDataBits(dataBitsGlobal);
    serial->setParity(parityGlobal);
    serial->setStopBits(stopBitsGlobal);
    serial->setFlowControl(flowControlGlobal);
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
                    case 2:
                        tmpQByte = generateMsg(255,'A',cont+1,pregArray[cont].getRespuestaA());
                        msgArray << tmpQByte;
                        tmpQByte = generateMsg(255,'B',cont+1,pregArray[cont].getRespuestaB());
                        msgArray << tmpQByte;
                        break;
                    case 3:
                        tmpQByte = generateMsg(255,'A',cont+1,pregArray[cont].getRespuestaA());
                        msgArray << tmpQByte;
                        tmpQByte = generateMsg(255,'B',cont+1,pregArray[cont].getRespuestaB());
                        msgArray << tmpQByte;
                        tmpQByte = generateMsg(255,'C',cont+1,pregArray[cont].getRespuestaC());
                        msgArray << tmpQByte;
                        break;
                    case 4:
                        tmpQByte = generateMsg(255,'A',cont+1,pregArray[cont].getRespuestaA());
                        msgArray << tmpQByte;
                        tmpQByte = generateMsg(255,'B',cont+1,pregArray[cont].getRespuestaB());
                        msgArray << tmpQByte;
                        tmpQByte = generateMsg(255,'C',cont+1,pregArray[cont].getRespuestaC());
                        msgArray << tmpQByte;
                        tmpQByte = generateMsg(255,'D',cont+1,pregArray[cont].getRespuestaD());
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
    timer->start(TIMERENVIODATOS);
}

void serialPort::enviarMsgTimer(){
    static int cont=0;

    write(msgArray[cont]);
    cont++;
    if(cont>=msgArray.size()){
        for(cont=0;cont<_players_total_;cont++)
            idRetrys[cont] = 0;
        cont=0;
        timer->stop();
        envioConfirmacion();
    }
}

void serialPort::envioConfirmacion(){
    timerConfirmacion->start(TIMERESPERARESPUESTA);
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
                tmp = generateMsg(id,'G',id,63);
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
            if(retry!=_repeat_message_){
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
    QByteArray read = serial->readAll();
    qDebug() << "Recibido: " << read.toHex();
    if(read[0]=='<'&&read[1]==char(1)&&read[3]=='R'&&read[4]=='O'&&read[5]==read[6]&&read[7]=='>'){
        if(read[2]>=char(0)&&read[2]<=char(7)){

            idRetrys[read[2]] = -1;
        }
    }
    if(read[0]=='<'&&read[3]=='R'&&read[4]=='M'){
        if(read[2]>=char(1)&&read[2]<=char(5)){
            if(read[6+read[1]]=='>'){
                idRetryInfo[read[2]-1].resize(read[1]);
                for(cont=0;cont!=read[1];cont++)
                    idRetryInfo[read[2]-1][cont] = read[cont+5];
                for(cont=0,XoR=0;cont!=read[1];cont++)
                    XoR = XoR^read[cont+5];
                if(!(XoR==read[5+read[1]]))
                    idRetryInfo[read[2]].clear();
            }
        }
    }
    if(read[0]=='<'&&read[3]=='R'&&read[4]=='F'&&read[5]=='P'&&read[6]==char(1)&&
            read[8]=='P'&&read[9]==char(2)&&read[11]=='P'&&read[12]==char(3)&&read[14]=='P'&&read[15]==char(4)&&
            read[17]=='P'&&read[18]==char(5)&&read[20]=='P'&&read[21]==char(6)&&read[23]=='P'&&read[24]==char(7)){
        if(read[2]>=char(1)&&read[2]<=char(5)){
            if(read[6+read[1]]=='>'){
                response[read[2]].resize(read[1]);
                for(cont=0;cont!=read[1];cont++)
                    response[read[2]][cont] = read[cont+5];
                for(cont=0,XoR=0;cont!=read[1];cont++)
                    XoR ^= read[cont+5];
                if(!(XoR==read[5+read[1]]))
                    response[read[2]].clear();
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
    timerReenvio->start(TIMERENVIODATOS);
}

void serialPort::envioReenvioTimer(){
    int size = retryList.size();
    int maxPreg,contMax;
    static int cont=0;
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
    cont++;
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
















