#pragma once

#include "Arduino.h"

class UltrasonicSensor
{
  public:
    UltrasonicSensor(uint8_t trig_pin, uint8_t echo_pin):
      trig_pin(trig_pin),
      echo_pin(echo_pin),
      echo_start(0),
      echo_end(0),
      echo_duration(0)
      {
        pinMode(trig_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
        ultrasonic_sensors[num_ultrasonic_sensors] = this;
        num_ultrasonic_sensors++;
      };

    float read();
    static void initialize(void);

    // TODO might be able to make these private
    static void timerISR(void);
    static void echo_interrupt();
    static void trigger_pulse();

  private:    
    uint8_t trig_pin;
    uint8_t echo_pin;
    volatile long echo_start; 
    volatile long echo_end;
    volatile long echo_duration;

  protected:
    // class variables
    const static unsigned timer_us = 50; // 50 us
    const static unsigned tick_counts = 4000; // 200 ms
    static IntervalTimer timer;
    static uint8_t num_ultrasonic_sensors;
    static UltrasonicSensor* ultrasonic_sensors[5];

    static volatile int trigger_time_count;
};