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


/*----------------------------Module Function Prototypes------------*/
void checkGlobalEvents(void);
void handleMoveForward(void);
void handleMoveBackward(void);
//void handleRightTurn(void);
//void handleLeftTurn(void);

void setPWM(double duty_cycle, uint8_t right_motor);

/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_IDLE, STATE_FORWARD, STATE_BACKWARD
} States_t;

/*---------------Module Variables---------------------------*/
States_t state;

IntervalTimer left_pwm_timer;
IntervalTimer right_pwm_timer;
volatile unsigned int left_motor_state;
volatile unsigned int right_motor_state;

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

  void SetPWM();

  //timer 
  previous_millis = millis();

  // handle PWM
  duty_cycle = 0.5 * PWM_CYCLE_LENGTH;
  off_time = PWM_CYCLE_LENGTH - duty_cycle;
  left_pwm_timer.begin(SetLeftPWM, duty_cycle);
  right_pwm_timer.begin(SetRightPWM, duty_cycle);


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
  
