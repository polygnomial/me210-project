#pragma once

#include "Arduino.h"

class UltrasonicSensor
{
  public:
    UltrasonicSensor(int pin);
    int read();
    const int lineThreshold = 600; 
  private:
    int pin;
};