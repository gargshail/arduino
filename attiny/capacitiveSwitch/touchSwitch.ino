#include <CapacitiveSensor.h>
 
 
//pin 1 is sensor pin
// place  a high value resistor between pins 0 & 1
// extend a wire from pin 1. That will act as touch switch
// add a LED on pin 3 to ground. You will be adding a relay if you are controlling a large load.
CapacitiveSensor   sensor = CapacitiveSensor(0,1); 

unsigned long lastTapped; 

boolean switchOn = false;
 
void setup()                    
{
    pinMode(3, OUTPUT);
    digitalWrite(3, true);
    lastTapped=millis();
}
 
void loop()                    
{
 
    if (sensor.capacitiveSensor(30) > 50) {
      if ((millis()-lastTapped)>500) {
      switchOn=!switchOn;
      lastTapped=millis();
      }
    }
    digitalWrite(3, switchOn);
 
    delay(500);                       // sampling delay 
}

