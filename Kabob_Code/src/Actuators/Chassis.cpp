#include "Arduino.h"
#include "Chassis.h"

void Chassis::activity(void){
  right.activity();
  left.activity();
}

void Chassis::stop(void) {
  left.stop();
  right.stop();
}

void Chassis::forward(uint32_t angle, uint8_t speed) {
  right.forward(angle, speed);
  left.forward(angle, speed);
}

void Chassis::backward(uint32_t angle, uint8_t speed) {
  right.backward(angle, speed);
  left.backward(angle, speed);
}

void Chassis::forward_at_speed(uint8_t speed) {
  right.forward_at_speed(speed);
  left.forward_at_speed(speed);
}

void Chassis::backward_at_speed(uint8_t speed) {
  right.backward_at_speed(speed);
  left.backward_at_speed(speed);
}

void Chassis::right_at_speed(uint8_t speed) {
  right.backward_at_speed(speed);
  left.forward_at_speed(speed);
}

void Chassis::left_at_speed(uint8_t speed) {
  right.forward_at_speed(speed);
  left.backward_at_speed(speed);
}