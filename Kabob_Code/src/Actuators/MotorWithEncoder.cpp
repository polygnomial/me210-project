#include "Arduino.h"
#include "MotorWithEncoder.h"

void MotorWithEncoder::activity(){
  pos = abs(encoder.read());

  Serial.println("position = ");
  Serial.println(pos);
  Serial.println("target : ");
  Serial.println(target);
  
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

void MotorWithEncoder::stop(void) {
  analogWrite(f_pin, 0);
  analogWrite(b_pin, 0);
  encoder.write(0);
  overflow = 0;
  pos = 0;
  target = 0;
}

void MotorWithEncoder::move(double angle, uint8_t speed){
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

void MotorWithEncoder::cw(double angle, uint8_t speed){
  move(angle, speed);
}

void MotorWithEncoder::ccw(double angle, uint8_t speed){
  move(-angle, speed);
}

int MotorWithEncoder::get_pos(void){
  return pos;
}