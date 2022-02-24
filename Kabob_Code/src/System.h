#pragma once

#include "Arduino.h"
#include "Sensors/LineSensor.h"
#include "Sensors/UltrasonicSensor.h"
#include "Actuators/Chassis.h"
#include "Actuators/Claw.h"

#define F1_PIN  3
#define B1_PIN  4  
#define F2_PIN  9
#define B2_PIN  10

#define SERVO_PIN 6

#define OPEN_CLAW_ANGLE 170
#define CLOSE_CLAW_ANGLE 50

class System
{
  public:
    struct Sensors
    {
      struct LineSensors{
        LineSensor left = LineSensor(15);
        LineSensor center_middle = LineSensor(15);
        LineSensor center_left = LineSensor(15);
        LineSensor center_right = LineSensor(15);
        LineSensor right = LineSensor(15);
      };
      LineSensors line;

      struct UltrasonicSensors{
        UltrasonicSensor front = UltrasonicSensor(15);
        UltrasonicSensor periscope = UltrasonicSensor(15);
      };
      UltrasonicSensors ultra;
    };
    Sensors sensors;
    Chassis chassis = Chassis(F1_PIN, F2_PIN, B1_PIN, B2_PIN);
    Claw claw = Claw(SERVO_PIN, OPEN_CLAW_ANGLE, CLOSE_CLAW_ANGLE);
};

System shephard;