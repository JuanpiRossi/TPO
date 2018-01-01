#include "config.h"
#include "ui_config.h"
#include <QSerialPortInfo>
#include "filehandler.h"
#include <QRegExp>


fileHandler file;

config::config(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::config)
{
    ui->setupUi(this);
    loadConfig();
    ui->playTime->setValue(playTime);
    ui->portCombo->setCurrentText(portName);
    ui->baudsCombo->setCurrentText(bauds);
    ui->parityCombo->setCurrentText(parity);
    ui->dataCombo->setCurrentText(dataBits);
    ui->stopCombo->setCurrentText(stopBits);
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        ui->portCombo->addItem(info.portName());
    }
}

config::~config()
{
    delete ui;
}

void config::on_closeButton_clicked()
{
    this->close();
}

void config::on_saveButton_clicked()
{
    file.writeFile(ui->playTime->text(),
                   ui->portCombo->currentText(),
                   ui->baudsCombo->currentText(),
                   ui->parityCombo->currentText(),
                   ui->dataCombo->currentText(),
                   ui->stopCombo->currentText());
}

void config::loadConfig(){
    QString fileContent = file.readFile();
    QRegExp rx("playTime:([0-9]*)\n"
               "portName:([^\n]*)\n"
               "baudios:([^\n]*)\n"
               "paridad:([^\n]*)\n"
               "bitsDatos:([^\n]*)\n"
               "bitStop:([^\n]*)");
    rx.indexIn(fileContent);

    playTime = rx.capturedTexts()[1].toInt();
    portName = rx.capturedTexts()[2];
    bauds = rx.capturedTexts()[3];
    parity = rx.capturedTexts()[4];
    dataBits = rx.capturedTexts()[5];
    stopBits = rx.capturedTexts()[6];
}

int config::getPlayTime(){
    return playTime;
}

QString config::getPortName(){
    return portName;
}

QString config::getBauds(){
    return bauds;
}

QString config::getParity(){
    return parity;
}

QString config::getDataBits(){
    return dataBits;
}

QString config::getStopBits(){
    return stopBits;
}

void config::closeEvent(QCloseEvent *event) {
    emit(exiting());
}












