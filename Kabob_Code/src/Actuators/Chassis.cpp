#include "Arduino.h"
#include "Chassis.h"

void Chassis::stop(void)
{
  left.stop();
  right.stop();
}

void Chassis::move_forward(double distance, uint8_t speed)
{
  double movement_degrees = distance / wheel_circumference * 360;
  right.move(movement_degrees, speed);
  left.move(-movement_degrees, speed);
}

void Chassis::move_backward(double distance, uint8_t speed)
{
  double movement_degrees = distance / wheel_circumference * 360;
  right.move(-movement_degrees, speed);
  left.move(movement_degrees, speed);
}

void Chassis::turn_right(uint8_t speed)
{
  right.ccw_at_speed(speed);
  left.ccw_at_speed(speed);
}

void Chassis::turn_left(uint8_t speed)
{
  right.cw_at_speed(speed);
  left.cw_at_speed(speed);
}

void Chassis::veer_forward(uint8_t speed_right, uint8_t speed_left)
{
  right.cw_at_speed(speed_right);
  left.ccw_at_speed(speed_left);
}

void Chassis::veer_backward(uint8_t speed_right, uint8_t speed_left)
{
  right.ccw_at_speed(speed_right);
  left.cw_at_speed(speed_left);
}

void Chassis::turn_cw(double angle, uint8_t speed)
{
  double movement_degrees = chassis_circumference * (angle / 360) / wheel_circumference * 360;
  right.ccw(movement_degrees, speed);
  left.ccw(movement_degrees, speed);
}

void Chassis::turn_ccw(double angle, uint8_t speed)
{
  double movement_degrees = chassis_circumference * (angle / 360) / wheel_circumference * 360;
  right.cw(movement_degrees, speed);
  left.cw(movement_degrees, speed);
}

void Chassis::move_forward_at_speed(uint8_t speed)
{
  right.cw_at_speed(speed);
  left.ccw_at_speed(speed);
}

void Chassis::move_backward_at_speed(uint8_t speed)
{
  right.ccw_at_speed(speed);
  left.cw_at_speed(speed);
}

void Chassis::turn_right_at_speed(uint8_t speed)
{
  right.ccw_at_speed(speed);
  left.ccw_at_speed(speed);
}

void Chassis::turn_left_at_speed(uint8_t speed)
{
  right.cw_at_speed(speed);
  left.cw_at_speed(speed);
}