#pragma once

#include "Arduino.h"

class BeaconSensor
{
  public:
    BeaconSensor(int pin):
      pin(pin)
      {
        pinMode(pin, INPUT);
      }
    uint32_t read();
    int getPin();
    
  private:
    void initialize(void);
    void CountFallingEdges(void);
    void UpdateFrequency(void);
    
    int pin;
    volatile float frequency;
    int count = 0;
    volatile uint32_t timerFlag = 0;
    // int frequency = 0;
    IntervalTimer frequencyTimer;
};