#include "Arduino.h"
#include "StepperMotor.h"

void StepperMotor::cw(int steps) {
  stepper.setSpeed(60);
  stepper.step(steps);
}

void StepperMotor::ccw(int steps) {
  stepper.setSpeed(-60);
  stepper.step(steps);
}

void StepperMotor::stop() {
    return;
}

