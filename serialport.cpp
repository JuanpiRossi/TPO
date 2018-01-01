#include "serialport.h"


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
    idRetrys[0] = 0;
    idRetrys[1] = 0;
    idRetrys[2] = 0;
    idRetrys[3] = 0;
    idRetrys[4] = 0;

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
    serial->write(sendQByteArray);
}

bool serialPort::isOpen(){
    return serial->isOpen();
}

void serialPort::open(){
    serial->setPortName(portNameString);
    loadConfig();
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
    int cont,maxPreg;
    QByteArray tmpQByte;
    msgArray.clear();

    pregArrayBuffer[0] = pregArray[0];
    pregArrayBuffer[1] = pregArray[1];
    pregArrayBuffer[2] = pregArray[2];
    pregArrayBuffer[3] = pregArray[3];
    pregArrayBuffer[4] = pregArray[4];
    pregArrayBuffer[5] = pregArray[5];
    pregArrayBuffer[6] = pregArray[6];

    for(cont=0,maxPreg=0;cont!=7;cont++){
        if(pregArray[cont].getCantResp()>0)
            maxPreg++;
    }
    if(maxPreg!=0){
        tmpQByte = generateMsg(255,'X','X',maxPreg);
        msgArray << tmpQByte;

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

    serial->write(msgArray[cont]);
    cont++;
    if(cont==msgArray.size()){
        cont=0;
        idRetrys[0] = 0;
        idRetrys[1] = 0;
        idRetrys[2] = 0;
        idRetrys[3] = 0;
        idRetrys[4] = 0;
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

    if(id>=5){
        timerConfirmacion->stop();
        for(id=0;id!=5;id++){
            if(idRetrys[id]!=-1){
                idRetrys[id]++;
            }
        }
        id = 0;
        if(idRetrys[0]!=-1||idRetrys[1]!=-1||idRetrys[2]!=-1||idRetrys[3]!=-1||idRetrys[4]!=-1){
            retry++;
            if(retry!=3){
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
    }   else    {
        id++;
        if(idRetrys[id-1]!=-1){
            tmp = generateMsg(id,'C','C',63);
            serial->write(tmp);
        }
    }
}

void serialPort::readData(){
    int cont,XoR;
    QByteArray read = serial->readAll();
    if(read[0]=='<'&&read[1]==char(1)&&read[3]=='R'&&read[4]=='O'&&read[5]==read[6]&&read[7]=='>'){
        if(read[2]>=char(1)&&read[2]<=char(5)){
            idRetrys[read[2]-1] = -1;
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
                    idRetryInfo[read[2]-1].clear();
            }
        }
    }
    if(read[0]=='<'&&read[3]=='R'&&read[4]=='F'&&read[5]=='P'&&read[6]==char(1)&&
       read[8]=='P'&&read[9]==char(2)&&read[11]=='P'&&read[12]==char(3)&&read[14]=='P'&&read[15]==char(4)&&
       read[17]=='P'&&read[18]==char(5)&&read[20]=='P'&&read[21]==char(6)&&read[23]=='P'&&read[24]==char(7)){
        if(read[2]>=char(1)&&read[2]<=char(5)){
            if(read[6+read[1]]=='>'){
                response[read[2]-1].resize(read[1]);
                for(cont=0;cont!=read[1];cont++)
                    response[read[2]-1][cont] = read[cont+5];
                for(cont=0,XoR=0;cont!=read[1];cont++)
                    XoR = XoR^read[cont+5];
                if(!(XoR==read[5+read[1]]))
                    response[read[2]-1].clear();
            }
        }
    }
}

void serialPort::createMsgReenvio(){
    int idRetrySize[5],cont;
    QByteArray tmp;
    tmp.clear();
    idRetrySize[0] = idRetryInfo[0].size()/2;
    idRetrySize[1] = idRetryInfo[1].size()/2;
    idRetrySize[2] = idRetryInfo[2].size()/2;
    idRetrySize[3] = idRetryInfo[3].size()/2;
    idRetrySize[4] = idRetryInfo[4].size()/2;
    retryList.clear();
    for(cont=0;cont<=idRetrySize[0];cont++){
        tmp.clear();
        tmp.resize(2);
        tmp[0] = idRetryInfo[0][cont];
        cont++;
        tmp[1] = idRetryInfo[0][cont];
        if(tmp[0]!=char(0)&&tmp[1]!=char(0)&&!retryList.contains(tmp))
            retryList << tmp;
    }
    for(cont=0;cont<=idRetrySize[1];cont++){
        tmp.clear();
        tmp.resize(2);
        tmp[0] = idRetryInfo[1][cont];
        cont++;
        tmp[1] = idRetryInfo[1][cont];
        if(tmp[0]!=char(0)&&tmp[1]!=char(0)&&!retryList.contains(tmp))
            retryList << tmp;
    }
    for(cont=0;cont<=idRetrySize[2];cont++){
        tmp.clear();
        tmp.resize(2);
        tmp[0] = idRetryInfo[2][cont];
        cont++;
        tmp[1] = idRetryInfo[2][cont];
        if(tmp[0]!=char(0)&&tmp[1]!=char(0)&&!retryList.contains(tmp))
            retryList << tmp;
    }
    for(cont=0;cont<=idRetrySize[3];cont++){
        tmp.clear();
        tmp.resize(2);
        tmp[0] = idRetryInfo[3][cont];
        cont++;
        tmp[1] = idRetryInfo[3][cont];
        if(tmp[0]!=char(0)&&tmp[1]!=char(0)&&!retryList.contains(tmp))
            retryList << tmp;
    }
    for(cont=0;cont<=idRetrySize[4];cont++){
        tmp.clear();
        tmp.resize(2);
        tmp[0] = idRetryInfo[4][cont];
        cont++;
        tmp[1] = idRetryInfo[4][cont];
        if(tmp[0]!=char(0)&&tmp[1]!=char(0)&&!retryList.contains(tmp))
            retryList << tmp;
    }
    timerReenvio->start(TIMERENVIODATOS);
}

void serialPort::envioReenvioTimer(){
    int size = retryList.size();
    static int cont=0;
    QByteArray tmp;

    if(!retryList.isEmpty()){
        switch(retryList[cont][0]){
        case 'P':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'p',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getPregunta());
                    serial->write(tmp);
                }
            }
            break;
        case 'A':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'a',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaA());
                    serial->write(tmp);
                }
            }
            break;
        case 'B':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'b',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaB());
                    serial->write(tmp);
                }
            }
            break;
        case 'C':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'c',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaC());
                    serial->write(tmp);
                }
            }
            break;
        case 'D':
            if(retryList[cont][1]>=char(1)&&retryList[cont][1]<=char(7)){
                if(pregArrayBuffer[retryList[cont][1]-1].getCantResp()!=0){
                    tmp = generateMsg(255,'d',retryList[cont][1],pregArrayBuffer[retryList[cont][1]-1].getRespuestaD());
                    serial->write(tmp);
                }
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


















