#include "Arduino.h"
#include "Chassis.h"

Chassis::Chassis(unsigned f1_pin, unsigned f2_pin, unsigned b1_pin, unsigned b2_pin)
{  
  f1_pin = f1_pin;
  f2_pin = f2_pin;
  b1_pin = b1_pin;
  b2_pin = b2_pin;
  pinMode(f1_pin, OUTPUT);
  pinMode(f2_pin, OUTPUT);
  pinMode(b1_pin, OUTPUT);
  pinMode(b2_pin, OUTPUT);
}

void Chassis::stop(void) {
  analogWrite(f1_pin, 0);
  analogWrite(f2_pin, 0); 
  analogWrite(b1_pin, 0);
  analogWrite(b2_pin, 0);
}

void Chassis::forward(uint8_t speed) {
  analogWrite(f1_pin, speed);
  analogWrite(f2_pin, speed); 
  analogWrite(b1_pin, 0);
  analogWrite(b2_pin, 0);
}

void Chassis::backward(uint8_t speed) {
  analogWrite(f1_pin, 0);
  analogWrite(f2_pin, 0); 
  analogWrite(b1_pin, speed);
  analogWrite(b2_pin, speed);
}