#pragma once

#include "Arduino.h"

#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

class Motor
{
  public:
    Motor(unsigned f_pin, 
          unsigned b_pin, 
          unsigned e_pin1, // polarity of these does not matter as far as I can tell
          unsigned e_pin2) :
      f_pin(f_pin),
      b_pin(b_pin),
      encoder(e_pin1, e_pin2){
        pinMode(f_pin, OUTPUT);
        pinMode(b_pin, OUTPUT);
      };
    // can optionally add encoder to make fake inertial measured movements

    
    void activity(void);

    void stop(void);
    /* cw (clockwise) and ccw (counterclockwise):
     * angle (degrees)
     * - clockwise when looking at the motor along the shaft
     * - if stop() is called, the Motor will reset its target
     */
    void cw(uint32_t angle, uint8_t speed);
    void ccw(uint32_t angle, uint8_t speed);
    
    void cw_at_speed(uint8_t speed);
    void ccw_at_speed(uint8_t speed);
    
    int get_pos(void);

  private:
    unsigned f_pin,
             b_pin;

    Encoder encoder;

    int pos;
    double target;
    double overflow;
};

//TODO decide when to reset the counter things