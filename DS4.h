#ifndef __DS4_H
#define __DS4_H

#include <linux/input.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Buttons.h"

enum ButtonPos{
    SQUAREPOS,
    CROSSPOS,
    CIRCLEPOS,
    TRIANGLEPOS,
    UPPOS,
    DOWNPOS,
    LEFTPOS,
    RIGHTPOS,
    SHAREPOS,
    OPTIONSPOS,
    PSNPOS
};

class DS4{
public:
    DS4();
    DS4(string local);

    int buttonPos(int button);
    bool DS4UpdateState();
    bool checkIfPressed(int button);

    ~DS4();
private:
    Buttons * but;
    ifstream rc; //Arquivo para a leitura dos dados do DS4
    char buff[8]; //Buffer para os dados a serem tratados
    int turnedOn; //Analisa se o controle está conectado
};

#endif