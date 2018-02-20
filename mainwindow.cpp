#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <sstream>
#include <iostream>
#include <string>
preguntas pregArray[7];
int currentPreg=1,maxPreg=1;
#define ERRORCOMUNICACION 2
#define ERRORGUARDAR 1

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
    timerError = new QTimer(this);
    timerGuardada = new QTimer(this);
    QObject::connect(configInstance,SIGNAL(exiting()),this,SLOT(reactivateConfig()));
    QObject::connect(prevInstance,SIGNAL(exiting()),this,SLOT(reactivatePrev()));
    QObject::connect(serial,SIGNAL(beginGame()),this,SLOT(empezarJuego()));
    QObject::connect(timerGetResp,SIGNAL(timeout()),this,SLOT(pedirPuntajes()));
    QObject::connect(timerError,SIGNAL(timeout()),this,SLOT(moveMsg()));
    QObject::connect(timerGuardada,SIGNAL(timeout()),this,SLOT(moveSave()));
    ui->gameState->setCurrentIndex(0);
    ui->mensajeError->setStyleSheet("background-color: lightgray");
    ui->mensajeGuardar->setStyleSheet("background-color: rgb(0, 255, 0)");

    ui->pregButton_2->setVisible(false);
    ui->pregButton_3->setVisible(false);
    ui->pregButton_4->setVisible(false);
    ui->pregButton_5->setVisible(false);
    ui->pregButton_6->setVisible(false);
    ui->pregButton_7->setVisible(false);
    ui->msgErrorGuardar->setVisible(false);
    ui->msgErrorComunicacion->setVisible(false);
    ui->mensajeError->setVisible(false);
    ui->mensajeGuardar->setVisible(false);
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
        showSave();
    }
    else{
        showMessage(ERRORGUARDAR);
    }
}

void MainWindow::habilitarPreguntas(){
    ui->pregButton_1->setVisible(true);
    ui->pregButton_2->setVisible(false);
    ui->pregButton_3->setVisible(false);
    ui->pregButton_4->setVisible(false);
    ui->pregButton_5->setVisible(false);
    ui->pregButton_6->setVisible(false);
    ui->pregButton_7->setVisible(false);
    switch(maxPreg){
    case 7:
        ui->pregButton_7->setVisible(true);
    case 6:
        ui->pregButton_6->setVisible(true);
    case 5:
        ui->pregButton_5->setVisible(true);
    case 4:
        ui->pregButton_4->setVisible(true);
    case 3:
        ui->pregButton_3->setVisible(true);
    case 2:
        ui->pregButton_2->setVisible(true);
    default:
        break;
    }
}

bool MainWindow::validacionGuardar()
{
    if(ui->pregunta->toPlainText()=="")
        return false;
    switch(ui->cantRespuestas->value()) {
    case 4:
        if(ui->respD->text()=="")
            return false;
    case 3:
        if(ui->respC->text()=="")
            return false;
    case 2:
        if(ui->respA->text()==""||ui->respB->text()=="")
            return false;
        if(!ui->checkBoxA->isChecked()&&!ui->checkBoxB->isChecked()&&!ui->checkBoxC->isChecked()&&!ui->checkBoxD->isChecked())
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
    if(maxPreg<7)
        maxPreg++;
    habilitarPreguntas();
}

void MainWindow::on_pregButton_1_clicked()
{
    changePreg(1);
}

void MainWindow::on_pregButton_2_clicked()
{
    changePreg(2);
}

void MainWindow::on_pregButton_3_clicked()
{
    changePreg(3);
}

void MainWindow::on_pregButton_4_clicked()
{
    changePreg(4);
}

void MainWindow::on_pregButton_5_clicked()
{
    changePreg(5);
}

void MainWindow::on_pregButton_6_clicked()
{
    changePreg(6);
}

void MainWindow::on_pregButton_7_clicked()
{
    changePreg(7);
}

void MainWindow::on_cantRespuestas_valueChanged(int value)
{
    ui->checkBoxC->setEnabled(true);
    ui->respC->setEnabled(true);
    ui->checkBoxD->setEnabled(true);
    ui->respD->setEnabled(true);
    if(value<4){
        ui->checkBoxD->setChecked(false);
        ui->checkBoxD->setDisabled(true);
        ui->respD->setText("");
        ui->respD->setDisabled(true);
        if(value<3){
            ui->checkBoxC->setChecked(false);
            ui->checkBoxC->setDisabled(true);
            ui->respC->setDisabled(true);
            ui->respC->setText("");
        }
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
}

void MainWindow::on_removeButton_clicked(){
    int i;
    if(maxPreg>1)
        maxPreg--;
    if(currentPreg>maxPreg)
        changePreg(currentPreg-1);
    for(i=6;i>(maxPreg-1);i--){
        pregArray[i].borrarPregunta();
    }
    habilitarPreguntas();
}

void MainWindow::on_startButton_clicked()
{
    if(pregArray[0].getCantResp()!=0){
        serial->createMsg(pregArray);
        serial->open();
        if(serial->isOpen()){
            ui->gameState->setCurrentIndex(1);
            serial->enviarMsg();
        }
        else{
            showMessage(ERRORCOMUNICACION);
        }
    }
}

void MainWindow::empezarJuego(){
    int amountOfPlayers=0,count;
    QByteArray tmp;
    QString fileContent;
    for(count=0;count<_players_total_;count++)
        serial->response[count].clear();

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
        for(count=0;count<_repeat_message_;count++){
        serial->write(tmp);
        }
        timer->singleShot(gameTimer*1000,this,SLOT(finJuego()));
    }   else
        ui->gameState->setCurrentIndex(0);
}

void MainWindow::finJuego(){
    timerGetResp->start(TIMERECIBIRPUNTOS);
}

void MainWindow::pedirPuntajes(){
    static int id=0;
    QByteArray tmp;
    while(!serial->response[id/_repeat_message_].isEmpty()
          &&(id<(_players_total_*_repeat_message_))
          &&id>=_repeat_message_){
        id++;
    }
    if(id<(_players_total_*_repeat_message_)){
        if(id<_repeat_message_)   {
            tmp = serial->generateMsg(255,'F','F',1);
            serial->write(tmp);
        }
        else    {
            tmp = serial->generateMsg(id/_repeat_message_,'Q','Q',1);
            serial->write(tmp);
        }
        id++;
    }else{
        timerGetResp->stop();
        procesarPuntajes();
        id=0;
    }

}

void MainWindow::procesarPuntajes(){
    int cont,cont2;
    int player[8];
    ui->gameState->setCurrentIndex(2);
    for(cont=0;cont!=_players_total_;cont++){
        player[cont]=0;
    }
    for(cont2=0;cont2<_players_total_;cont2++){
        if(!serial->response[cont2].isEmpty()){
            for(cont=0;cont!=7;cont++){
                if((pregArray[cont].getRespCorrect()+64)==serial->response[cont2][2+cont*3])
                    player[cont2]++;
            }
        }
    }
    scoreBoardWindow(player);
}

void MainWindow::on_replayButton_clicked()
{
    int i;
    ui->gameState->setCurrentIndex(0);

    ui->pregButton_2->setVisible(false);
    ui->pregButton_3->setVisible(false);
    ui->pregButton_4->setVisible(false);
    ui->pregButton_5->setVisible(false);
    ui->pregButton_6->setVisible(false);
    ui->pregButton_7->setVisible(false);
    for(i=0;i<_players_total_;i++){
        serial->response[i].clear();
    }
    for(i=0;i<7;i++){
       pregArray[i].borrarPregunta();
    }
    currentPreg=1;
    maxPreg=1;
    on_pregButton_1_clicked();
}

void MainWindow::scoreBoardWindow(int p[]){
    scoreBoardHelper players[8];
    scoreBoardHelper bestPlayer;
    int cont,index,cont2;

    for(cont=0;cont<_players_total_;cont++){
        players[cont].setPlayer(p[cont],cont+1);
    }
    bestPlayer.setPlayer(-1,0);

    for(cont2=0;cont2<8;cont2++){
        for(cont=0,index=0;cont<8;cont++){
            if(players[cont].getScore()>bestPlayer.getScore()){
                bestPlayer.copy(players[cont]);
                index = cont;
            }
        }
        players[index].setPlayer(-2,0);
        switch(cont2){
        case 0:
            ui->puntajePrimerPuesto->setText("<p>1.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        case 1:
            ui->puntajeSegundoPuesto->setText("<p>2.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        case 2:
            ui->puntajeTercerPuesto->setText("<p>3.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        case 3:
            ui->puntajeCuartoPuesto->setText("<p>4.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        case 4:
            ui->puntajeQuintoPuesto->setText("<p>5.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        case 5:
            ui->puntajeSextoPuesto->setText("<p>6.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        case 6:
            ui->puntajeSeptimoPuesto->setText("<p>7.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        case 7:
            ui->puntajeOctavoPuesto->setText("<p>8.- Jugador "+QString::number(bestPlayer.getPlayerNumber())+" : <strong>"+QString::number(bestPlayer.getScore())+" Puntos</strong></p>");
            break;
        default:
            break;
        }
        bestPlayer.setPlayer(-1,0);
    }

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

void MainWindow::showMessage(int msgSelect){
    switch(msgSelect){
    case ERRORGUARDAR:
        ui->msgErrorGuardar->setVisible(true);
        break;
    case ERRORCOMUNICACION:
        ui->msgErrorComunicacion->setVisible(true);
        break;
    }
    ui->mensajeError->setVisible(true);
    timerError->start(1);
}

void MainWindow::moveMsg(){
    static int cont=0;
    int y=0,tmp;

    if(cont<500){
        y = cont*16-9000;
        y = y/100;
        ui->mensajeError->move(140,y);
        cont++;
    }else if(cont<2500){
        cont++;
    }else if(cont<3000){
        tmp = abs(cont-3000);
        y = tmp*16-9000;
        y = y/100;
        ui->mensajeError->move(140,y);
        cont++;
    }else   {
        cont=0;
        ui->mensajeError->move(140,-90);
        ui->msgErrorComunicacion->setVisible(false);
        ui->msgErrorGuardar->setVisible(false);
        ui->mensajeError->setVisible(false);
        timerError->stop();
    }
}

void MainWindow::showSave(){
    ui->mensajeGuardar->setVisible(true);
    timerGuardada->start(1);
}

void MainWindow::moveSave(){
    static int cont=0;
    int y=0,tmp;

    if(cont<500){
        y = cont*8-4000;
        y = y/100;
        ui->mensajeGuardar->move(170,y);
        cont++;
    }else if(cont<1500){
        cont++;
    }else if(cont<2000){
        tmp = abs(cont-2000);
        y = tmp*8-4000;
        y = y/100;
        ui->mensajeGuardar->move(170,y);
        cont++;
    }else   {
        cont=0;
        ui->mensajeGuardar->move(170,-40);
        ui->mensajeGuardar->setVisible(false);
        timerGuardada->stop();
    }
}



void MainWindow::changePreg(int p)
{
    QString qstr1=QString::fromStdString("Pregunta ")+QString::number(p)+QString::fromStdString(":");
    ui->pregunta->setText(pregArray[p-1].getPregunta());
    ui->respA->setText(pregArray[p-1].getRespuestaA());
    ui->respB->setText(pregArray[p-1].getRespuestaB());
    ui->respC->setText(pregArray[p-1].getRespuestaC());
    ui->respD->setText(pregArray[p-1].getRespuestaD());
    ui->checkBoxA->setAutoExclusive(false);
    ui->checkBoxB->setAutoExclusive(false);
    ui->checkBoxC->setAutoExclusive(false);
    ui->checkBoxD->setAutoExclusive(false);
    if(pregArray[p-1].getCantResp()!=0){
        ui->cantRespuestas->setValue(pregArray[p-1].getCantResp());
        ui->checkBoxA->setChecked(false);
        ui->checkBoxB->setChecked(false);
        ui->checkBoxC->setChecked(false);
        ui->checkBoxD->setChecked(false);
        switch(pregArray[p-1].getRespCorrect()){
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
    }
    ui->checkBoxA->setAutoExclusive(true);
    ui->checkBoxB->setAutoExclusive(true);
    ui->checkBoxC->setAutoExclusive(true);
    ui->checkBoxD->setAutoExclusive(true);
    currentPreg = p;
    ui->labelPregunta->setText(qstr1);
}

















