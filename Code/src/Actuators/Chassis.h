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
          unsigned re_pin1,
          unsigned re_pin2,
          unsigned le_pin1,
          unsigned le_pin2,
          double hub_to_hub_distance,
          double wheel_circumference,
          uint8_t min_speed) : right(rf_pin, rb_pin, min_speed),
                               left(lf_pin, lb_pin, min_speed),
                               chassis_circumference(hub_to_hub_distance * PI),
                               wheel_circumference(wheel_circumference),
                               ninety_degrees(chassis_circumference / 4 / wheel_circumference * 360){};

  void activity(void);
  void stop(void);

  /* forward and backward
   * distance (centimeters)
   * - if stop() is called, the Chassis will reset its target.
   */
  void move_forward(double distance, uint8_t speed = 50);
  void move_backward(double distance, uint8_t speed = 50);

  /* turn_right and turn_left
   * rotate 90°
   */
  void turn_right(uint8_t speed = 50);
  void turn_left(uint8_t speed = 50);

  void veer_forward(uint8_t speed_right, uint8_t speed_left);
  void veer_backward(uint8_t speed_right, uint8_t speed_left);

  /* turn_cw and turn_ccw
   * distance (centimeters)
   * - if stop() is called, the Chassis will reset its target.
   */
  void turn_cw(double angle, uint8_t speed = 50);
  void turn_ccw(double angle, uint8_t speed = 50);

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