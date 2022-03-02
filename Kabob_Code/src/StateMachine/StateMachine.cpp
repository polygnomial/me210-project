#include "StateMachine.h"

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

unsigned long flag_time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  //timer 
  curr_time = millis();
  serial_time = millis();
  state_time = millis();
  flag_time = millis();

  // currently not doing anything
  state = STATE_NAV_TARGET; 
  
  Serial.println("Setup Complete!");
}

void loop() {
  curr_time = millis();
  checkGlobalEvents();
  checkFlags();
  // shephard.activity();

  // TO LINE FOLLOW: Must be in state = state_nav_target

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

  //debug for line sensors
  if (curr_time - serial_time > MILLISECONDS(1/PRINT_FREQUENCY) ){
    Serial.println("---------------");
    //Serial.println("left " + String(shephard.sensors.line.left.read()));
    //Serial.println("right " + String(shephard.sensors.line.right.read()));
    //Serial.println("center left " + String(shephard.sensors.line.center_left.read()));
    //Serial.println("center middle " + String(shephard.sensors.line.center_middle.read()));
    //Serial.println("center right " + String(shephard.sensors.line.center_right.read()));
    //Serial.println("---------------");
    Serial.println("In Zone" + zone);
    serial_time = curr_time;
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
  //shephard.chassis.move_forward_at_speed(200);
  //if (millis() - state_time> 5000){
  //  changeStateTo(STATE_IDLE);
  //}       
  switch(zone) {
    case ZONE_LOAD:
      break;
    case ZONE_1:
      lineFollow();
      break;
    case ZONE_2:
      lineFollow();
      break;
    case ZONE_3:
      // turn 90 degrees and then line follow
      if (curr_time - zone_time < 1000) {
        shephard.chassis.turn_right(200);
      } else {
        lineFollow();
      }
      break;
    case ZONE_4:
      break;
    case ZONE_TARGET:
      break;
    default:
      Serial.println("Zone has more states than Paxton thought");
  }
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
    if (left && zone == ZONE_1) {
      flagLeftLine = true;
      flag_time = millis();
      changeZoneTo(ZONE_2);
    } else if (right && zone == ZONE_2) {
      flagRightLine = true;
      flag_time = millis();
      changeZoneTo(ZONE_3);
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
    else if (center_middle && !center_right && center_left) { 
      changeLineStateTo(STATE_OFF_SLIGHT_RIGHT);
    }
    else if (center_middle && center_right && !center_left) { 
      changeLineStateTo(STATE_OFF_SLIGHT_LEFT);
    }

    switch(line_state) {
      case STATE_ON_LINE:
        shephard.chassis.move_forward_at_speed(200);
        break;
      case STATE_OFF_RIGHT:
        shephard.chassis.veer_forward(250, 180);
        break;
      case STATE_OFF_SLIGHT_RIGHT:
        shephard.chassis.veer_forward(250, 180);
        break;
      case STATE_OFF_LEFT:
        shephard.chassis.veer_forward(180, 250);
        break;
      case STATE_OFF_SLIGHT_LEFT:
        shephard.chassis.veer_forward(180, 250);
        break;
      default:
        Serial.println("humm");
    }

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
  }
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



