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

void Chassis::move_forward(uint32_t angle, uint8_t speed) {
  right.cw(angle, speed);
  left.ccw(angle, speed);
}

void Chassis::move_backward(uint32_t angle, uint8_t speed) {
  right.ccw(angle, speed);
  left.cw(angle, speed);
}

void Chassis::move_forward_at_speed(uint8_t speed) {
  right.cw_at_speed(speed);
  left.ccw_at_speed(speed);
}

void Chassis::move_backward_at_speed(uint8_t speed) {
  right.ccw_at_speed(speed);
  left.cw_at_speed(speed);
}

void Chassis::turn_right_at_speed(uint8_t speed) {
  right.ccw_at_speed(speed);
  left.ccw_at_speed(speed);
}

void Chassis::turn_left_at_speed(uint8_t speed) {
  right.cw_at_speed(speed);
  left.cw_at_speed(speed);
}