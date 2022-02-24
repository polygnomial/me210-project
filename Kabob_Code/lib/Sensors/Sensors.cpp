#include "Arduino.h"
#include "Sensors.h"

const int lineThreshold = 600; 

Sensors::Sensors(int PinLineSensor1)
{
  pinMode(PinLineSensor1, INPUT);
  _PinLineSensor1 = PinLineSensor1;
}

int Sensors::readLineSensors()
{
  int lineSensor1 = 0;
  for (int i = 0; i < 10; i++)
  {
    lineSensor1 += analogRead(_PinLineSensor1);
  }
  lineSensor1 /= 10;

  if(lineSensor1 <= lineThreshold){
    return 0;
  }
  else{
    return 1;
  }
}
