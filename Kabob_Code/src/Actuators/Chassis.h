#pragma once

#include "Arduino.h"

class Chassis
{
  public:
    Chassis(unsigned f1_pin, unsigned f2_pin, unsigned b1_pin, unsigned b2_pin);
    void forward(uint8_t speed);
    void backward(uint8_t speed);
    void left(uint8_t speed);
    void right(uint8_t speed);
    void stop(void);
  private:
    unsigned f1_pin;
    unsigned f2_pin;
    unsigned b1_pin;
    unsigned b2_pin;
};