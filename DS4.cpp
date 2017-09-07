#include "DS4.h"

DS4::DS4(){
    rc.open("/dev/input/js0");
    if(rc == NULL)
        cerr << "Erro ao abrir evento do controle\n";

    but = new Buttons [11]; //Cria os botões a serem usados


    
}

DS4::DS4(string local){
    rc.open(local.c_str());
    if(rc == NULL)
        cerr << "Erro ao abrir evento do controle\n";
}

int DS4::buttonPos(int button){
    switch(button){
        case SQUARE: return SQUAREPOS;
        case CROSS: return CROSSPOS;
        case CIRCLE: return CIRCLEPOS;
        case TRIANGLE: return TRIANGLEPOS;
        case UP: return UPPOS;
        case DOWN: return DOWNPOS;
        case LEFT: return LEFTPOS;
        case RIGHT: return RIGHTPOS;
        case SHARE: return SHAREPOS;
        case OPTIONS: return OPTIONSPOS;
        case PSN: return PSNPOS;
    }
}

bool DS4::DS4UpdateState(){
    cout << "antes\n";
    if(!(rc.read(buff, sizeof(buff)))) //Lê os dados do controle
        return 0; 
    //////DEBUG/////
    /*for(int i=0; i<8; i++) 
        cout << (int)buff[i] << "  ";
    cout << endl;*/

    int type = buff[6];   
    int value = buff[7];
    int status = buff[4]; 

    if(type == 1){ //Botões Comuns
        but[buttonPos(value)].setStatus(status);
    }
    else if(type == 2){ //D-PAD
        if(value == 6){ //D-PAD horizontal
            if((int)buff[4] == 1 && (int)buff[5] == -128)
                but[buttonPos(LEFT)].setStatus(PRESSED);
            else if((int)buff[4] == -1 && (int)buff[5] == 127)
                but[buttonPos(RIGHT)].setStatus(PRESSED);
            else{
                but[buttonPos(LEFT)].setStatus(NOTPRESSED);
                but[buttonPos(RIGHT)].setStatus(NOTPRESSED);
            }
        }
        else if(value == 7){ //D-PAD vertical
            if((int)buff[4] == 1 && (int)buff[5] == -128)
                but[buttonPos(UP)].setStatus(PRESSED);
            else if((int)buff[4] == -1 && (int)buff[5] == 127)
                but[buttonPos(DOWN)].setStatus(PRESSED);
            else{
                but[buttonPos(UP)].setStatus(NOTPRESSED);
                but[buttonPos(DOWN)].setStatus(NOTPRESSED);
            }
        }
    }
    cout << "depois\n";

    return 1;
}

bool DS4::checkIfPressed(int button){
    switch(button){
        case SQUARE: return but[SQUAREPOS].getStatus();
        case CROSS: return but[CROSSPOS].getStatus();
        case CIRCLE: return but[CIRCLEPOS].getStatus();
        case TRIANGLE: return but[TRIANGLEPOS].getStatus();
        case UP: return but[UPPOS].getStatus();
        case DOWN: return but[DOWNPOS].getStatus();
        case LEFT: return but[LEFTPOS].getStatus();
        case RIGHT: return but[RIGHTPOS].getStatus();
        case SHARE: return but[SHAREPOS].getStatus();
        case OPTIONS: return but[OPTIONSPOS].getStatus();
        case PSN: return but[PSNPOS].getStatus();
    }
    return 0;
}

DS4::~DS4(){
    delete [] but;
    rc.close();
}