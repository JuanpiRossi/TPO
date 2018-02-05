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
    QPushButton *saveButton;
    QPushButton *removeButton;
    QPushButton *newPregButton;
    QPushButton *previsualizarButton;
    QLabel *errorLabel;
    QPushButton *pregButton_7;
    QPushButton *configButton;
    QPushButton *pregButton_4;
    QPushButton *pregButton_6;
    QPushButton *pregButton_3;
    QPushButton *pregButton_1;
    QPushButton *pregButton_2;
    QPushButton *closeButton;
    QPushButton *pregButton_5;
    QPushButton *startButton;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(511, 291);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gameState = new QStackedWidget(centralWidget);
        gameState->setObjectName(QStringLiteral("gameState"));
        gameState->setGeometry(QRect(0, 0, 511, 321));
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
        labelCantResp->setGeometry(QRect(420, 20, 61, 41));
        cantRespuestas = new QSpinBox(principalBox);
        cantRespuestas->setObjectName(QStringLiteral("cantRespuestas"));
        cantRespuestas->setGeometry(QRect(430, 60, 42, 22));
        cantRespuestas->setMinimum(2);
        cantRespuestas->setMaximum(4);
        cantRespuestas->setValue(4);
        saveButton = new QPushButton(principalBox);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(400, 210, 75, 23));
        removeButton = new QPushButton(principalBox);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(20, 210, 75, 23));
        newPregButton = new QPushButton(principalBox);
        newPregButton->setObjectName(QStringLiteral("newPregButton"));
        newPregButton->setEnabled(true);
        newPregButton->setGeometry(QRect(294, 210, 91, 23));
        previsualizarButton = new QPushButton(principalBox);
        previsualizarButton->setObjectName(QStringLiteral("previsualizarButton"));
        previsualizarButton->setGeometry(QRect(210, 210, 75, 23));
        errorLabel = new QLabel(principalBox);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(110, 200, 120, 40));
        pregButton_7 = new QPushButton(principalBox);
        pregButton_7->setObjectName(QStringLiteral("pregButton_7"));
        pregButton_7->setGeometry(QRect(200, 240, 31, 23));
        configButton = new QPushButton(principalBox);
        configButton->setObjectName(QStringLiteral("configButton"));
        configButton->setGeometry(QRect(320, 240, 75, 23));
        pregButton_4 = new QPushButton(principalBox);
        pregButton_4->setObjectName(QStringLiteral("pregButton_4"));
        pregButton_4->setGeometry(QRect(110, 240, 31, 23));
        pregButton_6 = new QPushButton(principalBox);
        pregButton_6->setObjectName(QStringLiteral("pregButton_6"));
        pregButton_6->setGeometry(QRect(170, 240, 31, 23));
        pregButton_3 = new QPushButton(principalBox);
        pregButton_3->setObjectName(QStringLiteral("pregButton_3"));
        pregButton_3->setGeometry(QRect(80, 240, 31, 23));
        pregButton_1 = new QPushButton(principalBox);
        pregButton_1->setObjectName(QStringLiteral("pregButton_1"));
        pregButton_1->setGeometry(QRect(20, 240, 31, 23));
        pregButton_2 = new QPushButton(principalBox);
        pregButton_2->setObjectName(QStringLiteral("pregButton_2"));
        pregButton_2->setGeometry(QRect(50, 240, 31, 23));
        closeButton = new QPushButton(principalBox);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(240, 240, 75, 23));
        pregButton_5 = new QPushButton(principalBox);
        pregButton_5->setObjectName(QStringLiteral("pregButton_5"));
        pregButton_5->setGeometry(QRect(140, 240, 31, 23));
        startButton = new QPushButton(principalBox);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(400, 240, 75, 23));
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
        puntajePrimerPuesto->setGeometry(QRect(30, 60, 351, 21));
        puntajeSegundoPuesto = new QLabel(groupBox);
        puntajeSegundoPuesto->setObjectName(QStringLiteral("puntajeSegundoPuesto"));
        puntajeSegundoPuesto->setGeometry(QRect(30, 90, 351, 21));
        puntajeTercerPuesto = new QLabel(groupBox);
        puntajeTercerPuesto->setObjectName(QStringLiteral("puntajeTercerPuesto"));
        puntajeTercerPuesto->setGeometry(QRect(30, 120, 351, 21));
        puntajeCuartoPuesto = new QLabel(groupBox);
        puntajeCuartoPuesto->setObjectName(QStringLiteral("puntajeCuartoPuesto"));
        puntajeCuartoPuesto->setGeometry(QRect(30, 150, 351, 21));
        puntajeQuintoPuesto = new QLabel(groupBox);
        puntajeQuintoPuesto->setObjectName(QStringLiteral("puntajeQuintoPuesto"));
        puntajeQuintoPuesto->setGeometry(QRect(30, 180, 351, 21));
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
        saveButton->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
        removeButton->setText(QApplication::translate("MainWindow", "Borrar", nullptr));
        newPregButton->setText(QApplication::translate("MainWindow", "Nueva pregunta", nullptr));
        previsualizarButton->setText(QApplication::translate("MainWindow", "Previsualizar", nullptr));
        errorLabel->setText(QApplication::translate("MainWindow", "Configurar puerto", nullptr));
        pregButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        configButton->setText(QApplication::translate("MainWindow", "Configuracion", nullptr));
        pregButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pregButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        pregButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pregButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pregButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        closeButton->setText(QApplication::translate("MainWindow", "Cerrar", nullptr));
        pregButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Empezar", nullptr));
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
