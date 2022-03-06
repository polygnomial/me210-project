#pragma once

#include "Arduino.h"

class BeaconSensor
{
  public:
    BeaconSensor(int pin);
    uint32_t read();
    int getPin();
  private:
    int pin;
};