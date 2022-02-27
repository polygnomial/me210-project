#include "Arduino.h"
#include "Motor.h"

void Motor::activity(void){
  pos = encoder.read();

    // overflow protection
  if (pos > 0xFFFFFF){
    overflow += encoder.read();
    encoder.write(0);
    pos = 0;
  }
  
  // decide whether to stop
  if ((pos + overflow ) > target){
    stop();
  }
}

void Motor::stop(void) {
  analogWrite(f_pin, 0);
  analogWrite(b_pin, 0);
  encoder.write(0);
  overflow = 0;
  pos = 0;
  target = 0;
}

void Motor::cw(uint32_t angle, uint8_t speed){
  cw_at_speed(speed);
  target = pos + angle / 360 * 1920;
  encoder.write(0);
  overflow = 0;
  pos = 0;
}

void Motor::ccw(uint32_t angle, uint8_t speed){
  ccw_at_speed(speed);
  target = pos + angle / 360 * 1920;encoder.write(0);
  overflow = 0;
  pos = 0;
}

void Motor::cw_at_speed(uint8_t speed) {
  analogWrite(f_pin, speed);
  analogWrite(b_pin, 0); 
}

void Motor::ccw_at_speed(uint8_t speed) {
  analogWrite(f_pin, 0);
  analogWrite(b_pin, speed); 
}

int Motor::get_pos(void){
  return pos;
}