#include "Buttons.h"

Buttons::Buttons(){status = NOTPRESSED; }

bool Buttons::getStatus(){ return status; }

void Buttons::setStatus(int status){ this->status = status; }

Buttons::~Buttons(){}