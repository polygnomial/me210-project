//#pragma once

#include "Arduino.h"

class LineSensor
{
  public:
    LineSensor(int pin);
    int read();
    int readAnalog();     //adding for debug purposes
    int getPin();
    const int lineThreshold = 600; 
  private:
    int pin;
};