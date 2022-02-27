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
    
    void activity(void);
    void stop(void);
    void move_forward(uint32_t angle, uint8_t speed = 100);
    void move_backward(uint32_t angle, uint8_t speed = 100);
    void turn_left(void);
    void turn_right(void);
    void move_forward_at_speed(uint8_t speed);
    void move_backward_at_speed(uint8_t speed);
    void turn_right_at_speed(uint8_t speed);
    void turn_left_at_speed(uint8_t speed);
  

    Motor right;
    Motor left;
};

//TODO decide when to reset the counter things