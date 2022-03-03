
#include "Arduino.h"
#include "UltrasonicSensor.h"

uint8_t UltrasonicSensor::num_ultrasonic_sensors          = 0;
volatile int UltrasonicSensor::trigger_time_count         = 0;

float UltrasonicSensor::read()
{
  return echo_duration / 58;
}

void UltrasonicSensor::initialize(){
  timer.begin(UltrasonicSensor::timerISR, timer_us);
  attachInterrupt(0, UltrasonicSensor::echo_interrupt, CHANGE); // TODO select interrupt ID better
}


void UltrasonicSensor::timerISR()
{
    trigger_pulse();
}


void UltrasonicSensor::trigger_pulse()
{
      static volatile int state = 0;                 // State machine variable

      if (!(--trigger_time_count))                   // Count to 200mS
      {                                              // Time out - Initiate trigger pulse
         trigger_time_count = tick_counts;           // Reload
         state = 1;                                  // Changing to state 1 initiates a pulse
      }
    
      switch(state)                                  // State machine handles delivery of trigger pulse
      {
        case 0:                                      // Normal state does nothing
          break;
        
        case 1:                                      // Initiate pulse
          for (int i=0; i<num_ultrasonic_sensors; ++i){
            digitalWrite(ultrasonic_sensors[i]->trig_pin, HIGH);  // Set the trigger output high
          }
          state = 2;                                 // and set state to 2
          break;
        
        case 2:                                      // Complete the pulse
        default:      
          for (int i=0; i<num_ultrasonic_sensors; ++i){
            digitalWrite(ultrasonic_sensors[i]->trig_pin, LOW);  // Set the trigger output high
          }
          state = 0;                                // and return state to normal 0
          break;
     }
}

// --------------------------
// echo_interrupt() External interrupt from HC-SR04 echo signal. 
// Called every time the echo signal changes state.
//
// Note: this routine does not handle the case where the timer
//       counter overflows which will result in the occassional error.
// --------------------------
void UltrasonicSensor::echo_interrupt()
{ 
  for (int i=0; i<num_ultrasonic_sensors; ++i){
    UltrasonicSensor uss = *ultrasonic_sensors[i];
    switch (digitalRead(uss.echo_pin))                    // Test to see if the signal is high or low
    {
      case HIGH:                                          // High so must be the start of the echo pulse
        uss.echo_end = 0;                                 // Clear the end time
        uss.echo_start = micros();                        // Save the start time
        break;
        
      case LOW:                                           // Low so must be the end of hte echo pulse
        uss.echo_end = micros();                          // Save the end time
        uss.echo_duration = uss.echo_end - uss.echo_start;// Calculate the pulse duration
        break;
    }
  }
}