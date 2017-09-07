#ifndef __BUTTONS_H
#define __BUTTONS_H

#include <linux/input.h>
#include <iostream>

enum ButtonNum{
    SQUARE = 0,
    CROSS = 1,
    CIRCLE = 2,
    TRIANGLE = 3,
    UP = 21,
    DOWN = 22,
    LEFT = 23,
    RIGHT = 24,
    SHARE = 8,
    OPTIONS = 9,
    PSN = 12
};

enum Status{ NOTPRESSED, PRESSED};

class Buttons{
public:
    Buttons();
    bool getStatus();
    void setStatus(int status);
    ~Buttons();

private:
    bool status;
};

#endif