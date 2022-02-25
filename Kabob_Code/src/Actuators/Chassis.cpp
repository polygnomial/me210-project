#include "Arduino.h"
#include "Chassis.h"

void Chassis::stop(void) {
  analogWrite(rf_pin, 0);
  analogWrite(rb_pin, 0); 
  analogWrite(lf_pin, 0);
  analogWrite(lb_pin, 0);
}

void Chassis::forward_at_speed(uint8_t speed) {
  analogWrite(rf_pin, speed);
  analogWrite(rb_pin, 0); 
  analogWrite(lf_pin, speed);
  analogWrite(lb_pin, 0);
}

void Chassis::backward_at_speed(uint8_t speed) {
  analogWrite(rf_pin, 0);
  analogWrite(rb_pin, speed); 
  analogWrite(lf_pin, 0);
  analogWrite(lb_pin, speed);
}

void Chassis::right_at_speed(uint8_t speed) {
  analogWrite(rf_pin, speed);
  analogWrite(rb_pin, 0); 
  analogWrite(lf_pin, 0);
  analogWrite(lb_pin, speed);
}

void Chassis::left_at_speed(uint8_t speed) {
  analogWrite(rf_pin, 0);
  analogWrite(rb_pin, speed); 
  analogWrite(lf_pin, speed);
  analogWrite(lb_pin, 0);
}