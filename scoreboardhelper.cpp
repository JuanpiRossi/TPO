#include "scoreboardhelper.h"

scoreBoardHelper::scoreBoardHelper()
{
    score = 0;
    playerNumber = 0;
}

void scoreBoardHelper::setPlayer(int puntos, int numero){
    score = puntos;
    playerNumber = numero;
}

int scoreBoardHelper::getScore(){
    return score;
}

int scoreBoardHelper::getPlayerNumber(){
    return playerNumber;
}

void scoreBoardHelper::copy(scoreBoardHelper cp){
    score = cp.score;
    playerNumber = cp.playerNumber;
}









