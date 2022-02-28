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

typedef enum {
  STATE_1, STATE_2, STATE_3, STATE_4, STATE_wait
} States_r;

/*----------------------------Function Prototypes------------*/
void checkGlobalEvents(void);
void handleMoveForward(void);
void handleMoveBackward(void);
uint8_t TestForKey(void);
uint8_t TestforT1(void);
void TestforT2(void);
void ResptoT2(void);
void LineFollow(void);
void RespToKey(void);
void RespToT1(void);
void turn1sequence(void);
void handleRightTurn(void);
void handleLeftTurn(void);
void handleLoadState(void);
void handleNavTargetState(void);
void changeStateTo(States_t);
