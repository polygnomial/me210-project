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
            unsigned le_pin2, 
            double hub_to_hub_distance,
            double wheel_circumference) : 
      right(rf_pin, rb_pin, re_pin1, re_pin2),
      left(lf_pin, lb_pin, le_pin1, le_pin2),
      chassis_circumference(hub_to_hub_distance*PI),
      wheel_circumference(wheel_circumference),
      ninety_degrees(chassis_circumference / 4 / wheel_circumference * 360)
      {};
    
    void activity(void);
    void stop(void);
    void move_forward(double distance, uint8_t speed = 100);
    void move_backward(double distance, uint8_t speed = 100);
    void turn_right(uint8_t speed = 100);
    void turn_left(uint8_t speed = 100);
    void turn_cw(double angle, uint8_t speed = 100);
    void turn_ccw(double angle, uint8_t speed = 100);
    void move_forward_at_speed(uint8_t speed);
    void move_backward_at_speed(uint8_t speed);
    void turn_right_at_speed(uint8_t speed);
    void turn_left_at_speed(uint8_t speed);
  

    Motor right;
    Motor left;

    private:
      double chassis_circumference,
             wheel_circumference,
             ninety_degrees;
};

//TODO decide when to reset the counter things