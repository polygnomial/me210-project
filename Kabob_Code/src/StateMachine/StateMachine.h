#pragma once

#include <Arduino.h>
#include <Wire.h>
#include "System.h"

#define PRINT_FREQUENCY                 1 // hz
#define MILLISECONDS(time)({time * 1000;})

/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_IDLE, STATE_LOAD, STATE_NAV_TARGET, STATE_UNLOAD, STATE_NAV_LOAD
} States_t;

/*----------------------------Function Prototypes------------*/
void checkGlobalEvents(void);
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

/*---------------Module Variables---------------------------*/
