// #include "Test.h"
// #include <Arduino.h>
// #include <Metro.h>

// // int outputPin = 19;
// // int inputPin = A1;
// int PIN_SIGNAL_IN = 19;
// volatile uint8_t outputState = false;
// IntervalTimer myTimer;
// IntervalTimer freqTimer;
// int test = 400;
// int count = 0;
// int timertime = 1000000;

// void setFreq(void);
// void CountFallingEdges(void);
// void announceF(void);

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   while(!Serial);
//   Serial.println("Hello, world!");
//   // Initialize pins
//   pinMode(PIN_SIGNAL_IN, INPUT);
//   //Start output at high
// //   digitalWrite(outputPin, HIGH);
// //   myTimer.begin(setFreq, test);
//   freqTimer.begin(announceF,timertime);
//   attachInterrupt(digitalPinToInterrupt(PIN_SIGNAL_IN), CountFallingEdges, FALLING);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// //   noInterrupts();
// //   test = map(analogRead(inputPin), 0, 1023, 40, 10000);

// //   interrupts();
// //   myTimer.update(test);
// }

// // void setFreq() {
// //   outputState = !outputState;
// //   digitalWrite(outputPin, outputState);
// // }

// void CountFallingEdges() {
//   count ++;
// }

// void announceF() {
//   Serial.println(count);
//   // Serial.println((count/timertime));
//   count=0;
// }

#include <Arduino.h>
#include <Metro.h>

int outputPin = 17;
int inputPin = A1;
int PIN_SIGNAL_IN = 20;
volatile uint8_t outputState = false;
IntervalTimer myTimer;
IntervalTimer freqTimer;
int test = 400;
int count = 0;
int timertime = 1000000;

void setFreq(void);
void CountFallingEdges(void);
void announceF(void);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Hello, world!");
  // Initialize pins
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  //Start output at high
  digitalWrite(outputPin, HIGH);
  myTimer.begin(setFreq, test);
  freqTimer.begin(announceF,timertime);
  attachInterrupt(digitalPinToInterrupt(PIN_SIGNAL_IN), CountFallingEdges, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  noInterrupts();
  test = map(analogRead(inputPin), 0, 1023, 40, 10000);

  interrupts();
  myTimer.update(test);
}

void setFreq() {
  outputState = !outputState;
  digitalWrite(outputPin, outputState);
}

void CountFallingEdges() {
  count ++;
}

void announceF() {
  Serial.println(count);
  // Serial.println((count/timertime));
  count=0;
}

