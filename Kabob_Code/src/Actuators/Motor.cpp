#include "Arduino.h"
#include "Motor.h"

void Motor::stop(void) {
  analogWrite(f_pin, 0);
  analogWrite(b_pin, 0);
}

void Motor::cw_at_speed(uint8_t speed) {
  analogWrite(f_pin, speed);
  analogWrite(b_pin, 0); 
}

void Motor::ccw_at_speed(uint8_t speed) {
  analogWrite(f_pin, 0);
  analogWrite(b_pin, speed); 
}
