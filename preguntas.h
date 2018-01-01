#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <QByteArray>

class preguntas
{
public:
    preguntas();
    void borrarPregunta();
    void guardarPregunta(QByteArray preg,QByteArray resA,QByteArray resB,QByteArray resC,QByteArray resD,int cantRes,int respCor);
    QByteArray getPregunta();
    QByteArray getRespuestaA();
    QByteArray getRespuestaB();
    QByteArray getRespuestaC();
    QByteArray getRespuestaD();
    int getCantResp();
    int getRespCorrect();
    void copy(preguntas cp);

private:
    QByteArray pregunta;
    QByteArray respuestaA;
    QByteArray respuestaB;
    QByteArray respuestaC;
    QByteArray respuestaD;
    int cantResp;
    int respCorrect;
};

#endif // PREGUNTAS_H
