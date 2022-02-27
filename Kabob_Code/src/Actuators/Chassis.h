#pragma once

#include "Arduino.h"
#include "Motor.h"

class Chassis
{
  public:
    Chassis(unsigned rf_pin, 
            unsigned rb_pin, 
            unsigned lf_pin, 
            unsigned lb_pin,
            unsigned re_pin1, // polarity of these does not matter as far as I can tell
            unsigned re_pin2,
            unsigned le_pin1,
            unsigned le_pin2) : 
      right(rf_pin, rb_pin, re_pin1, re_pin2),
      left(lf_pin, lb_pin, le_pin1, le_pin2){
      };
    // can optionally add encoder to make fake inertial measured movements
    void forward(uint32_t angle, uint8_t speed = 100);
    void backward(uint32_t angle, uint8_t speed = 100);
    void forward_at_speed(uint8_t speed);
    void backward_at_speed(uint8_t speed);
    void right_at_speed(uint8_t speed);
    void left_at_speed(uint8_t speed);
    void stop(void);
    void activity(void);

    Motor right;
    Motor left;
};

//TODO decide when to reset the counter things