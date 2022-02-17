#include <Arduino.h>
#include <Wire.h>
#include <AccelStepper.h>

#define PWM_FREQUENCY               490 // hz
#define MILLISECONDS(time)({time * 1000;})
#define MICROSECONDS(time)({time * 1000000;})
#define PWM_CYCLE_LENGTH            MICROSECONDS((float)1/PWM_FREQUENCY)

int outputPinF1 = 3; 
int outputPinB1 = 4;  
int outputPinF2 = 11;
int outputPinB2 = 12;
int state = HIGH; //low is bwds, high is fwds


IntervalTimer pin_timer;
volatile unsigned int motor_running;
volatile unsigned int pin_state;
unsigned long previous_millis; 
static double duty_cycle;
static double off_time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, world!");

  // Initialize pins
  //pinMode(inputPin, INPUT);
  pinMode(outputPinF1,OUTPUT);
  pinMode(outputPinB1,OUTPUT);
  pinMode(outputPinF2,OUTPUT);
  pinMode(outputPinB2,OUTPUT);
  // Set all pins to low to start
  analogWrite(outputPinB1, LOW);
  analogWrite(outputPinB2, LOW);
  analogWrite(outputPinF1, LOW);
  analogWrite(outputPinF2, LOW);  


  // handle PWM
  duty_cycle = 0.5;
  off_time = PWM_CYCLE_LENGTH - duty_cycle;
  pin_timer.begin(TogglePin, duty_cycle);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (state == HIGH) {
    analogWrite(outputPinF1, 255); //for now just set to max output
    analogWrite(outputPinF2, 255);
    analogWrite(outputPinB1, 0);
    analogWrite(outputPinB2, 0);
  } else if (state == LOW) {
    analogWrite(outputPinB1, 255); //for now just set to max output
    analogWrite(outputPinB2, 255);
    analogWrite(outputPinF1, 0);
    analogWrite(outputPinF2, 0);
  }
}
  
