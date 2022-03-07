#include "Test.h"
#include <Arduino.h>
#include <System.h>

bool moved_forward;
bool turned_left;
bool moved_forward2;
bool turned_right;
bool moved_forward3;
bool finished;
bool moved_backward;
bool turn_right2;
bool moved_forward4;
bool turned_start;
bool moved_backward2;
const bool red = true; 

void setup() {
  Serial.begin(9600);
  shephard.claw.open();
  delay(8000);
  moved_forward = false;
  turned_left = false;
  moved_forward2 = false;
  turned_right = false;
  moved_forward3 = false;
  moved_backward = false;
  turn_right2 = false;
  moved_forward4 = false;
  turned_start = false;
  moved_backward2 = false;
}

void loop() {
  shephard.activity();
  // Serial.println(shephard.chassis.movement_complete());
  if (!moved_forward && shephard.chassis.movement_complete()){
    shephard.claw.close();
    shephard.chassis.move_forward(60, 255);
    moved_forward = true;
  } else if (moved_forward && !turned_left && shephard.chassis.movement_complete()){
    if (red){shephard.chassis.turn_ccw(68);}
    else {shephard.chassis.turn_cw(68);}
    turned_left = true;
  }
  else if (turned_left && !moved_forward2 && shephard.chassis.movement_complete()){
    shephard.chassis.move_forward(188, 255);
    moved_forward2 = true;
  }
  else if (moved_forward2 && !turned_right && shephard.chassis.movement_complete()){
    if (red){shephard.chassis.turn_cw(70);}
    else {shephard.chassis.turn_ccw(70);}
    turned_right = true;
  }
  else if (turned_right && !moved_forward3 && shephard.chassis.movement_complete()){
    shephard.chassis.move_forward(10);
    moved_forward3 = true;
  }
  else if (moved_forward3 & !moved_backward && shephard.chassis.movement_complete()){
    shephard.claw.open();
    delay(1000);
    shephard.chassis.move_backward(55);
    moved_backward = true;
  }
  else if (moved_backward && !turn_right2 && shephard.chassis.movement_complete()){
    if (red){shephard.chassis.turn_cw(67);}
    else{shephard.chassis.turn_ccw(67);}
    turn_right2 = true;
  }
  else if (turn_right2 && !moved_forward4 && shephard.chassis.movement_complete()){
    shephard.chassis.move_forward(183, 255);
    moved_forward4 = true;
  }
  else if (moved_forward4 && !turned_start && shephard.chassis.movement_complete()){
    if (red){shephard.chassis.turn_ccw(60);}
    else{shephard.chassis.turn_cw(60);}
    turned_start = true;
  }
  else if (turned_start && !moved_backward2 && shephard.chassis.movement_complete()){
    shephard.chassis.move_backward(7, 255);
    moved_backward2 = true;
  }
  else if (moved_backward2 && shephard.chassis.movement_complete()){
    delay(5000);
    moved_forward = false;
    turned_left = false;
    moved_forward2 = false;
    turned_right = false;
    moved_forward3 = false;
    moved_backward = false;
    turn_right2 = false;
    moved_forward4 = false;
    turned_start = false;
    moved_backward2 = false;
  }
}