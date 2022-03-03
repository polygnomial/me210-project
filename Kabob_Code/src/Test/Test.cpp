#include "Test.h"
#include "Arduino.h"

#define trigpin 7
#define echopin 8

unsigned long state_time;
unsigned long serial_time; 
unsigned long curr_time;
unsigned long zone_time;

#define PRINT_FREQUENCY                 1 // hz
#define MILLISECONDS(time)({time * 1000;})

long duration; // variable for the duration of sound wave travel
int distance; 

void setup(){
    Serial.begin(9600);
    Serial.println("Starting...");
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);
    curr_time = millis();
    serial_time = millis();
}

void loop(void){
  unsigned long t = millis();
  digitalWrite(trigpin, LOW);
  if (t > 0.01) {
    digitalWrite(trigpin, HIGH);
  } else if (t > 0.02) {
    digitalWrite(trigpin, LOW);
  }
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor

  if (distance < 15) {
    Serial.println("ROBOT DETECTED");
  }

  if (t - serial_time > MILLISECONDS(1/PRINT_FREQUENCY) ){

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    serial_time = t;
  }
}   




