#pragma once

#include "Arduino.h"
#include <Servo.h>

class Claw
{
  public:
    Claw(unsigned servo_pin, unsigned open_angle, unsigned close_angle):
    open_angle(open_angle),
    close_angle(close_angle)
    {
      pinMode(servo_pin, OUTPUT);
     analogWrite(servo_pin, LOW);
     servo.attach(servo_pin);
    };
    void open(void);
    void close(void);
    Servo servo;
  private:
    unsigned open_angle;
    unsigned close_angle;
};