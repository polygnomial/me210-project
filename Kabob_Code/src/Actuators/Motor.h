#pragma once

#include "Arduino.h"

class Motor
{
public:
  Motor(unsigned f_pin,
        unsigned b_pin,
        uint8_t min_speed) : f_pin(f_pin),
                             b_pin(b_pin)
  {
    pinMode(f_pin, OUTPUT);
    pinMode(b_pin, OUTPUT);
  };

  void activity(void);
  void stop(void);

  void cw_at_speed(uint8_t speed);
  void ccw_at_speed(uint8_t speed);

protected:
  unsigned f_pin,
           b_pin;
};
