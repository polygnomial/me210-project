#include "Arduino.h"
#include "Claw.h"

void Claw::open(void) {
  servo.write(open_angle);
  Serial.print("opening to:");
  Serial.println(open_angle);
}

void Claw::close(void) {
  servo.write(close_angle);
  Serial.print("closing to:");
  Serial.println(close_angle);
}