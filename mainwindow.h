#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define _players_total_ 8
#define _repeat_message_ 3

#include <QMainWindow>
#include "config.h"
#include "preguntas.h"
#include "previsualizar.h"
#include <QObject>
#include <QTimer>
#include "serialport.h"
#include "filehandler.h"
#include "scoreboardhelper.h"
class serialPort;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_closeButton_clicked();

    void on_configButton_clicked();

    void reactivateConfig();

    void reactivatePrev();

    void on_saveButton_clicked();

    bool validacionGuardar();

    void habilitarPreguntas();

    void on_newPregButton_clicked();

    void on_pregButton_1_clicked();

    void on_pregButton_2_clicked();

    void on_pregButton_3_clicked();

    void on_pregButton_4_clicked();

    void on_pregButton_5_clicked();

    void on_pregButton_6_clicked();

    void on_pregButton_7_clicked();

    void on_removeButton_clicked();

    void on_previsualizarButton_clicked();

    void on_startButton_clicked();

    void empezarJuego();

    void finJuego();

    void pedirPuntajes();

    void procesarPuntajes();

    void on_closeButton_2_clicked();

    void on_replayButton_clicked();

    void scoreBoardWindow(int p[]);

    void on_pregunta_textChanged();

    void on_cantRespuestas_valueChanged(int value);

    void showMessage(int msgSelect);

    void moveMsg();

    void showSave();

    void moveSave();

    void changePreg(int p);
signals:
    void emitData();
private:
    Ui::MainWindow *ui;
    previsualizar *prevInstance;
    config *configInstance;
    serialPort *serial;
    fileHandler file;
    int gameTimer;
    QTimer *timerGetResp;
    QTimer *timer;
    QTimer *timerError;
    QTimer *timerGuardada;
};

#endif // MAINWINDOW_H
