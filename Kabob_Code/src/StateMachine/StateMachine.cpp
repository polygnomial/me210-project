#include "StateMachine.h"

States_t state;

States_r state2;

unsigned long state_time;
unsigned long serial_time; 
uint8_t servoPin = 6;
uint8_t servoPos = 0;


void setup() {
  delayMicroseconds(2000);
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  //timer 
  serial_time = millis();
  state_time = millis();

  state = STATE_NAV_TARGET;
  state2 = STATE_1;
  
  Serial.println("Setup Complete!");
}

void loop() {
  checkGlobalEvents();

  switch(state) {
    case STATE_IDLE:
      shephard.chassis.stop();
      break;
    case STATE_LOAD:
      handleLoadState();
      break;
    case STATE_NAV_TARGET:
      // handleNavTargetState();
      break;
    case STATE_UNLOAD:
      shephard.chassis.move_backward(100);
      break;
    case STATE_NAV_LOAD:
      break;
    default:
      Serial.println("What is this I do not even...");
  }

  switch(state2) {
    case STATE_1:
      if (state==STATE_NAV_TARGET) {
        LineFollow();
        if (TestforT1()) RespToT1();
      }
      break;
    case STATE_2:
      LineFollow();
      break;
    case STATE_3:
      handleNavTargetState();
      break;
    case STATE_4:
      shephard.chassis.stop();
      break;
    case STATE_wait:
      break;
    default:
      Serial.println("What is this I do not even...");
  }

  unsigned long current_millis = millis();
  if (current_millis - serial_time > MILLISECONDS(1/PRINT_FREQUENCY) ){
    Serial.println("One Secound update: ");
    Serial.println("left " + String(shephard.sensors.line.left.readAnalog()));
    Serial.println("right " + String(shephard.sensors.line.right.readAnalog()));
    Serial.println("center left " + String(shephard.sensors.line.center_left.readAnalog()));
    Serial.println("center middle " + String(shephard.sensors.line.center_middle.readAnalog()));
    Serial.println("center right " + String(shephard.sensors.line.center_right.readAnalog()));
    serial_time = current_millis;
  }

}

void handleLoadState(void) {
  int timeInState = millis() - state_time;
  if (timeInState < 1500) {
    shephard.claw.open(); 
  } else if (timeInState > 3000 && timeInState < 5000) {
    shephard.claw.close(); 
  } else if (timeInState > 5000) {
    changeStateTo(STATE_NAV_TARGET);
  }
}

void handleNavTargetState(void){
  shephard.chassis.move_forward(200);
  if (millis() - state_time> 5000) {
    changeStateTo(STATE_IDLE);
  }       
}

void changeStateTo(States_t s) {
  state = s;
  state_time = millis();
  Serial.println("New state = " + s);
}

void checkGlobalEvents(void) {
  if (TestForKey()) RespToKey();
  //DArcy's tests
  // if (LineFollow()) RespToLine();
  // if (TestforT1()) RespToT1();
}

uint8_t TestforT1(void) {
  if (shephard.sensors.line.left.readAnalog() > 100) {
    return 1;
  } else {
    return 0;
  }
}
 
void LineFollow(void) {
  analogWrite(3,0);
  if (shephard.sensors.line.right.readAnalog() > 900||shephard.sensors.line.left.readAnalog() > 800) {
    // hole avoidance
    analogWrite(9,0);
    analogWrite(4, 0);
    analogWrite(10, 0); 
    state = STATE_IDLE;
    state2=STATE_4;

  // } else if (shephard.sensors.line.left.readAnalog() > 900) {
  //   //hole avoidance
  //   analogWrite(9,0);
  //   analogWrite(4, 0);
  //   analogWrite(10, 0); 
  } else if (shephard.sensors.line.center_middle.readAnalog() > 100) {
    analogWrite(4, 100);
    analogWrite(9,0);
    analogWrite(10, 100); 
  } else if (shephard.sensors.line.center_left.readAnalog() > 100) {
    analogWrite(9,0);
    analogWrite(4, 185);
    analogWrite(10, 100);
  } else if (shephard.sensors.line.center_right.readAnalog() > 100) {
    analogWrite(9,0);
    analogWrite(4, 100);
    analogWrite(10, 140);
  } else {
    shephard.chassis.stop();
    analogWrite(9,0);
    analogWrite(4, 0);
    analogWrite(10, 0); 
  }
}

void RespToT1(void) {
  turn1sequence();
   
  // shephard.chassis.forward(80);
  // if (current_millis - serial_time > MILLISECONDS(1/PRINT_FREQUENCY) ){
  //   Serial.println("Line test");
  // }
}

//untested
void turn1sequence(void) {
  while (shephard.sensors.line.center_left.readAnalog() < 100) {
    LineFollow();
  }
  Serial.println("Yeehaw");
  while (shephard.sensors.line.right.readAnalog() < 100) {
    //Pivot(); PUT THIS FUNCTION IN]
    analogWrite(4, 100);
    analogWrite(9,100);
    analogWrite(10,0);
    analogWrite(3,0);
  }
  Serial.println("Made it here");
  while (shephard.sensors.line.center_right.readAnalog() < 100 && shephard.sensors.line.center_left.readAnalog() <100 && shephard.sensors.line.center_middle.readAnalog() < 100) {
    //Pivot(); PUT THIS FUNCTION IN
    analogWrite(4, 100);
    analogWrite(9,100);
    // analogWrite(4, 0);
    // analogWrite(9,0);
    analogWrite(3,0);
    analogWrite(10,0);
    delayMicroseconds(500);
  } 
  // while(shephard.sensors.line.left.readAnalog()<100&&shephard.sensors.line.right.readAnalog()<100) {
  //   analogWrite(3, 100);
  //   analogWrite(9,100);
  //   analogWrite(10, 0);
  //   analogWrite(4,0);
  // }
  // Serial.println("Yeah baby");

  state2 = STATE_2;
  LineFollow();
  Serial.println("whoop");
}

uint8_t TestForKey(void) {
  uint8_t KeyEventOccurred;
  KeyEventOccurred = Serial.available();
  return KeyEventOccurred;
}

void RespToKey(void) {
  uint8_t theKey;
  theKey = Serial.read();
  Serial.print(theKey);
  Serial.print(", ASCII=");
  Serial.println(theKey, HEX);

  switch(theKey) {
    case ' ': 
      state = STATE_IDLE;
      break;
    default:
      break;
  }
}