#include <SoftwareSerial.h>
SoftwareSerial dbgSerial(10, 11); // RX, TX
int count = 0;
void setup()
{
 
  dbgSerial.begin(9600);  
  dbgSerial.println("Testing");
  
}
void loop()
{
  dbgSerial.print(count++);
  delay(1000);
}
