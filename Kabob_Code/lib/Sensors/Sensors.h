#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"

class Sensors
{
  public:
    Sensors(int PinLineSensor1);
    int readLineSensors();
  private:
    int _PinLineSensor1;
};

#endif
