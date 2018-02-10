#include "preguntas.h"

preguntas::preguntas()
{
    pregunta = "";
    respuestaA = "";
    respuestaB = "";
    respuestaC = "";
    respuestaD = "";
    cantResp = 0;
    respCorrect = 0;
}

void preguntas::borrarPregunta(){
    pregunta = "";
    respuestaA = "";
    respuestaB = "";
    respuestaC = "";
    respuestaD = "";
    cantResp = 0;
}

void preguntas::guardarPregunta(QByteArray preg,QByteArray resA,QByteArray resB,QByteArray resC,QByteArray resD,int cantRes,int respCor){
    pregunta = preg;
    respuestaA = resA;
    respuestaB = resB;
    respuestaC = resC;
    respuestaD = resD;
    cantResp = cantRes;
    respCorrect = respCor;
}

void preguntas::copy(preguntas cp){
    pregunta = cp.pregunta;
    respuestaA = cp.respuestaA;
    respuestaB = cp.respuestaB;
    respuestaC = cp.respuestaC;
    respuestaD = cp.respuestaD;
    cantResp = cp.cantResp;
    respCorrect = cp.respCorrect;
}

QByteArray preguntas::getPregunta(){
    return pregunta;
}

QByteArray preguntas::getRespuestaA(){
    return respuestaA;
}

QByteArray preguntas::getRespuestaB(){
    return respuestaB;
}

QByteArray preguntas::getRespuestaC(){
    return respuestaC;
}

QByteArray preguntas::getRespuestaD(){
    return respuestaD;
}

int preguntas::getCantResp(){
    return cantResp;
}

int preguntas::getRespCorrect(){
    return respCorrect;
}
















