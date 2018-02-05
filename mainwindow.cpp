#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
preguntas pregArray[7];
int currentPreg=1,maxPreg=1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configInstance = new config();
    prevInstance = new previsualizar();
    serial = new serialPort();
    timer = new QTimer(this);
    timerGetResp = new QTimer(this);
    QObject::connect(configInstance,SIGNAL(exiting()),this,SLOT(reactivateConfig()));
    QObject::connect(prevInstance,SIGNAL(exiting()),this,SLOT(reactivatePrev()));
    QObject::connect(serial,SIGNAL(beginGame()),this,SLOT(empezarJuego()));
    QObject::connect(timerGetResp,SIGNAL(timeout()),this,SLOT(pedirPuntajes()));
    ui->gameState->setCurrentIndex(0);

    ui->pregButton_2->setVisible(false);
    ui->pregButton_3->setVisible(false);
    ui->pregButton_4->setVisible(false);
    ui->pregButton_5->setVisible(false);
    ui->pregButton_6->setVisible(false);
    ui->pregButton_7->setVisible(false);
    ui->errorLabel->setVisible(false);
}

MainWindow::~MainWindow()
{
    serial->close();
    delete timer;
    delete configInstance;
    delete prevInstance;
    delete serial;
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::on_closeButton_2_clicked()
{
    this->close();
}

void MainWindow::on_configButton_clicked()
{
    configInstance->show();
    ui->configButton->setDisabled(true);
}

void MainWindow::on_previsualizarButton_clicked()
{
    prevInstance->show();
    ui->previsualizarButton->setDisabled(true);
    prevInstance->initForm(pregArray);
}

void MainWindow::reactivateConfig(){
    ui->configButton->setEnabled(true);
}

void MainWindow::reactivatePrev(){
    ui->previsualizarButton->setEnabled(true);
}

void MainWindow::on_saveButton_clicked()
{
    if(validacionGuardar()){
        int respCorrecta=0;
        if(ui->checkBoxA->isChecked())
            respCorrecta=1;
        else if(ui->checkBoxB->isChecked())
            respCorrecta=2;
        else if(ui->checkBoxC->isChecked())
            respCorrecta=3;
        else if(ui->checkBoxD->isChecked())
            respCorrecta=4;
        pregArray[currentPreg-1].guardarPregunta(ui->pregunta->toPlainText().toUtf8(),
                                            ui->respA->text().toUtf8(),
                                            ui->respB->text().toUtf8(),
                                            ui->respC->text().toUtf8(),
                                            ui->respD->text().toUtf8(),
                                            ui->cantRespuestas->value(),
                                            respCorrecta);
    }
}

void MainWindow::habilitarPreguntas(){
    switch(maxPreg){
    case 1:
        ui->pregButton_1->setVisible(true);
        ui->pregButton_2->setVisible(false);
        ui->pregButton_3->setVisible(false);
        ui->pregButton_4->setVisible(false);
        ui->pregButton_5->setVisible(false);
        ui->pregButton_6->setVisible(false);
        ui->pregButton_7->setVisible(false);
        break;
    case 2:
        ui->pregButton_1->setVisible(true);
        ui->pregButton_2->setVisible(true);
        ui->pregButton_3->setVisible(false);
        ui->pregButton_4->setVisible(false);
        ui->pregButton_5->setVisible(false);
        ui->pregButton_6->setVisible(false);
        ui->pregButton_7->setVisible(false);
        break;
    case 3:
        ui->pregButton_1->setVisible(true);
        ui->pregButton_2->setVisible(true);
        ui->pregButton_3->setVisible(true);
        ui->pregButton_4->setVisible(false);
        ui->pregButton_5->setVisible(false);
        ui->pregButton_6->setVisible(false);
        ui->pregButton_7->setVisible(false);
        break;
    case 4:
        ui->pregButton_1->setVisible(true);
        ui->pregButton_2->setVisible(true);
        ui->pregButton_3->setVisible(true);
        ui->pregButton_4->setVisible(true);
        ui->pregButton_5->setVisible(false);
        ui->pregButton_6->setVisible(false);
        ui->pregButton_7->setVisible(false);
        break;
    case 5:
        ui->pregButton_1->setVisible(true);
        ui->pregButton_2->setVisible(true);
        ui->pregButton_3->setVisible(true);
        ui->pregButton_4->setVisible(true);
        ui->pregButton_5->setVisible(true);
        ui->pregButton_6->setVisible(false);
        ui->pregButton_7->setVisible(false);
        break;
    case 6:
        ui->pregButton_1->setVisible(true);
        ui->pregButton_2->setVisible(true);
        ui->pregButton_3->setVisible(true);
        ui->pregButton_4->setVisible(true);
        ui->pregButton_5->setVisible(true);
        ui->pregButton_6->setVisible(true);
        ui->pregButton_7->setVisible(false);
        break;
    case 7:
        ui->pregButton_1->setVisible(true);
        ui->pregButton_2->setVisible(true);
        ui->pregButton_3->setVisible(true);
        ui->pregButton_4->setVisible(true);
        ui->pregButton_5->setVisible(true);
        ui->pregButton_6->setVisible(true);
        ui->pregButton_7->setVisible(true);
        break;
    }
}

bool MainWindow::validacionGuardar()
{
    if(ui->pregunta->toPlainText()=="")
        return false;
    switch(ui->cantRespuestas->value()) {
    case 4:
        if(ui->respA->text()==""||ui->respB->text()==""||ui->respC->text()==""||ui->respD->text()=="")
            return false;
        if(!ui->checkBoxA->isChecked()&&!ui->checkBoxB->isChecked()&&!ui->checkBoxC->isChecked()&&!ui->checkBoxD->isChecked())
            return false;
        break;
    case 3:
        if(ui->respA->text()==""||ui->respB->text()==""||ui->respC->text()=="")
            return false;
        if(!ui->checkBoxA->isChecked()&&!ui->checkBoxB->isChecked()&&!ui->checkBoxC->isChecked())
            return false;
        break;
    case 2:
        if(ui->respA->text()==""||ui->respB->text()=="")
            return false;
        if(!ui->checkBoxA->isChecked()&&!ui->checkBoxB->isChecked())
            return false;
        break;
    default:
        return false;
        break;
    }
    return true;
}

void MainWindow::on_newPregButton_clicked()
{
    if(maxPreg!=7)
        maxPreg++;
    habilitarPreguntas();
}

void MainWindow::on_pregButton_1_clicked()
{
    ui->pregunta->setText(pregArray[0].getPregunta());
    ui->respA->setText(pregArray[0].getRespuestaA());
    ui->respB->setText(pregArray[0].getRespuestaB());
    ui->respC->setText(pregArray[0].getRespuestaC());
    ui->respD->setText(pregArray[0].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[0].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[0].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[0].getRespCorrect()){
        case 1:
            ui->checkBoxA->setChecked(true);
            break;
        case 2:
            ui->checkBoxB->setChecked(true);
            break;
        case 3:
            ui->checkBoxC->setChecked(true);
            break;
        case 4:
            ui->checkBoxD->setChecked(true);
            break;
        }
    }
    else{
        ui->cantRespuestas->setValue(4);
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = 1;
    ui->labelPregunta->setText("Pregunta 1:");
}

void MainWindow::on_pregButton_2_clicked()
{
    ui->pregunta->setText(pregArray[1].getPregunta());
    ui->respA->setText(pregArray[1].getRespuestaA());
    ui->respB->setText(pregArray[1].getRespuestaB());
    ui->respC->setText(pregArray[1].getRespuestaC());
    ui->respD->setText(pregArray[1].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[1].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[1].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[1].getRespCorrect()){
        case 1:
            ui->checkBoxA->setChecked(true);
            break;
        case 2:
            ui->checkBoxB->setChecked(true);
            break;
        case 3:
            ui->checkBoxC->setChecked(true);
            break;
        case 4:
            ui->checkBoxD->setChecked(true);
            break;
        }
    }
    else{
        ui->cantRespuestas->setValue(4);
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = 2;
    ui->labelPregunta->setText("Pregunta 2:");
}

void MainWindow::on_pregButton_3_clicked()
{
    ui->pregunta->setText(pregArray[2].getPregunta());
    ui->respA->setText(pregArray[2].getRespuestaA());
    ui->respB->setText(pregArray[2].getRespuestaB());
    ui->respC->setText(pregArray[2].getRespuestaC());
    ui->respD->setText(pregArray[2].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[2].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[2].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[2].getRespCorrect()){
        case 1:
            ui->checkBoxA->setChecked(true);
            break;
        case 2:
            ui->checkBoxB->setChecked(true);
            break;
        case 3:
            ui->checkBoxC->setChecked(true);
            break;
        case 4:
            ui->checkBoxD->setChecked(true);
            break;
        }
    }
    else{
        ui->cantRespuestas->setValue(4);
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = 3;
    ui->labelPregunta->setText("Pregunta 3:");
}

void MainWindow::on_pregButton_4_clicked()
{
    ui->pregunta->setText(pregArray[3].getPregunta());
    ui->respA->setText(pregArray[3].getRespuestaA());
    ui->respB->setText(pregArray[3].getRespuestaB());
    ui->respC->setText(pregArray[3].getRespuestaC());
    ui->respD->setText(pregArray[3].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[3].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[3].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[3].getRespCorrect()){
        case 1:
            ui->checkBoxA->setChecked(true);
            break;
        case 2:
            ui->checkBoxB->setChecked(true);
            break;
        case 3:
            ui->checkBoxC->setChecked(true);
            break;
        case 4:
            ui->checkBoxD->setChecked(true);
            break;
        }
    }
    else{
        ui->cantRespuestas->setValue(4);
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = 4;
    ui->labelPregunta->setText("Pregunta 4:");
}

void MainWindow::on_pregButton_5_clicked()
{
    ui->pregunta->setText(pregArray[4].getPregunta());
    ui->respA->setText(pregArray[4].getRespuestaA());
    ui->respB->setText(pregArray[4].getRespuestaB());
    ui->respC->setText(pregArray[4].getRespuestaC());
    ui->respD->setText(pregArray[4].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[4].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[4].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[4].getRespCorrect()){
        case 1:
            ui->checkBoxA->setChecked(true);
            break;
        case 2:
            ui->checkBoxB->setChecked(true);
            break;
        case 3:
            ui->checkBoxC->setChecked(true);
            break;
        case 4:
            ui->checkBoxD->setChecked(true);
            break;
        }
    }
    else{
        ui->cantRespuestas->setValue(4);
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = 5;
    ui->labelPregunta->setText("Pregunta 5:");
}

void MainWindow::on_pregButton_6_clicked()
{
    ui->pregunta->setText(pregArray[5].getPregunta());
    ui->respA->setText(pregArray[5].getRespuestaA());
    ui->respB->setText(pregArray[5].getRespuestaB());
    ui->respC->setText(pregArray[5].getRespuestaC());
    ui->respD->setText(pregArray[5].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[5].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[5].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[5].getRespCorrect()){
        case 1:
            ui->checkBoxA->setChecked(true);
            break;
        case 2:
            ui->checkBoxB->setChecked(true);
            break;
        case 3:
            ui->checkBoxC->setChecked(true);
            break;
        case 4:
            ui->checkBoxD->setChecked(true);
            break;
        }
    }
    else{
        ui->cantRespuestas->setValue(4);
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = 6;
    ui->labelPregunta->setText("Pregunta 6:");
}

void MainWindow::on_pregButton_7_clicked()
{
    ui->pregunta->setText(pregArray[6].getPregunta());
    ui->respA->setText(pregArray[6].getRespuestaA());
    ui->respB->setText(pregArray[6].getRespuestaB());
    ui->respC->setText(pregArray[6].getRespuestaC());
    ui->respD->setText(pregArray[6].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[6].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[6].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[6].getRespCorrect()){
        case 1:
            ui->checkBoxA->setChecked(true);
            break;
        case 2:
            ui->checkBoxB->setChecked(true);
            break;
        case 3:
            ui->checkBoxC->setChecked(true);
            break;
        case 4:
            ui->checkBoxD->setChecked(true);
            break;
        }
    }
    else{
        ui->cantRespuestas->setValue(4);
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = 7;
    ui->labelPregunta->setText("Pregunta 7:");
}

void MainWindow::on_cantRespuestas_valueChanged(int value)
{
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    switch(value){
    case 2:
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        ui->checkBoxC->setDisabled(true);
        ui->checkBoxD->setDisabled(true);
        ui->respC->setDisabled(true);
        ui->respD->setDisabled(true);
        break;
    case 3:
        ui->checkBoxD->setChecked(false);
        ui->checkBoxC->setEnabled(true);
        ui->checkBoxD->setDisabled(true);
        ui->respC->setEnabled(true);
        ui->respD->setDisabled(true);
        break;
    case 4:
        ui->checkBoxC->setEnabled(true);
        ui->checkBoxD->setEnabled(true);
        ui->respC->setEnabled(true);
        ui->respD->setEnabled(true);
        break;
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
}

void MainWindow::on_removeButton_clicked(){
    int cont = 0;

    for(cont = currentPreg;cont!=7;cont++){
        pregArray[cont-1].copy(pregArray[cont]);
    }
    pregArray[6].guardarPregunta("","","","","",0,0);
    maxPreg--;
    habilitarPreguntas();
    on_pregButton_1_clicked();
}

void MainWindow::on_startButton_clicked()
{
    if(pregArray[0].getCantResp()!=0){
        serial->createMsg(pregArray);
        serial->open();
        if(serial->isOpen()){
            ui->gameState->setCurrentIndex(1);
            ui->errorLabel->setVisible(false);
            serial->enviarMsg();
        }   else
            ui->errorLabel->setVisible(true);
    }
}

void MainWindow::empezarJuego(){
    int amountOfPlayers=0;
    QByteArray tmp;
    QString fileContent;
    serial->response[0].clear();
    serial->response[1].clear();
    serial->response[2].clear();
    serial->response[3].clear();
    serial->response[4].clear();

    for(const int &player : serial->idRetrys){
        if(player==-1)
            amountOfPlayers++;
    }
    if(amountOfPlayers>=1){
        fileContent = file.readFile();
        QRegExp rx("playTime:([0-9]*)\n"
                   "portName:([^\n]*)\n"
                   "baudios:([^\n]*)\n"
                   "paridad:([^\n]*)\n"
                   "bitsDatos:([^\n]*)\n"
                   "bitStop:([^\n]*)");
        rx.indexIn(fileContent);
        gameTimer = rx.capturedTexts()[1].toInt();
        tmp = serial->generateMsg(255,'E','E',gameTimer);
        serial->write(tmp);
        timer->singleShot(gameTimer*1000,this,SLOT(finJuego()));
    }   else
        ui->gameState->setCurrentIndex(0);
}

void MainWindow::finJuego(){
    timerGetResp->start(TIMERESPERARESPUESTA);
}

void MainWindow::pedirPuntajes(){
    static int id=0;
    QByteArray tmp;

    while(id!=6){
        if(id==0)   {
            tmp = serial->generateMsg(255,'F','F',1);
            serial->write(tmp);
        }
        else    {
            tmp = serial->generateMsg(id,'Q','Q',1);
            serial->write(tmp);
        }
        id++;
    }
    if(id==6){
        timerGetResp->stop();
        procesarPuntajes();
        id=0;
    }
}

void MainWindow::procesarPuntajes(){
    int cont,player1,player2,player3,player4,player5;
    ui->gameState->setCurrentIndex(2);

    player1 = 0;
    player2 = 0;
    player3 = 0;
    player4 = 0;
    player5 = 0;
    if(!serial->response[0].isEmpty()){
        for(cont=0;cont!=7;cont++){
            if((pregArray[cont].getRespCorrect()+64)==serial->response[0][2+cont*3])
                player1++;
        }
    }
    if(!serial->response[1].isEmpty()){
        for(cont=0;cont!=7;cont++){
            if((pregArray[cont].getRespCorrect()+64)==serial->response[1][2+cont*3])
                player2++;
        }
    }
    if(!serial->response[2].isEmpty()){
        for(cont=0;cont!=7;cont++){
            if((pregArray[cont].getRespCorrect()+64)==serial->response[2][2+cont*3])
                player3++;
        }
    }
    if(!serial->response[3].isEmpty()){
        for(cont=0;cont!=7;cont++){
            if((pregArray[cont].getRespCorrect()+64)==serial->response[3][2+cont*3])
                player4++;
        }
    }
    if(!serial->response[4].isEmpty()){
        for(cont=0;cont!=7;cont++){
            if((pregArray[cont].getRespCorrect()+64)==serial->response[4][2+cont*3])
                player5++;
        }
    }

    scoreBoardWindow(player1,player2,player3,player4,player5);
}

void MainWindow::on_replayButton_clicked()
{
    ui->gameState->setCurrentIndex(0);

    ui->pregButton_2->setVisible(false);
    ui->pregButton_3->setVisible(false);
    ui->pregButton_4->setVisible(false);
    ui->pregButton_5->setVisible(false);
    ui->pregButton_6->setVisible(false);
    ui->pregButton_7->setVisible(false);
    ui->errorLabel->setVisible(false);
    serial->response[0].clear();
    serial->response[1].clear();
    serial->response[2].clear();
    serial->response[3].clear();
    serial->response[4].clear();
    pregArray[0].borrarPregunta();
    pregArray[1].borrarPregunta();
    pregArray[2].borrarPregunta();
    pregArray[3].borrarPregunta();
    pregArray[4].borrarPregunta();
    pregArray[5].borrarPregunta();
    pregArray[6].borrarPregunta();
    on_pregButton_1_clicked();
}

void MainWindow::scoreBoardWindow(int p1, int p2, int p3, int p4, int p5){
    scoreBoardHelper players[5];
    scoreBoardHelper bestPlayer;
    int cont,index;

    players[0].setPlayer(p1,1);
    players[1].setPlayer(p2,2);
    players[2].setPlayer(p3,3);
    players[3].setPlayer(p4,4);
    players[4].setPlayer(p5,5);
    bestPlayer.setPlayer(-1,0);

    for(cont=0,index=0;cont!=5;cont++){
        if(players[cont].getScore()>bestPlayer.getScore()){
            bestPlayer.copy(players[cont]);
            index = cont;
        }
    }
    players[index].setPlayer(-2,0);
    ui->puntajePrimerPuesto->setText("<p>1.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
    bestPlayer.setPlayer(-1,0);

    for(cont=0,index=0;cont!=5;cont++){
        if(players[cont].getScore()>bestPlayer.getScore()){
            bestPlayer.copy(players[cont]);
            index = cont;
        }
    }
    players[index].setPlayer(-2,0);
    ui->puntajeSegundoPuesto->setText("<p>2.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
    bestPlayer.setPlayer(-1,0);

    for(cont=0,index=0;cont!=5;cont++){
        if(players[cont].getScore()>bestPlayer.getScore()){
            bestPlayer.copy(players[cont]);
            index = cont;
        }
    }
    players[index].setPlayer(-2,0);
    ui->puntajeTercerPuesto->setText("<p>3.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
    bestPlayer.setPlayer(-1,0);

    for(cont=0,index=0;cont!=5;cont++){
        if(players[cont].getScore()>bestPlayer.getScore()){
            bestPlayer.copy(players[cont]);
            index = cont;
        }
    }
    players[index].setPlayer(-2,0);
    ui->puntajeCuartoPuesto->setText("<p>4.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
    bestPlayer.setPlayer(-1,0);

    for(cont=0,index=0;cont!=5;cont++){
        if(players[cont].getScore()>bestPlayer.getScore()){
            bestPlayer.copy(players[cont]);
            index = cont;
        }
    }
    ui->puntajeQuintoPuesto->setText("<p>5.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
}

void MainWindow::on_pregunta_textChanged()
{
    if(ui->pregunta->toPlainText().length()>40){
        QTextCursor cursor(ui->pregunta->textCursor());
        ui->pregunta->setText(ui->pregunta->toPlainText().mid(0,40));
        cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        ui->pregunta->setTextCursor(cursor);
    }
}























