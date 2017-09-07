#include <linux/input.h>

#include <fstream>
#include <iostream>
using namespace std;
#include "DS4.h"


int main(){
    DS4 control;

    while(control.DS4UpdateState()){        
        if(control.checkIfPressed(CROSS))
            cout << "CROSS pressed\n";
        if(control.checkIfPressed(CIRCLE))
            cout << "CIRCLE pressed\n";
        if(control.checkIfPressed(SQUARE))
            cout << "SQUARE pressed\n";
        if(control.checkIfPressed(TRIANGLE))
            cout << "TRIANGLE pressed\n";
        if(control.checkIfPressed(LEFT))
            cout << "LEFT pressed\n";
        if(control.checkIfPressed(RIGHT))
            cout << "RIGHT pressed\n";
        if(control.checkIfPressed(UP))
            cout << "UP pressed\n";
        if(control.checkIfPressed(DOWN))
            cout << "DOWN pressed\n";
        if(control.checkIfPressed(SHARE))
            cout << "SHARE pressed\n";
        if(control.checkIfPressed(OPTIONS))
            cout << "OPTIONS pressed\n";
        if(control.checkIfPressed(PSN))
            cout << "PSN pressed\n";
        cout << "presses\n";
    }

    cout << "saiu\n";
}