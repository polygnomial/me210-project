#include "BeaconSensor.h"


// void BeaconSensor::initialize(void){
//   frequencyTimer.begin(UpdateFrequency, 1000000);
//   attachInterrupt(digitalPinToInterrupt(pin), CountFallingEdges, FALLING);
// }

// keep falling edge count updated
void BeaconSensor::CountFallingEdges() { 
  count++;
}

// keep falling edge count updated
void BeaconSensor::UpdateFrequency() { 
  // Serial.println(count);
  frequency=count;
  count=0;
}

uint32_t BeaconSensor::read()
{
  // freqTimer.begin(announceF,timertime);
  
  // while(!timerFlag);
  // Serial.println(count);
  return(frequency);
}

int BeaconSensor::getPin()
{
  return pin;
}