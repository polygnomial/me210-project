#include "Arduino.h"
#include "Claw.h"

void Claw::open(void) {
  servo.write(95);
  Serial.print("opening to:");
  Serial.println(95);
}

void Claw::close(void) {
  servo.write(122);
  Serial.print("closing to:");
  Serial.println(122);
}