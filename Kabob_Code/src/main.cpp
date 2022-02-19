#include <Arduino.h>
#include <Wire.h>
#include <AccelStepper.h>
#include <Servo.h>

#define PRINT_FREQUENCY                 1 // hz
#define MILLISECONDS(time)({time * 1000;})

#define F1_PIN  3
#define B1_PIN  4  
#define F2_PIN  9
#define B2_PIN  10
#define SERVO_PIN 6

#define OPEN_CLAW_ANGLE 170
#define CLOSE_CLAW_ANGLE 50

/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_IDLE, STATE_LOAD, STATE_NAV_TARGET, STATE_UNLOAD, STATE_NAV_LOAD
} States_t;

/*----------------------------Function Prototypes------------*/
void initializePins(void);
void checkGlobalEvents(void);
void handleMoveForward(void);
void handleMoveBackward(void);
uint8_t TestForKey(void);
void RespToKey(void);
void handleRightTurn(void);
void handleLeftTurn(void);
void stop(void);
void forward(uint8_t);
void backward(uint8_t);
void handleLoadState(void);
void handleNavTargetState(void);
void closeClaw(void);
void openClaw(void);
void changeStateTo(States_t);


/*---------------Module Variables---------------------------*/
States_t state;

Servo myservo;
unsigned long state_time;
unsigned long serial_time; 
uint8_t servoPin = 6;
uint8_t servoPos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initializePins();

  // What does this do @Darcy?
  analogWrite(SERVO_PIN, LOW);

  //timer 
  serial_time = millis();
  state_time = millis();

  state = STATE_LOAD;
  
  //servo init
  myservo.attach(SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkGlobalEvents();

  switch(state) {
    case STATE_IDLE:
      stop();
      break;
    case STATE_LOAD:
      handleLoadState();
      break;
    case STATE_NAV_TARGET:
      handleNavTargetState();
      break;
    case STATE_UNLOAD:
      backward(100);
      break;
    case STATE_NAV_LOAD:
      break;
    default:
      Serial.println("What is this I do not even...");
  }

  unsigned long current_millis = millis();
  if (current_millis - serial_time > MILLISECONDS(1/PRINT_FREQUENCY) ){
    Serial.println("One Secound update: ");
    serial_time = current_millis;
  }

}

void handleLoadState(void) {
  int timeInState = millis() - state_time;
  if (timeInState < 1500) {
    openClaw();
  } else if (timeInState > 3000 && timeInState < 5000) {
    closeClaw();
  } else if (timeInState > 5000) {
    changeStateTo(STATE_NAV_TARGET);
  }
}

void handleNavTargetState(void){
  forward(200);
  if (millis() - state_time> 5000) {
    changeStateTo(STATE_IDLE);
  }
}

void changeStateTo(States_t s) {
  state = s;
  state_time = millis();
  Serial.println("New state = " + s);
}

void initializePins(void) {
  pinMode(F1_PIN, OUTPUT);
  pinMode(B1_PIN, OUTPUT);
  pinMode(F2_PIN, OUTPUT);
  pinMode(B2_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
}

void stop(void) {
  analogWrite(F1_PIN, 0);
  analogWrite(F2_PIN, 0); 
  analogWrite(B1_PIN, 0);
  analogWrite(B2_PIN, 0);
}

void forward(uint8_t speed) {
  analogWrite(F1_PIN, speed);
  analogWrite(F2_PIN, speed); 
  analogWrite(B1_PIN, 0);
  analogWrite(B2_PIN, 0);
}

void backward(uint8_t speed) {
  analogWrite(F1_PIN, 0);
  analogWrite(F2_PIN, 0); 
  analogWrite(B1_PIN, speed);
  analogWrite(B2_PIN, speed);
}

void openClaw(void) {
  myservo.write(OPEN_CLAW_ANGLE);
}

void closeClaw(void) {
  myservo.write(CLOSE_CLAW_ANGLE);
}

void checkGlobalEvents(void) {
  if (TestForKey()) RespToKey();
}
  
uint8_t TestForKey(void) {
  uint8_t KeyEventOccurred;
  KeyEventOccurred = Serial.available();
  return KeyEventOccurred;
}

void RespToKey(void) {
  uint8_t theKey;
  theKey = Serial.read();
  Serial.print(theKey);
  Serial.print(", ASCII=");
  Serial.println(theKey, HEX);

  switch(theKey) {
    case 0x20:
      state = STATE_IDLE;
      break;
    default:
      break;
  }
}
