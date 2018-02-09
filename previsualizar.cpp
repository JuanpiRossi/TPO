#include "previsualizar.h"
#include "ui_previsualizar.h"

previsualizar::previsualizar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::previsualizar)
{
    ui->setupUi(this);
}

previsualizar::~previsualizar()
{
    delete ui;
}

void previsualizar::initForm(preguntas *pregArray){
    ui->preguntaText_1->setText(pregArray[0].getPregunta());
    ui->aText_1->setText(pregArray[0].getRespuestaA());
    ui->bText_1->setText(pregArray[0].getRespuestaB());
    ui->cText_1->setText(pregArray[0].getRespuestaC());
    ui->dText_1->setText(pregArray[0].getRespuestaD());
    ui->aCheck_1->setChecked(false);
    ui->bCheck_1->setChecked(false);
    ui->cCheck_1->setChecked(false);
    ui->dCheck_1->setChecked(false);
    switch(pregArray[0].getRespCorrect()){
    case 1:
        ui->aCheck_1->setChecked(true);
        break;
    case 2:
        ui->bCheck_1->setChecked(true);
        break;
    case 3:
        ui->cCheck_1->setChecked(true);
        break;
    case 4:
        ui->dCheck_1->setChecked(true);
        break;
    default:
        break;
    }
    ui->preguntaText_2->setText(pregArray[1].getPregunta());
    ui->aText_2->setText(pregArray[1].getRespuestaA());
    ui->bText_2->setText(pregArray[1].getRespuestaB());
    ui->cText_2->setText(pregArray[1].getRespuestaC());
    ui->dText_2->setText(pregArray[1].getRespuestaD());
    switch(pregArray[1].getRespCorrect()){
    case 1:
        ui->aCheck_2->setChecked(true);
        ui->bCheck_2->setChecked(false);
        ui->cCheck_2->setChecked(false);
        ui->dCheck_2->setChecked(false);
        break;
    case 2:
        ui->aCheck_2->setChecked(false);
        ui->bCheck_2->setChecked(true);
        ui->cCheck_2->setChecked(false);
        ui->dCheck_2->setChecked(false);
        break;
    case 3:
        ui->aCheck_2->setChecked(false);
        ui->bCheck_2->setChecked(false);
        ui->cCheck_2->setChecked(true);
        ui->dCheck_2->setChecked(false);
        break;
    case 4:
        ui->aCheck_2->setChecked(false);
        ui->bCheck_2->setChecked(false);
        ui->cCheck_2->setChecked(false);
        ui->dCheck_2->setChecked(true);
        break;
    case 0:
        ui->aCheck_2->setChecked(false);
        ui->bCheck_2->setChecked(false);
        ui->cCheck_2->setChecked(false);
        ui->dCheck_2->setChecked(false);
        break;
    }
    ui->preguntaText_3->setText(pregArray[2].getPregunta());
    ui->aText_3->setText(pregArray[2].getRespuestaA());
    ui->bText_3->setText(pregArray[2].getRespuestaB());
    ui->cText_3->setText(pregArray[2].getRespuestaC());
    ui->dText_3->setText(pregArray[2].getRespuestaD());
    switch(pregArray[2].getRespCorrect()){
    case 1:
        ui->aCheck_3->setChecked(true);
        ui->bCheck_3->setChecked(false);
        ui->cCheck_3->setChecked(false);
        ui->dCheck_3->setChecked(false);
        break;
    case 2:
        ui->aCheck_3->setChecked(false);
        ui->bCheck_3->setChecked(true);
        ui->cCheck_3->setChecked(false);
        ui->dCheck_3->setChecked(false);
        break;
    case 3:
        ui->aCheck_3->setChecked(false);
        ui->bCheck_3->setChecked(false);
        ui->cCheck_3->setChecked(true);
        ui->dCheck_3->setChecked(false);
        break;
    case 4:
        ui->aCheck_3->setChecked(false);
        ui->bCheck_3->setChecked(false);
        ui->cCheck_3->setChecked(false);
        ui->dCheck_3->setChecked(true);
        break;
    case 0:
        ui->aCheck_3->setChecked(false);
        ui->bCheck_3->setChecked(false);
        ui->cCheck_3->setChecked(false);
        ui->dCheck_3->setChecked(false);
        break;
    }
    ui->preguntaText_4->setText(pregArray[3].getPregunta());
    ui->aText_4->setText(pregArray[3].getRespuestaA());
    ui->bText_4->setText(pregArray[3].getRespuestaB());
    ui->cText_4->setText(pregArray[3].getRespuestaC());
    ui->dText_4->setText(pregArray[3].getRespuestaD());
    switch(pregArray[3].getRespCorrect()){
    case 1:
        ui->aCheck_4->setChecked(true);
        ui->bCheck_4->setChecked(false);
        ui->cCheck_4->setChecked(false);
        ui->dCheck_4->setChecked(false);
        break;
    case 2:
        ui->aCheck_4->setChecked(false);
        ui->bCheck_4->setChecked(true);
        ui->cCheck_4->setChecked(false);
        ui->dCheck_4->setChecked(false);
        break;
    case 3:
        ui->aCheck_4->setChecked(false);
        ui->bCheck_4->setChecked(false);
        ui->cCheck_4->setChecked(true);
        ui->dCheck_4->setChecked(false);
        break;
    case 4:
        ui->aCheck_4->setChecked(false);
        ui->bCheck_4->setChecked(false);
        ui->cCheck_4->setChecked(false);
        ui->dCheck_4->setChecked(true);
        break;
    case 0:
        ui->aCheck_4->setChecked(false);
        ui->bCheck_4->setChecked(false);
        ui->cCheck_4->setChecked(false);
        ui->dCheck_4->setChecked(false);
        break;
    }
    ui->preguntaText_5->setText(pregArray[4].getPregunta());
    ui->aText_5->setText(pregArray[4].getRespuestaA());
    ui->bText_5->setText(pregArray[4].getRespuestaB());
    ui->cText_5->setText(pregArray[4].getRespuestaC());
    ui->dText_5->setText(pregArray[4].getRespuestaD());
    switch(pregArray[4].getRespCorrect()){
    case 1:
        ui->aCheck_5->setChecked(true);
        ui->bCheck_5->setChecked(false);
        ui->cCheck_5->setChecked(false);
        ui->dCheck_5->setChecked(false);
        break;
    case 2:
        ui->aCheck_5->setChecked(false);
        ui->bCheck_5->setChecked(true);
        ui->cCheck_5->setChecked(false);
        ui->dCheck_5->setChecked(false);
        break;
    case 3:
        ui->aCheck_5->setChecked(false);
        ui->bCheck_5->setChecked(false);
        ui->cCheck_5->setChecked(true);
        ui->dCheck_5->setChecked(false);
        break;
    case 4:
        ui->aCheck_5->setChecked(false);
        ui->bCheck_5->setChecked(false);
        ui->cCheck_5->setChecked(false);
        ui->dCheck_5->setChecked(true);
        break;
    case 0:
        ui->aCheck_5->setChecked(false);
        ui->bCheck_5->setChecked(false);
        ui->cCheck_5->setChecked(false);
        ui->dCheck_5->setChecked(false);
        break;
    }
    ui->preguntaText_6->setText(pregArray[5].getPregunta());
    ui->aText_6->setText(pregArray[5].getRespuestaA());
    ui->bText_6->setText(pregArray[5].getRespuestaB());
    ui->cText_6->setText(pregArray[5].getRespuestaC());
    ui->dText_6->setText(pregArray[5].getRespuestaD());
    switch(pregArray[5].getRespCorrect()){
    case 1:
        ui->aCheck_6->setChecked(true);
        ui->bCheck_6->setChecked(false);
        ui->cCheck_6->setChecked(false);
        ui->dCheck_6->setChecked(false);
        break;
    case 2:
        ui->aCheck_6->setChecked(false);
        ui->bCheck_6->setChecked(true);
        ui->cCheck_6->setChecked(false);
        ui->dCheck_6->setChecked(false);
        break;
    case 3:
        ui->aCheck_6->setChecked(false);
        ui->bCheck_6->setChecked(false);
        ui->cCheck_6->setChecked(true);
        ui->dCheck_6->setChecked(false);
        break;
    case 4:
        ui->aCheck_6->setChecked(false);
        ui->bCheck_6->setChecked(false);
        ui->cCheck_6->setChecked(false);
        ui->dCheck_6->setChecked(true);
        break;
    case 0:
        ui->aCheck_6->setChecked(false);
        ui->bCheck_6->setChecked(false);
        ui->cCheck_6->setChecked(false);
        ui->dCheck_6->setChecked(false);
        break;
    }
    ui->preguntaText_7->setText(pregArray[6].getPregunta());
    ui->aText_7->setText(pregArray[6].getRespuestaA());
    ui->bText_7->setText(pregArray[6].getRespuestaB());
    ui->cText_7->setText(pregArray[6].getRespuestaC());
    ui->dText_7->setText(pregArray[6].getRespuestaD());
    switch(pregArray[6].getRespCorrect()){
    case 1:
        ui->aCheck_7->setChecked(true);
        ui->bCheck_7->setChecked(false);
        ui->cCheck_7->setChecked(false);
        ui->dCheck_7->setChecked(false);
        break;
    case 2:
        ui->aCheck_7->setChecked(false);
        ui->bCheck_7->setChecked(true);
        ui->cCheck_7->setChecked(false);
        ui->dCheck_7->setChecked(false);
        break;
    case 3:
        ui->aCheck_7->setChecked(false);
        ui->bCheck_7->setChecked(false);
        ui->cCheck_7->setChecked(true);
        ui->dCheck_7->setChecked(false);
        break;
    case 4:
        ui->aCheck_7->setChecked(false);
        ui->bCheck_7->setChecked(false);
        ui->cCheck_7->setChecked(false);
        ui->dCheck_7->setChecked(true);
        break;
    case 0:
        ui->aCheck_7->setChecked(false);
        ui->bCheck_7->setChecked(false);
        ui->cCheck_7->setChecked(false);
        ui->dCheck_7->setChecked(false);
        break;
    }
}

void previsualizar::closeEvent(QCloseEvent *event) {
    emit(exiting());
}

void previsualizar::on_closeButton_clicked()
{
    this->close();
}
