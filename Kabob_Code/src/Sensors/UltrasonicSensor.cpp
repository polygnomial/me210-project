#include "Arduino.h"
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int pin)
{  
  pin = pin;
  pinMode(pin, INPUT);
}

int UltrasonicSensor::read()
{
  return 0;
}
