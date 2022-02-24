#include "Arduino.h"
#include "Claw.h"

Claw::Claw(unsigned servo_pin, unsigned open_angle, unsigned close_angle){
    servo_pin = servo_pin;
    open_angle = open_angle;
    close_angle = close_angle;
    pinMode(servo_pin, OUTPUT);
    analogWrite(servo_pin, LOW);
    servo.attach(servo_pin);
}

void Claw::open(void) {
  servo.write(open_angle);
}

void Claw::close(void) {
  servo.write(close_angle);
}