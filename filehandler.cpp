#include "filehandler.h"

fileHandler::fileHandler()
{
}

void fileHandler::writeFile(QString playTime,QString portName,QString baudios,QString paridad,QString bitsDatos,QString bitStop)
{
    QFile file(QCoreApplication::applicationDirPath()+"\\config.txt");
    file.open(QFile::WriteOnly |QFile::Text);
    QTextStream out(&file);
    out << "playTime:"+playTime+"\n";
    out << "portName:"+portName+"\n";
    out << "baudios:"+baudios+"\n";
    out << "paridad:"+paridad+"\n";
    out << "bitsDatos:"+bitsDatos+"\n";
    out << "bitStop:"+bitStop;
    file.flush();
    file.close();
}

QString fileHandler::readFile()
{
    QFile file(QCoreApplication::applicationDirPath()+"\\config.txt");
    if(!file.open(QFile::ReadOnly |QFile::Text)){
        writeFile("15","","115200","Par","8","1");
        file.open(QFile::ReadOnly |QFile::Text);
    }
    QTextStream in(&file);
    QString myText = in.readAll();
    file.close();

    return myText;
}
