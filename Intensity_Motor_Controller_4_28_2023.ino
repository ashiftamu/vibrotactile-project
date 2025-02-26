#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(9600);
  Serial.println("DRV test");
  drv.begin();
    
  // Set Real-Time Playback mode
  drv.setMode(DRV2605_MODE_REALTIME);
}

uint16_t timeon = 3000; //milliseconds
uint16_t timeoff = 1000;
uint8_t intensity = 24; // intensity ranges from 0-127

void loop() {

  while(1) {
    drv.setRealtimeValue(intensity);
    delay(timeon);
    drv.setRealtimeValue(0);
    delay(timeoff);
  }
    
  
  
}
