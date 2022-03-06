#include "BeaconSensor.h"

volatile uint32_t count = 0;
volatile uint32_t timerFlag = 0;
volatile uint32_t frequency = 0;
IntervalTimer frequencyTimer;

// keep falling edge count updated
void CountFallingEdges() { 
  count++;
}

// keep falling edge count updated
void UpdateFrequency() { 
  Serial.println(count);
  count=0;
}

BeaconSensor::BeaconSensor(int pin)
{  
  BeaconSensor::pin = pin;
  pinMode(pin, INPUT);
}

uint32_t BeaconSensor::read()
{
  frequencyTimer.begin(UpdateFrequency, 1000000);
  attachInterrupt(digitalPinToInterrupt(pin), CountFallingEdges, FALLING);
  // while(!timerFlag);
  // Serial.println(count);
  return(count);
}

int BeaconSensor::getPin()
{
  return pin;
}