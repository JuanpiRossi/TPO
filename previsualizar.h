#ifndef PREVISUALIZAR_H
#define PREVISUALIZAR_H

#include <QMainWindow>
#include "preguntas.h"

namespace Ui {
class previsualizar;
}

class previsualizar : public QMainWindow
{
    Q_OBJECT

public:
    explicit previsualizar(QWidget *parent = 0);
    void initForm(preguntas *pregArrayReceive);
    ~previsualizar();
signals:
    void exiting();
protected:
     void closeEvent(QCloseEvent *event);

private slots:
     void on_closeButton_clicked();

private:
    Ui::previsualizar *ui;
};

#endif // PREVISUALIZAR_H
