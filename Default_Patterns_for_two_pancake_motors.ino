#include <Adafruit_DRV2605.h>

#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include "Wire.h"

#define TCAADDR 0x70
Adafruit_DRV2605 drv0;
Adafruit_DRV2605 drv1;
void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

void setup() {
  while (!Serial);
    delay(1000);

    Wire.begin();
    
    Serial.begin(115200);
    Serial.println("\nTCAScanner ready!");
    
    for (uint8_t t=0; t<8; t++) {
      tcaselect(t);
      Serial.print("TCA Port #"); Serial.println(t);

      for (uint8_t addr = 0; addr<=127; addr++) {
        if (addr == TCAADDR) continue;

        Wire.beginTransmission(addr);
        if (!Wire.endTransmission()) {
          Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
          
          
        }
      }
    }

        tcaselect(0);
        Serial.println("Made it here");
            drv0.selectLibrary(1);
            drv0.setMode(DRV2605_MODE_INTTRIG);
          tcaselect(1);
            drv1.selectLibrary(1);
            drv1.setMode(DRV2605_MODE_INTTRIG);
          
          
   Serial.println("Adafruit DRV2605 Basic test");
  

  
 

  
  
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  
  


    Serial.println("\ndone");

}
uint8_t effect = 1;
void loop() {
  // put your main code here, to run repeatedly:
   tcaselect(0);
  drv0.setWaveform(0, effect);  // play effect 
  drv0.setWaveform(1, 0);       // end waveform
  drv0.go();
  tcaselect(1);
  drv1.setWaveform(0, effect);  // play effect 
  drv1.setWaveform(1, 0);       // end waveform
  drv1.go();

  // play the effect!
  
  


  // wait a bit
  delay(500);

  effect++;
  if (effect > 117) effect = 1;

}
