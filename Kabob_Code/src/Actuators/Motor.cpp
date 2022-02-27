#include "Arduino.h"
#include "Motor.h"

void Motor::activity(void){
  bool reset = false;
  uint32_t delta = encoder.read() - pos;
  
  // decide whether to stop
  if (overflow + delta > target){
    stop();
  }

  // overflow protection
  if (pos > 0xFFFFFF){
    overflow = pos;
    pos = delta - pos;
    encoder.write(0);
    reset = true;
  }

  // update position
  pos += delta;
}

void Motor::stop(void) {
  analogWrite(f_pin, 0);
  analogWrite(b_pin, 0); 
  overflow = 0;
  pos = 0;
  target = 0;
}

void Motor::forward(uint32_t angle, uint8_t speed){
  forward_at_speed(speed);
  target = pos + angle / 360 * 1920;
}

void Motor::backward(uint32_t angle, uint8_t speed){
  backward_at_speed(speed);
  target = pos + angle / 360 * 1920;
}

void Motor::forward_at_speed(uint8_t speed) {
  analogWrite(f_pin, speed);
  analogWrite(b_pin, 0); 
}

void Motor::backward_at_speed(uint8_t speed) {
  analogWrite(f_pin, 0);
  analogWrite(b_pin, speed); 
}

int Motor::get_pos(void){
  return pos;
}