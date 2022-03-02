#include "StateMachine.h"

States_t state;

unsigned long state_time;
unsigned long serial_time; 
uint8_t servoPin = 6;
uint8_t servoPos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  //timer 
  serial_time = millis();
  state_time = millis();

  state = STATE_IDLE;
  
  Serial.println("Setup Complete!");
}

void loop() {
  checkGlobalEvents();
  shephard.activity();

  switch(state) {
    case STATE_IDLE:
      shephard.chassis.stop();
      break;
    case STATE_LOAD:
      handleLoadState();
      break;
    case STATE_NAV_TARGET:
      handleNavTargetState();
      break;
    case STATE_UNLOAD:
      shephard.chassis.move_backward_at_speed(100);
      break;
    case STATE_NAV_LOAD:
      break;
    default:
      Serial.println("What is this I do not even...");
  }

  unsigned long current_millis = millis();
  if (current_millis - serial_time > MILLISECONDS(1/PRINT_FREQUENCY) ){
    Serial.println("One Secound update: ");
    Serial.println("left " + String(shephard.sensors.line.left.readAnalog()));
    Serial.println("right " + String(shephard.sensors.line.right.readAnalog()));
    Serial.println("center left " + String(shephard.sensors.line.center_left.readAnalog()));
    Serial.println("center middle " + String(shephard.sensors.line.center_middle.readAnalog()));
    Serial.println("center right " + String(shephard.sensors.line.center_right.readAnalog()));
    serial_time = current_millis;
  }

}

void handleLoadState(void) {
  int timeInState = millis() - state_time;
  if (timeInState < 1500) {
    shephard.claw.open(); 
  } else if (timeInState > 3000 && timeInState < 5000) {
    shephard.claw.close(); 
  } else if (timeInState > 5000) {
    changeStateTo(STATE_NAV_TARGET);
  }
}

void handleNavTargetState(void){
  shephard.chassis.move_forward_at_speed(200);
  if (millis() - state_time> 5000) {
    changeStateTo(STATE_IDLE);
  }       
}

void changeStateTo(States_t s) {
  state = s;
  state_time = millis();
  Serial.println("New state = " + s);
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
    case ' ': 
      state = STATE_IDLE;
      break;
    default:
      break;
  }
}
