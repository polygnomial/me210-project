#include "StateMachine.h"
#include <Arduino.h>
#include <Metro.h>

#define VELOCITY 100

#define Right_TURN_TIME       3000
#define SECOUND_TURN_TIME     1000

uint8_t DEBUG = true; 

States_t state;
States_r line_state;
Zones_t zone;

unsigned long state_time;
unsigned long serial_time; 
unsigned long curr_time;
unsigned long zone_time;

uint8_t servoPin = 6;
uint8_t servoPos = 0;

uint8_t flagLeftLine = 0;
uint8_t flagRightLine = 0;

volatile uint32_t frequency = 0;
IntervalTimer myTimer;
IntervalTimer freqTimer;
int test = 400;
volatile uint32_t count = 0;

// right now code only works for state red
uint8_t stateRed = true;

//if this is true, do not allow motor to be set on different course
// unless extreme reason (i.e. hole)
uint8_t navigationSet = 0;

unsigned long flag_time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // shephard.claw.open();
  while(!Serial);
  delay(5000);

  //times
  curr_time = millis();
  serial_time = millis();
  state_time = millis();
  flag_time = millis();

  changeStateTo(STATE_NAV_TARGET);
  
  Serial.println("Setup Complete!");

  freqTimer.begin(announceF,1000000);
  attachInterrupt(digitalPinToInterrupt(5), CountFallingEdges, FALLING);
}

void loop() {
  curr_time = millis();
  // checkGlobalEvents();
  // checkFlags();
  // checkForZoneChange();
  // shephard.activity();

  // switch(state) {
  //   case STATE_IDLE:
  //     shephard.chassis.stop();
  //     break;
  //   case STATE_LOAD:
  //     handleLoadState();
  //     break;
  //   case STATE_NAV_TARGET:
  //     handleNavTargetState();
  //     break;
  //   case STATE_UNLOAD:
  //     handleUnloadState();
  //     break;
  //   case STATE_NAV_LOAD:
  //     handleNavLoadState();
  //     break;
  //   default:
  //     Serial.println("What is this I do not even...");
  // }
  
  //debug for line sensors
  if (curr_time - serial_time > MILLISECONDS(1/PRINT_FREQUENCY) && DEBUG){
    Serial.println("---------------");
    Serial.println(frequency);
  //   // Serial.println("left " + String(shephard.sensors.line.left.read()));
  //   // Serial.println("right " + String(shephard.sensors.line.right.read()));
  //   // Serial.println("center left " + String(shephard.sensors.line.center_left.read()));
  //   // Serial.println("center middle " + String(shephard.sensors.line.center_middle.read()));
  //   // Serial.println("center right " + String(shephard.sensors.line.center_right.read()));
  //   Serial.println("Beacon " + String(shephard.sensors.beacon.front.read()));
  //   Serial.println("---------------");
  //   serial_time = curr_time;
  }
}

void handleLoadState(void) {
  unsigned int timeInState = curr_time - state_time;
  if (timeInState < 1000) {
    shephard.claw.open(); 
  } else if (timeInState > 1000 && timeInState < 2000) {
    shephard.claw.close(); 
  } else if (timeInState > 2000  && timeInState < 2100) {
    shephard.chassis.move_forward(20, 150);
  } else if (timeInState > 3500) { 
    changeStateTo(STATE_NAV_TARGET);
    // changeZoneTo(ZONE_1);
  }
}

void handleUnloadState(void) {
  int timeInState = curr_time - state_time;
  if (timeInState < 1000) {
    // shephard.claw.open(); 
  } else if (timeInState > 1000 && timeInState < 4000) {
    shephard.chassis.move_backward(15, VELOCITY);
  } else if (timeInState > 4000 && timeInState < 10000) {
    shephard.chassis.turn_ccw(360, VELOCITY);
  } else if (timeInState > 10000) {
    changeStateTo(STATE_NAV_LOAD);
  } 
}

void handleNavTargetState(void){  
  unsigned long t = curr_time - zone_time; 
  if (frequency == 0) {
    shephard.chassis.turn_ccw(5, 100);
  } else if (frequency > 3000) { // AND ULTRASONIC SENSOR SAYS AWAY FROM WALL. Assume for the red team
    shephard.chassis.move_forward_at_speed(100);
  } else {
    shephard.chassis.stop();
    Serial.println (frequency);
  }
}

void CountFallingEdges(void) {
  count ++;
}                     

void announceF(void) {
  frequency=count;
  count=0;
}

void handleNavLoadState(void) {
  shephard.chassis.stop();
}

void checkGlobalEvents(void) {
  if (TestForKey()) RespToKey();
}

void checkFlags(void) {
  if (curr_time - flag_time > FLAG_TIME) {
    flagLeftLine = 0;
    flagRightLine = 0;
  }
}

void checkForZoneChange(void) {
    uint8_t left = shephard.sensors.line.left.read();
    uint8_t right = shephard.sensors.line.right.read();
    //Serial.println(left);
    if (left && zone == ZONE_1) {
      setFlag(flagLeftLine);
      changeZoneTo(ZONE_2);
    } else if (right && zone == ZONE_2) {
      setFlag(flagRightLine);
      changeZoneTo(ZONE_3);
    } else if (left && zone == ZONE_3 && curr_time - zone_time > 2000) {
      changeZoneTo(ZONE_4);
      setFlag(flagLeftLine);
    } else if (left && zone == ZONE_4 && curr_time - zone_time > 2000) {
      changeZoneTo(ZONE_TARGET);
    }
}


void lineFollow(void) {
    uint8_t center_left = shephard.sensors.line.center_left.read();
    uint8_t center_middle = shephard.sensors.line.center_middle.read();
    uint8_t center_right = shephard.sensors.line.center_right.read();
    // primary line sensing states
    if (center_middle && !center_right && !center_left){
      changeLineStateTo(STATE_ON_LINE);
    }
    else if (!center_middle && center_right && !center_left) { 
      changeLineStateTo(STATE_OFF_LEFT);
    }
    else if (!center_middle && !center_right && center_left) { 
      changeLineStateTo(STATE_OFF_RIGHT);
    }
    else if (center_middle && !center_right && center_left && !flagLeftLine) { 
      changeLineStateTo(STATE_OFF_SLIGHT_RIGHT);
    }
    else if (center_middle && center_right && !center_left && !flagRightLine) { 
      changeLineStateTo(STATE_OFF_SLIGHT_LEFT);
    }

    switch(line_state) {
      case STATE_ON_LINE:
        shephard.chassis.move_forward_at_speed(130);
        break;
      case STATE_OFF_RIGHT:
        shephard.chassis.veer_forward(140, 100);
        break;
      case STATE_OFF_SLIGHT_RIGHT:
        shephard.chassis.veer_forward(130, 100);
        break;
      case STATE_OFF_LEFT:
        shephard.chassis.veer_forward(100, 140);
        break;
      case STATE_OFF_SLIGHT_LEFT:
        shephard.chassis.veer_forward(100, 130);
        break;
      default:
        Serial.println("humm");
    }

}

void makeFirstTurn() {
  if (stateRed) shephard.chassis.turn_cw(90, 100);
  else shephard.chassis.turn_ccw(90, 100);
}

void makeSecondTurn() {
  if (stateRed) shephard.chassis.turn_ccw(70, 100);
  else shephard.chassis.turn_ccw(70, 100);
}
  
uint8_t TestForKey(void) {
  uint8_t KeyEventOccurred;
  KeyEventOccurred = Serial.available();
  return KeyEventOccurred;
}


void changeStateTo(States_t s) {
  if (s != state) {
    state = s;
    state_time = curr_time;
  }
}

void changeLineStateTo(States_r s) {
  if (s != line_state) {
    line_state = s;
  }
}

void changeZoneTo(Zones_t z) {
  if (z != zone) {
    zone = z;
    zone_time = millis();
    Serial.println("In new zone " + z);
  }
}

void setFlag(uint8_t flag){
  flag = true;
  flag_time = curr_time;
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
    case 'r': 
      changeStateTo(STATE_NAV_TARGET);      
      break;
    default:
      break;
  }
}



