#ifndef SCOREBOARDHELPER_H
#define SCOREBOARDHELPER_H


class scoreBoardHelper
{
private:
    int score;
    int playerNumber;
public:
    scoreBoardHelper();
    void setPlayer(int puntos,int numero);
    int getScore();
    int getPlayerNumber();
    void copy(scoreBoardHelper cp);
};

#endif // SCOREBOARDHELPER_H
