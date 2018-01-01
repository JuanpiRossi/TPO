#ifndef CONFIG_H
#define CONFIG_H

#include <QMainWindow>

namespace Ui {
class config;
}

class config : public QMainWindow
{
    Q_OBJECT

public:
    explicit config(QWidget *parent = 0);
    void loadConfig();
    int getPlayTime();
    QString getPortName();
    QString getBauds();
    QString getParity();
    QString getDataBits();
    QString getStopBits();
    ~config();
signals:
    void exiting();
protected:
     void closeEvent(QCloseEvent *event);

private slots:
    void on_closeButton_clicked();

    void on_saveButton_clicked();

private:
    int playTime;
    QString portName;
    QString bauds;
    QString parity;
    QString dataBits;
    QString stopBits;
    Ui::config *ui;
};

#endif // CONFIG_H
