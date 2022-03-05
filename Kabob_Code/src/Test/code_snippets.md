# Quasi Regression Testing

(meant to help debug whether issues stem from electrical or code changes)

## Test Encoder Funcionality

### Using shephard

```c++
#include "Test.h"
#include "System.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("Encoder Test:");
}

long positionLeft = -999;
long positionRight = -999;

void loop()
{   
    shephard.activity();
    long newLeft, newRight;
    newLeft = shephard.chassis.left.get_pos();
    newRight = shephard.chassis.right.get_pos();
    if (newLeft != positionLeft || newRight != positionRight)
    {
        Serial.print("Left = ");
        Serial.print(newLeft);
        Serial.print(", Right = ");
        Serial.print(newRight);
        Serial.println();
        positionLeft = newLeft;
        positionRight = newRight;
    }
}
```

### Without Shephard

```c++
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#define ENCODER_RIGHT_PIN1 8
#define ENCODER_RIGHT_PIN2 11
#define ENCODER_LEFT_PIN1 5
#define ENCODER_LEFT_PIN2 7

Encoder knobLeft(ENCODER_LEFT_PIN1, ENCODER_LEFT_PIN2);
Encoder knobRight(ENCODER_RIGHT_PIN1, ENCODER_RIGHT_PIN2);

void setup() {
  Serial.begin(9600);
  Serial.println("TwoKnobs Encoder Test:");
}

long positionLeft  = -999;
long positionRight = -999;

void loop() {
  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newLeft != positionLeft || newRight != positionRight) {
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
    positionLeft = newLeft;
    positionRight = newRight;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
    knobRight.write(0);
  }
}
```

## Test Motor Funcionality

### With Motor Class

```c++
#include "Test.h"
#include "../Actuators/Motor.h"

#define RIGHT_BACKWARD_PIN 3
#define RIGHT_FORWARD_PIN 4
#define LEFT_BACKWARD_PIN 9
#define LEFT_FORWARD_PIN 10

#define ENCODER_RIGHT_PIN1 8
#define ENCODER_RIGHT_PIN2 11
#define ENCODER_LEFT_PIN1 5
#define ENCODER_LEFT_PIN2 7

Motor motor_l(LEFT_FORWARD_PIN, 
              LEFT_BACKWARD_PIN,
              ENCODER_LEFT_PIN1,
              ENCODER_LEFT_PIN2);

Motor motor_r(RIGHT_FORWARD_PIN, 
              RIGHT_BACKWARD_PIN,
              ENCODER_RIGHT_PIN1,
              ENCODER_RIGHT_PIN2);

int i = 0;
bool debug = false;

void setup(){
    Serial.begin(9600);
    delay(2000);
    motor_r.ccw(90, 50);
    motor_l.ccw(90, 50);
}
void loop(void){
    if (i%100000000 == 0){
        debug  = true;
    } else {
        debug = false;
    }
    motor_l.activity(true);
    motor_r.activity(true);
}
```

## Claw

### With Shephard

```c++
#include "Test.h"
#include "System.h"


unsigned start;

void setup(){
    Serial.begin(9600);
    Serial.println("Currently doing some testing...");
    delay(1000);
    start = millis();
}
void loop(void){
    shephard.activity();
    uint32_t tick = millis();
    Serial.println(tick);
    if (tick - 5000 > start){
        shephard.claw.close();
    } else if (tick - 4000 > start){
        shephard.chassis.move_forward(5, 100);
    } else if (tick - 3000 > start){
        shephard.claw.open();
    }
}
```

### Encoder Funcionality

```c++
unsigned long start; 
void setup(){
    Serial.begin(9600);
    while(!Serial);
    Serial.println("Starting");
    start = millis();
}

void loop(void){
  Serial.println(millis() - start);
  if (millis() - start < 500) {
    Serial.println("test");
    shephard.chassis.move_forward(20, 150);
  }
  shephard.activity();
  delay(100);
}   
```