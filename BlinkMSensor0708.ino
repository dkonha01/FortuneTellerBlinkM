
//#include "mpr121.h"
#include <Wire.h>
#include "Wire.h"
#include "BlinkM_funcs.h"


int ledPin = 13;      // select the pin for the LED
int sensorValue = 137;  // variable to store the value coming from the sensor
int triggerValue = 0;
int blinkm_addr = 0;


int sensorPin = A0;
int sensorPinValue = 0;

int redVal = 0;
int grnVal = 0;
int bluVal = 0;

int LEDState = 0;   

void setup() {

  Serial.begin(9600);
  Wire.begin();
  pinMode(ledPin, OUTPUT);

  BlinkM_beginWithPower();
  BlinkM_stopScript(blinkm_addr);  // turn off startup script

}

void loop() {
readTouchInputs();
    
}

void readTouchInputs()
{
   BlinkM_fadeToHSB( blinkm_addr, 87+rand(), sensorValue , sensorValue);
    delay(97); 

    sensorPinValue = analogRead(sensorPin); 
    Serial.print(sensorPinValue);

   if (sensorPinValue > 43) {

       for (int x=0; x< 69; x++){
       BlinkM_setRGB(blinkm_addr, 255,0,0);
       delay(70);
       BlinkM_setRGB(blinkm_addr,0,0,0);
       delay(70);
       }
   }

   else {

        BlinkM_fadeToHSB( blinkm_addr, 87+rand(), sensorValue , sensorValue);
        delay(97);
    
   }
    delay(97); 

}


void set_register(int address, unsigned char r, unsigned char v){
    Wire.beginTransmission(address);
    Wire.write(r);
    Wire.write(v);
    Wire.endTransmission();
}
