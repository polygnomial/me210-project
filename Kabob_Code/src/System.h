#pragma once

#include "Arduino.h"
#include "Sensors/LineSensor.h"
#include "Sensors/UltrasonicSensor.h"
#include "Actuators/Chassis.h"
#include "Actuators/Claw.h"

#define RIGHT_BACKWARD_PIN 3
#define RIGHT_FORWARD_PIN 4
#define LEFT_BACKWARD_PIN 9
#define LEFT_FORWARD_PIN 10

#define SERVO_PIN 6

#define OPEN_CLAW_ANGLE 170
#define CLOSE_CLAW_ANGLE 50

#define LINE_RIGHT 18
#define LINE_LEFT 14
#define LINE_CENTER_MIDDLE 15
#define LINE_CENTER_RIGHT 16
#define LINE_CENTER_LEFT 17

struct System
{
  public:
    struct Sensors
    {
      struct LineSensors{
        LineSensor left = LineSensor(LINE_LEFT);
        LineSensor center_middle = LineSensor(LINE_CENTER_MIDDLE);
        LineSensor center_left = LineSensor(LINE_CENTER_LEFT);
        LineSensor center_right = LineSensor(LINE_CENTER_RIGHT);
        LineSensor right = LineSensor(LINE_RIGHT);
      };
      LineSensors line;

      struct UltrasonicSensors{
        UltrasonicSensor front = UltrasonicSensor(15);
        UltrasonicSensor periscope = UltrasonicSensor(15);
      };
      UltrasonicSensors ultra;
    };
    Sensors sensors;
    Chassis chassis = Chassis(RIGHT_FORWARD_PIN, 
                              RIGHT_BACKWARD_PIN, 
                              LEFT_FORWARD_PIN,
                              LEFT_BACKWARD_PIN);
    Claw claw = Claw(SERVO_PIN, OPEN_CLAW_ANGLE, CLOSE_CLAW_ANGLE);
};

extern struct System shephard;