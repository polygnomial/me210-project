#pragma once

#include <Arduino.h>
#include <Wire.h>
#include "System.h"



typedef enum {
  STATE_IDLE, STATE_LOAD, STATE_NAV_TARGET, STATE_UNLOAD, 
  STATE_NAV_LOAD,  
} States_t;

typedef enum {
  STATE_ON_LINE, STATE_OFF_LEFT, STATE_OFF_RIGHT,
  STATE_OFF_SLIGHT_RIGHT, STATE_OFF_SLIGHT_LEFT
} States_r;

// Zone defintions
typedef enum {
  ZONE_LOAD, ZONE_1, ZONE_2, ZONE_3, ZONE_4, ZONE_TARGET
} Zones_t;


void checkGlobalEvents(void);
void checkForZoneChange(void);
void lineFollow(void);
void handleMoveForward(void);
void handleMoveBackward(void);
uint8_t TestForKey(void);
void RespToKey(void);
void handleRightTurn(void);
void handleLeftTurn(void);
void handleLoadState(void);
void handleUnloadState(void);
void handleNavTargetState(void);
void handleNavLoadState(void);
void changeStateTo(States_t);
void setup(void);
void loop(void);
void checkFlags(void);
void changeLineStateTo(States_r s);
void changeStateTo(States_t s);
void changeZoneTo(Zones_t z);
void setFlag(uint8_t flag);