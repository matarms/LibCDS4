#include <linux/input.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
using namespace std;
//#include "ds4.h"


int main()
{
    ifstream rc;
 	char rawdata[8], pre_data[1000];
	int fd;
	int turnedOn = 1; //Analisa se o controle foi desligado
	//DS4_CONTROLLER * ds4;
	/*IN MY CASE THE FILE IS js0*/
    rc.open("/dev/input/by-id/usb-Sony_Interactive_Entertainment_Wireless_Controller-if03-joystick");
    if(rc == NULL)
    cerr << "Erro ao abrir evento do controle\n"; 

    while(1){
        rc.read(rawdata, sizeof(rawdata));

        int type = rawdata[6], status = rawdata[4], value = rawdata[7];
        
        /*cout << "Type: ";
        cout << type << endl;

        cout << "Status: ";
        cout << status << endl;

        cout << "Value: ";
        cout << value << endl;*/

        for(int i=0; i < 8; i++)
            cout << (int)rawdata[i] << "  ";
        cout << endl;

        if(type == 1)
            if(status){
             if(value == 1)
                cout << "x pressed\n";
                if(value == 2)
                cout << "O pressed\n";
            }

    }

	/*read(rc, rawdata, sizeof(pre_data));
	while(turnedOn > 0) {
        turnedOn = read(fd, rawdata, sizeof(rawdata));
        
	    // ds4_update_status(ds4, rawdata);
	    // ds4_print_buttons(ds4);
	}*/
	rc.close();

	return 0;
}