#pragma once

#include "Arduino.h"
#include <Servo.h>

class Claw
{
  public:
    Claw(unsigned servo_pin, unsigned open_angle, unsigned close_angle);
    void open(void);
    void close(void);
  private:
    unsigned servo_pin;
    unsigned open_angle;
    unsigned close_angle;
    Servo servo;
};