/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *gameState;
    QWidget *page;
    QGroupBox *principalBox;
    QTextEdit *pregunta;
    QLineEdit *respA;
    QLineEdit *respB;
    QLineEdit *respC;
    QLineEdit *respD;
    QCheckBox *checkBoxA;
    QCheckBox *checkBoxB;
    QCheckBox *checkBoxC;
    QCheckBox *checkBoxD;
    QLabel *labelRespB;
    QLabel *labelRespA;
    QLabel *labelRespC;
    QLabel *labelRespD;
    QLabel *labelPregunta;
    QLabel *labelCantResp;
    QSpinBox *cantRespuestas;
    QPushButton *pregButton_7;
    QPushButton *pregButton_4;
    QPushButton *pregButton_6;
    QPushButton *pregButton_3;
    QPushButton *pregButton_1;
    QPushButton *pregButton_2;
    QPushButton *pregButton_5;
    QPushButton *startButton;
    QPushButton *saveButton;
    QPushButton *configButton;
    QPushButton *newPregButton;
    QPushButton *removeButton;
    QPushButton *previsualizarButton;
    QPushButton *closeButton;
    QWidget *mensajeError;
    QLabel *msgErrorGuardar;
    QLabel *msgErrorComunicacion;
    QWidget *mensajeGuardar;
    QLabel *label_3;
    QWidget *page_2;
    QGroupBox *gameInProgressBox;
    QLabel *label;
    QWidget *page_3;
    QGroupBox *groupBox;
    QPushButton *closeButton_2;
    QPushButton *replayButton;
    QLabel *label_2;
    QLabel *puntajePrimerPuesto;
    QLabel *puntajeSegundoPuesto;
    QLabel *puntajeTercerPuesto;
    QLabel *puntajeCuartoPuesto;
    QLabel *puntajeQuintoPuesto;
    QLabel *puntajeSextoPuesto;
    QLabel *puntajeSeptimoPuesto;
    QLabel *puntajeOctavoPuesto;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(511, 291);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gameState = new QStackedWidget(centralWidget);
        gameState->setObjectName(QStringLiteral("gameState"));
        gameState->setGeometry(QRect(0, 0, 511, 291));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        principalBox = new QGroupBox(page);
        principalBox->setObjectName(QStringLiteral("principalBox"));
        principalBox->setGeometry(QRect(10, 10, 491, 271));
        pregunta = new QTextEdit(principalBox);
        pregunta->setObjectName(QStringLiteral("pregunta"));
        pregunta->setGeometry(QRect(20, 40, 391, 51));
        pregunta->setTabChangesFocus(true);
        respA = new QLineEdit(principalBox);
        respA->setObjectName(QStringLiteral("respA"));
        respA->setGeometry(QRect(20, 120, 181, 20));
        respA->setMaxLength(20);
        respB = new QLineEdit(principalBox);
        respB->setObjectName(QStringLiteral("respB"));
        respB->setGeometry(QRect(20, 180, 181, 20));
        respB->setMaxLength(20);
        respC = new QLineEdit(principalBox);
        respC->setObjectName(QStringLiteral("respC"));
        respC->setGeometry(QRect(270, 120, 181, 20));
        respC->setMaxLength(20);
        respD = new QLineEdit(principalBox);
        respD->setObjectName(QStringLiteral("respD"));
        respD->setGeometry(QRect(270, 180, 181, 20));
        respD->setMaxLength(20);
        checkBoxA = new QCheckBox(principalBox);
        checkBoxA->setObjectName(QStringLiteral("checkBoxA"));
        checkBoxA->setGeometry(QRect(210, 120, 16, 17));
        checkBoxA->setAutoExclusive(true);
        checkBoxA->setTristate(false);
        checkBoxB = new QCheckBox(principalBox);
        checkBoxB->setObjectName(QStringLiteral("checkBoxB"));
        checkBoxB->setGeometry(QRect(210, 180, 16, 17));
        checkBoxB->setAutoExclusive(true);
        checkBoxB->setTristate(false);
        checkBoxC = new QCheckBox(principalBox);
        checkBoxC->setObjectName(QStringLiteral("checkBoxC"));
        checkBoxC->setGeometry(QRect(460, 120, 16, 17));
        checkBoxC->setAutoExclusive(true);
        checkBoxC->setTristate(false);
        checkBoxD = new QCheckBox(principalBox);
        checkBoxD->setObjectName(QStringLiteral("checkBoxD"));
        checkBoxD->setGeometry(QRect(460, 180, 16, 17));
        checkBoxD->setAutoExclusive(true);
        checkBoxD->setTristate(false);
        labelRespB = new QLabel(principalBox);
        labelRespB->setObjectName(QStringLiteral("labelRespB"));
        labelRespB->setGeometry(QRect(20, 160, 121, 16));
        labelRespA = new QLabel(principalBox);
        labelRespA->setObjectName(QStringLiteral("labelRespA"));
        labelRespA->setGeometry(QRect(20, 100, 121, 16));
        labelRespC = new QLabel(principalBox);
        labelRespC->setObjectName(QStringLiteral("labelRespC"));
        labelRespC->setGeometry(QRect(270, 100, 121, 16));
        labelRespD = new QLabel(principalBox);
        labelRespD->setObjectName(QStringLiteral("labelRespD"));
        labelRespD->setGeometry(QRect(270, 160, 121, 16));
        labelPregunta = new QLabel(principalBox);
        labelPregunta->setObjectName(QStringLiteral("labelPregunta"));
        labelPregunta->setGeometry(QRect(20, 20, 91, 16));
        labelCantResp = new QLabel(principalBox);
        labelCantResp->setObjectName(QStringLiteral("labelCantResp"));
        labelCantResp->setGeometry(QRect(420, 50, 61, 41));
        cantRespuestas = new QSpinBox(principalBox);
        cantRespuestas->setObjectName(QStringLiteral("cantRespuestas"));
        cantRespuestas->setGeometry(QRect(430, 90, 42, 22));
        cantRespuestas->setMinimum(2);
        cantRespuestas->setMaximum(4);
        cantRespuestas->setValue(4);
        pregButton_7 = new QPushButton(principalBox);
        pregButton_7->setObjectName(QStringLiteral("pregButton_7"));
        pregButton_7->setGeometry(QRect(190, 240, 31, 23));
        pregButton_4 = new QPushButton(principalBox);
        pregButton_4->setObjectName(QStringLiteral("pregButton_4"));
        pregButton_4->setGeometry(QRect(100, 240, 31, 23));
        pregButton_6 = new QPushButton(principalBox);
        pregButton_6->setObjectName(QStringLiteral("pregButton_6"));
        pregButton_6->setGeometry(QRect(160, 240, 31, 23));
        pregButton_3 = new QPushButton(principalBox);
        pregButton_3->setObjectName(QStringLiteral("pregButton_3"));
        pregButton_3->setGeometry(QRect(70, 240, 31, 23));
        pregButton_1 = new QPushButton(principalBox);
        pregButton_1->setObjectName(QStringLiteral("pregButton_1"));
        pregButton_1->setGeometry(QRect(10, 240, 31, 23));
        pregButton_2 = new QPushButton(principalBox);
        pregButton_2->setObjectName(QStringLiteral("pregButton_2"));
        pregButton_2->setGeometry(QRect(40, 240, 31, 23));
        pregButton_5 = new QPushButton(principalBox);
        pregButton_5->setObjectName(QStringLiteral("pregButton_5"));
        pregButton_5->setGeometry(QRect(130, 240, 31, 23));
        startButton = new QPushButton(principalBox);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(430, 215, 50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/playButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        startButton->setIcon(icon);
        startButton->setIconSize(QSize(40, 40));
        saveButton = new QPushButton(principalBox);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(380, 215, 50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/saveButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(40, 40));
        configButton = new QPushButton(principalBox);
        configButton->setObjectName(QStringLiteral("configButton"));
        configButton->setGeometry(QRect(330, 215, 50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/configButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        configButton->setIcon(icon2);
        configButton->setIconSize(QSize(40, 40));
        newPregButton = new QPushButton(principalBox);
        newPregButton->setObjectName(QStringLiteral("newPregButton"));
        newPregButton->setEnabled(true);
        newPregButton->setGeometry(QRect(280, 215, 50, 50));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/plusButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        newPregButton->setIcon(icon3);
        newPregButton->setIconSize(QSize(40, 40));
        removeButton = new QPushButton(principalBox);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(230, 215, 50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/minusButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton->setIcon(icon4);
        removeButton->setIconSize(QSize(40, 40));
        previsualizarButton = new QPushButton(principalBox);
        previsualizarButton->setObjectName(QStringLiteral("previsualizarButton"));
        previsualizarButton->setGeometry(QRect(80, 215, 75, 23));
        closeButton = new QPushButton(principalBox);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(440, 0, 50, 50));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/closebutton.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon5);
        closeButton->setIconSize(QSize(50, 50));
        mensajeError = new QWidget(page);
        mensajeError->setObjectName(QStringLiteral("mensajeError"));
        mensajeError->setGeometry(QRect(140, -90, 221, 91));
        msgErrorGuardar = new QLabel(mensajeError);
        msgErrorGuardar->setObjectName(QStringLiteral("msgErrorGuardar"));
        msgErrorGuardar->setGeometry(QRect(20, 10, 181, 81));
        msgErrorComunicacion = new QLabel(mensajeError);
        msgErrorComunicacion->setObjectName(QStringLiteral("msgErrorComunicacion"));
        msgErrorComunicacion->setGeometry(QRect(20, 10, 181, 71));
        mensajeGuardar = new QWidget(page);
        mensajeGuardar->setObjectName(QStringLiteral("mensajeGuardar"));
        mensajeGuardar->setGeometry(QRect(170, -40, 161, 41));
        label_3 = new QLabel(mensajeGuardar);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 6, 151, 31));
        gameState->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gameInProgressBox = new QGroupBox(page_2);
        gameInProgressBox->setObjectName(QStringLiteral("gameInProgressBox"));
        gameInProgressBox->setGeometry(QRect(10, 10, 491, 271));
        label = new QLabel(gameInProgressBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 501, 171));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        gameState->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 491, 271));
        closeButton_2 = new QPushButton(groupBox);
        closeButton_2->setObjectName(QStringLiteral("closeButton_2"));
        closeButton_2->setGeometry(QRect(410, 240, 75, 23));
        replayButton = new QPushButton(groupBox);
        replayButton->setObjectName(QStringLiteral("replayButton"));
        replayButton->setGeometry(QRect(330, 240, 75, 23));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 0, 211, 51));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        puntajePrimerPuesto = new QLabel(groupBox);
        puntajePrimerPuesto->setObjectName(QStringLiteral("puntajePrimerPuesto"));
        puntajePrimerPuesto->setGeometry(QRect(110, 20, 191, 21));
        puntajeSegundoPuesto = new QLabel(groupBox);
        puntajeSegundoPuesto->setObjectName(QStringLiteral("puntajeSegundoPuesto"));
        puntajeSegundoPuesto->setGeometry(QRect(110, 50, 191, 21));
        puntajeTercerPuesto = new QLabel(groupBox);
        puntajeTercerPuesto->setObjectName(QStringLiteral("puntajeTercerPuesto"));
        puntajeTercerPuesto->setGeometry(QRect(110, 80, 191, 21));
        puntajeCuartoPuesto = new QLabel(groupBox);
        puntajeCuartoPuesto->setObjectName(QStringLiteral("puntajeCuartoPuesto"));
        puntajeCuartoPuesto->setGeometry(QRect(110, 110, 191, 21));
        puntajeQuintoPuesto = new QLabel(groupBox);
        puntajeQuintoPuesto->setObjectName(QStringLiteral("puntajeQuintoPuesto"));
        puntajeQuintoPuesto->setGeometry(QRect(110, 140, 191, 21));
        puntajeSextoPuesto = new QLabel(groupBox);
        puntajeSextoPuesto->setObjectName(QStringLiteral("puntajeSextoPuesto"));
        puntajeSextoPuesto->setGeometry(QRect(110, 170, 191, 21));
        puntajeSeptimoPuesto = new QLabel(groupBox);
        puntajeSeptimoPuesto->setObjectName(QStringLiteral("puntajeSeptimoPuesto"));
        puntajeSeptimoPuesto->setGeometry(QRect(110, 200, 191, 21));
        puntajeOctavoPuesto = new QLabel(groupBox);
        puntajeOctavoPuesto->setObjectName(QStringLiteral("puntajeOctavoPuesto"));
        puntajeOctavoPuesto->setGeometry(QRect(110, 230, 191, 21));

        gameState->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        gameState->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        principalBox->setTitle(QString());
        checkBoxA->setText(QString());
        checkBoxB->setText(QString());
        checkBoxC->setText(QString());
        checkBoxD->setText(QString());
        labelRespB->setText(QApplication::translate("MainWindow", "Respuesta B:", nullptr));
        labelRespA->setText(QApplication::translate("MainWindow", "Respuesta A:", nullptr));
        labelRespC->setText(QApplication::translate("MainWindow", "Respuesta C:", nullptr));
        labelRespD->setText(QApplication::translate("MainWindow", "Respuesta D:", nullptr));
        labelPregunta->setText(QApplication::translate("MainWindow", "Pregunta 1:", nullptr));
        labelCantResp->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Cantidad de<br/>respuestas:</p></body></html>", nullptr));
        pregButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        pregButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pregButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        pregButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pregButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pregButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pregButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
#ifndef QT_NO_TOOLTIP
        startButton->setToolTip(QApplication::translate("MainWindow", "Empezar partida", nullptr));
#endif // QT_NO_TOOLTIP
        startButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("MainWindow", "Guardar partida", nullptr));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        configButton->setToolTip(QApplication::translate("MainWindow", "Configuracion", nullptr));
#endif // QT_NO_TOOLTIP
        configButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        newPregButton->setToolTip(QApplication::translate("MainWindow", "Nueva pregunta", nullptr));
#endif // QT_NO_TOOLTIP
        newPregButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeButton->setToolTip(QApplication::translate("MainWindow", "Borrar pregunta", nullptr));
#endif // QT_NO_TOOLTIP
        removeButton->setText(QString());
        previsualizarButton->setText(QApplication::translate("MainWindow", "Previsualizar", nullptr));
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("MainWindow", "Cerrar juego", nullptr));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QString());
        msgErrorGuardar->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600; color:#ff0000;\">Error al guardar</span><br/>Debe escribir la pregunta,<br/>sus respuestas y seleccionar<br/>a correcta.</p></body></html>", nullptr));
        msgErrorComunicacion->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600; color:#ff0000;\">Error de comunicacion</span><br/>Debe configurar el puerto<br/>antes de empezar la partida.</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">Pregunta guardada</span></p></body></html>", nullptr));
        gameInProgressBox->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Juego en progreso", nullptr));
        groupBox->setTitle(QString());
        closeButton_2->setText(QApplication::translate("MainWindow", "Cerrar", nullptr));
        replayButton->setText(QApplication::translate("MainWindow", "Volver a jugar", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Puntajes:", nullptr));
        puntajePrimerPuesto->setText(QApplication::translate("MainWindow", "<p>1.- Jugador # : <strong># Puntos</strong></p>", nullptr));
        puntajeSegundoPuesto->setText(QApplication::translate("MainWindow", "<p>2.- Jugador # : <strong># Puntos</strong></p>", nullptr));
        puntajeTercerPuesto->setText(QApplication::translate("MainWindow", "<p>3.- Jugador # : <strong># Puntos</strong></p>", nullptr));
        puntajeCuartoPuesto->setText(QApplication::translate("MainWindow", "<p>4.- Jugador # : <strong># Puntos</strong></p>", nullptr));
        puntajeQuintoPuesto->setText(QApplication::translate("MainWindow", "<p>5.- Jugador # : <strong># Puntos</strong></p>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
