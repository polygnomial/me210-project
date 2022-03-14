#include "Arduino.h"
#include "LineSensor.h"

LineSensor::LineSensor(int pin)
{  
  LineSensor::pin = pin;
  pinMode(pin, INPUT);
}

int LineSensor::read()
{
  int value = 0;
  for (int i = 0; i < 10; i++)
  {
    value += analogRead(pin);
  }
  value /= 10;

  if(value <= lineThreshold){
    return 0;
  }
  else{
    return 1;
  }
}

int LineSensor::readAnalog()
{
  int value = analogRead(pin);

  return value;
}

int LineSensor::getPin()
{
  return pin;
}
