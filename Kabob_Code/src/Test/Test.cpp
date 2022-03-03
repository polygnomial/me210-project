#include "Test.h"

#define VELOCITY 255
#define FLAG_TIME                 1000

unsigned long state_time;
unsigned long serial_time; 
unsigned long curr_time;
unsigned long zone_time;

uint8_t servoPin = 6;
uint8_t servoPos = 0;

uint8_t flagLeftLine = 0;
uint8_t flagRightLine = 0;
States_r line_state;
unsigned long flag_time;


void setup(){
    Serial.begin(9600);
}
void loop(void){
    lineFollow();
    checkFlags();
}   


void checkFlags(void) {
  if (curr_time - flag_time > FLAG_TIME) {
    flagLeftLine = 0;
    flagRightLine = 0;
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
        shephard.chassis.move_forward_at_speed(VELOCITY);
        break;
      case STATE_OFF_RIGHT:
        shephard.chassis.veer_forward(250, 180);
        break;
      case STATE_OFF_SLIGHT_RIGHT:
        shephard.chassis.veer_forward(250, 200);
        break;
      case STATE_OFF_LEFT:
        shephard.chassis.veer_forward(180, 250);
        break;
      case STATE_OFF_SLIGHT_LEFT:
        shephard.chassis.veer_forward(200, 250);
        break;
      default:
        Serial.println("humm");
    }

}


void changeLineStateTo(States_r s) {
  if (s != line_state) {
    line_state = s;
  }
}