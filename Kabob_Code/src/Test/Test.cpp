#include "Test.h"

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