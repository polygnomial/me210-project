#include "Test.h"
#include "System.h"
#include "Stepper.h"

// change this to the number of steps on your motor
//Stepper stepper2 = Stepper(200, 16, 15);
// the previous reading from the analog input
int previous = 0;


void setup() {
  // set the speed of the motor to 30 RPMs
  //stepper2.setSpeed(60);

}

void loop() {
  // get the sensor value

  // move a number of steps equal to the change in the
  // sensor reading
  shephard.chassis.stepper_ccw(1);
  //stepper2.step(100);
  delay(3000);

  Serial.println("test");


  // remember the previous value of the sensor
}