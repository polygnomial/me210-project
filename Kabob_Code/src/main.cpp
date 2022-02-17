#include <Arduino.h>

int outputPinF1 = 3; 
int outputPinB1 = 4;  
int outputPinF2 = 9;
int outputPinB2 = 10;
int servoPin = 6;
int state = HIGH; //low is bwds, high is fwds

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Hello, world!");
  // Initialize pins
  pinMode(inputPin, INPUT);
  pinMode(outputPinF1,OUTPUT);
  pinMode(outputPinB1,OUTPUT);
  pinMode(outputPinF2,OUTPUT);
  pinMode(outputPinB2,OUTPUT);
  pinMode(servoPin,OUTPUT);
  // Set all pins to low to start
  analogWrite(outputPinB1, LOW);
  analogWrite(outputPinB2, LOW);
  analogWrite(outputPinF1, LOW);
  analogWrite(outputPinF2, LOW);  
  analogWrite(servoPin, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (state == HIGH) {
    analogWrite(outputPinF1, 255); //for now just set to max output
    analogWrite(outputPinF2, 255);
    analogWrite(outputPinB1, 0);
    analogWrite(outputPinB2, 0);
    analogWrite(servoPin, 50);
  } else if (state == LOW) {
    analogWrite(outputPinB1, 255); //for now just set to max output
    analogWrite(outputPinB2, 255);
    analogWrite(outputPinF1, 0);
    analogWrite(outputPinF2, 0);
    analogWrite(servoPin, 0);
  }
}
  
