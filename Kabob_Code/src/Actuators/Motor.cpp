#include "Arduino.h"
#include "Motor.h"

void Motor::activity(){
  pos = abs(encoder.read());
  
  // overflow protection
  if (pos > 0xFFFFFF){
    overflow +=  abs(encoder.read());
    encoder.write(0);
    pos = 0;
  }
  
  // decide whether to stop
  if ((pos + overflow) > target){
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

void Motor::move(double angle, uint8_t speed){
  if (angle > 0){
    cw_at_speed(speed);
  } else {
    ccw_at_speed(speed);
  }
  
  target = abs(pos + angle / 360 * 1920);
  if (speed < min_speed){
    speed = min_speed;
  }

  encoder.write(0);
  overflow = 0;
  pos = 0;
}

void Motor::cw(double angle, uint8_t speed){
  move(angle, speed);
}

void Motor::ccw(double angle, uint8_t speed){
  move(-angle, speed);
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