#include "Test.h"

void setup(){
    Serial.begin(9600);
    Serial.println("Starting");
<<<<<<< Updated upstream
}

void loop(void){
  Serial.println("ah");
  shephard.chassis.move_forward_at_speed(200);
  delay(1000);
=======
    start = millis();
    shephard.chassis.turn_cw(90, 100);
}

void loop(void){
  Serial.println(millis() - start);
  if (millis() - start < 500) {
    Serial.println("test");
    // shephard.chassis.move_forward(20, 150);
  }
  shephard.activity();
  delay(100);
>>>>>>> Stashed changes
}   