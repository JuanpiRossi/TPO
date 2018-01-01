#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>


class fileHandler
{
public:
    fileHandler();
    void writeFile(QString playTime,QString portName,QString baudios,QString paridad,QString bitsDatos,QString bitStop);
    QString readFile();

private:

};

#endif // FILEHANDLER_H
