#pragma once

#include "Arduino.h"
#include "Stepper.h"

#define STEPS_PER_REVOLUTION 200

class StepperMotor
{
public:
  StepperMotor(unsigned dir_pin, unsigned step_pin)
  {
    pinMode(dir_pin, OUTPUT);
    pinMode(step_pin, OUTPUT);
    stepper = Stepper(STEPS_PER_REVOLUTION, dir_pin, step_pin);

  };

  void cw(int steps);
  void ccw(int steps);
  void stop(void);

  Stepper stepper;

};
