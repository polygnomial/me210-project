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
  frequency = count / 0.01;
  timerFlag = 1;
}

BeaconSensor::BeaconSensor(int pin)
{  
  BeaconSensor::pin = pin;
  pinMode(pin, INPUT);
}

uint32_t BeaconSensor::read()
{
  timerFlag = 0;
  count = 0;
  frequencyTimer.begin(UpdateFrequency, 10000);
  attachInterrupt(digitalPinToInterrupt(pin), CountFallingEdges, FALLING);
  while(!timerFlag);
  Serial.println(count);
  return(count);
}

int BeaconSensor::getPin()
{
  return pin;
}