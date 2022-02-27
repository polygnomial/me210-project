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
