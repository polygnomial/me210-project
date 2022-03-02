#pragma once

#include <Arduino.h>
#include <Wire.h>
#include "System.h"

#define PRINT_FREQUENCY                 1 // hz
#define MILLISECONDS(time)({time * 1000;})
#define FLAG_TIME                 1000

/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_IDLE, STATE_LOAD, STATE_NAV_TARGET, STATE_UNLOAD, 
  STATE_NAV_LOAD, STATE_ON_LINE, STATE_OFF_LEFT, STATE_OFF_RIGHT,
  STATE_OFF_SLIGHT_RIGHT, STATE_OFF_SLIGHT_LEFT 
} States_t;

/*----------------------------Function Prototypes------------*/
void checkGlobalEvents(void);
void checkLineSensors(void);
void handleMoveForward(void);
void handleMoveBackward(void);
uint8_t TestForKey(void);
void RespToKey(void);
void handleRightTurn(void);
void handleLeftTurn(void);
void handleLoadState(void);
void handleNavTargetState(void);
void changeStateTo(States_t);
void setup(void);
void loop(void);
void checkFlags(void);

/*---------------Module Variables---------------------------*/
