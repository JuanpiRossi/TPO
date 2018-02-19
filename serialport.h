#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtSerialPort/QSerialPort>
#include "mainwindow.h"
#include "filehandler.h"
#include "preguntas.h"
#include <qbytearray.h>
#include <QTimer>
#include <QObject>

#define TIMERENVIODATOS 150
#define TIMERESPERARESPUESTA 150
#define TIMERECIBIRPUNTOS 150

class serialPort : public QObject
{
    Q_OBJECT

private:
    QSerialPort *serial;
    fileHandler file;
    QString portNameString;
    QString baudsString;
    QString parityString;
    QString dataBitsString;
    QString stopBitsString;
    QSerialPort::BaudRate baudRateGlobal;
    QSerialPort::DataBits dataBitsGlobal;
    QSerialPort::Parity parityGlobal;
    QSerialPort::StopBits stopBitsGlobal;
    QSerialPort::FlowControl flowControlGlobal;
    QByteArrayList msgArray;
    QTimer *timer;
    QTimer *timerConfirmacion;
    QTimer *timerReenvio;
    QByteArray idRetryInfo[_players_total_];
    preguntas pregArrayBuffer[7];
    QByteArrayList retryList;
public slots:
    void enviarMsgTimer();
    void readData();
    void envioConfirmacionTimer();
    void envioReenvioTimer();
signals:
    void beginGame();
public:
    serialPort();
    virtual ~serialPort();
    bool isOpen();
    void open();
    void loadConfig();
    void close();
    void createMsg(preguntas *pregArray);
    void enviarMsg();
    QByteArray generateMsg(int id, char accion1, char accion2, QByteArray msg);
    QByteArray generateMsg(int id, char accion1, char accion2, int msg);
    void envioConfirmacion();
    void createMsgReenvio();
    int idRetrys[_players_total_];
    void write(QByteArray sendQByteArray);
    QByteArray response[_players_total_];
    void createRetryListFull();
};

#endif // SERIALPORT_H
