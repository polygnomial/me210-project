#pragma once

#include "Arduino.h"

class LineSensor
{
  public:
    LineSensor(int pin);
    int read();
    const int lineThreshold = 600; 
  private:
    int pin;
};