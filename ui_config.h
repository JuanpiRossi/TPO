/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_config
{
public:
    QWidget *centralwidget;
    QPushButton *closeButton;
    QGroupBox *groupBox_2;
    QSpinBox *playTime;
    QLabel *label_7;
    QPushButton *saveButton;
    QGroupBox *groupBox;
    QComboBox *stopCombo;
    QLabel *label_6;
    QComboBox *dataCombo;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label;
    QComboBox *portCombo;
    QComboBox *baudsCombo;
    QLabel *label_5;
    QComboBox *parityCombo;

    void setupUi(QMainWindow *config)
    {
        if (config->objectName().isEmpty())
            config->setObjectName(QStringLiteral("config"));
        config->resize(581, 240);
        centralwidget = new QWidget(config);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(30, 200, 75, 23));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 291, 171));
        playTime = new QSpinBox(groupBox_2);
        playTime->setObjectName(QStringLiteral("playTime"));
        playTime->setGeometry(QRect(160, 30, 121, 22));
        playTime->setMaximum(120);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 30, 191, 16));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(210, 200, 75, 23));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(320, 10, 251, 221));
        stopCombo = new QComboBox(groupBox);
        stopCombo->addItem(QString());
        stopCombo->addItem(QString());
        stopCombo->setObjectName(QStringLiteral("stopCombo"));
        stopCombo->setGeometry(QRect(150, 150, 81, 22));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 150, 91, 16));
        dataCombo = new QComboBox(groupBox);
        dataCombo->addItem(QString());
        dataCombo->addItem(QString());
        dataCombo->setObjectName(QStringLiteral("dataCombo"));
        dataCombo->setGeometry(QRect(150, 120, 81, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 91, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 90, 91, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 91, 16));
        portCombo = new QComboBox(groupBox);
        portCombo->setObjectName(QStringLiteral("portCombo"));
        portCombo->setGeometry(QRect(150, 30, 81, 22));
        baudsCombo = new QComboBox(groupBox);
        baudsCombo->addItem(QString());
        baudsCombo->addItem(QString());
        baudsCombo->addItem(QString());
        baudsCombo->addItem(QString());
        baudsCombo->addItem(QString());
        baudsCombo->addItem(QString());
        baudsCombo->addItem(QString());
        baudsCombo->addItem(QString());
        baudsCombo->setObjectName(QStringLiteral("baudsCombo"));
        baudsCombo->setGeometry(QRect(150, 60, 81, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 120, 91, 16));
        parityCombo = new QComboBox(groupBox);
        parityCombo->addItem(QString());
        parityCombo->addItem(QString());
        parityCombo->addItem(QString());
        parityCombo->setObjectName(QStringLiteral("parityCombo"));
        parityCombo->setGeometry(QRect(150, 90, 81, 22));
        config->setCentralWidget(centralwidget);

        retranslateUi(config);

        stopCombo->setCurrentIndex(1);
        dataCombo->setCurrentIndex(0);
        baudsCombo->setCurrentIndex(3);
        parityCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(config);
    } // setupUi

    void retranslateUi(QMainWindow *config)
    {
        config->setWindowTitle(QApplication::translate("config", "MainWindow", nullptr));
        closeButton->setText(QApplication::translate("config", "Cerrar", nullptr));
        groupBox_2->setTitle(QApplication::translate("config", "Configuracion del juego", nullptr));
        label_7->setText(QApplication::translate("config", "Tiempo de partida (segundos): ", nullptr));
        saveButton->setText(QApplication::translate("config", "Guardar", nullptr));
        groupBox->setTitle(QApplication::translate("config", "Configuracion de puerto serie", nullptr));
        stopCombo->setItemText(0, QApplication::translate("config", "1", nullptr));
        stopCombo->setItemText(1, QApplication::translate("config", "2", nullptr));

        stopCombo->setCurrentText(QApplication::translate("config", "2", nullptr));
        label_6->setText(QApplication::translate("config", "Bits de stop: ", nullptr));
        dataCombo->setItemText(0, QApplication::translate("config", "7", nullptr));
        dataCombo->setItemText(1, QApplication::translate("config", "8", nullptr));

        label_2->setText(QApplication::translate("config", "Baudios:", nullptr));
        label_4->setText(QApplication::translate("config", "Paridad:", nullptr));
        label->setText(QApplication::translate("config", "Puerto:", nullptr));
        baudsCombo->setItemText(0, QApplication::translate("config", "1200", nullptr));
        baudsCombo->setItemText(1, QApplication::translate("config", "2400", nullptr));
        baudsCombo->setItemText(2, QApplication::translate("config", "4800", nullptr));
        baudsCombo->setItemText(3, QApplication::translate("config", "9600", nullptr));
        baudsCombo->setItemText(4, QApplication::translate("config", "19200", nullptr));
        baudsCombo->setItemText(5, QApplication::translate("config", "38400", nullptr));
        baudsCombo->setItemText(6, QApplication::translate("config", "57600", nullptr));
        baudsCombo->setItemText(7, QApplication::translate("config", "115200", nullptr));

        label_5->setText(QApplication::translate("config", "Bits de datos: ", nullptr));
        parityCombo->setItemText(0, QApplication::translate("config", "Par", nullptr));
        parityCombo->setItemText(1, QApplication::translate("config", "Impar", nullptr));
        parityCombo->setItemText(2, QApplication::translate("config", "Sin paridad", nullptr));

    } // retranslateUi

};

namespace Ui {
    class config: public Ui_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
