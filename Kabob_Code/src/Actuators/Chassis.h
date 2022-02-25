#pragma once

#include "Arduino.h"

class Chassis
{
  public:
    Chassis(unsigned rf_pin, unsigned rb_pin, unsigned lf_pin, unsigned lb_pin) : 
      rf_pin(rf_pin),
      rb_pin(rb_pin),
      lf_pin(lf_pin),
      lb_pin(lb_pin){
        pinMode(rf_pin, OUTPUT);
        pinMode(rb_pin, OUTPUT);
        pinMode(lf_pin, OUTPUT);
        pinMode(lb_pin, OUTPUT);
      };
    // can optionally add encoder to make fake inertial measured movements
    void forward_at_speed(uint8_t speed);
    void backward_at_speed(uint8_t speed);
    void left_at_speed(uint8_t speed);
    void right_at_speed(uint8_t speed);
    void stop(void);
  private:
    unsigned rf_pin;
    unsigned rb_pin;
    unsigned lf_pin;
    unsigned lb_pin;
};