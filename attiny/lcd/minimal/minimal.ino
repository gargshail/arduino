#include <PCD8544.h>


/*

               |1--  --8| -- VCC
          rst  |2      7|  clk
     pot-> A2  |3      6|  din
       GND--   |4------5|  dc
       

  LCD - CE -->gnd
  LCD - VCC--> VCC
  LCD - GND --> GND
  
  VCC GND voltage is 3V.

*/


static const byte sensorPin = A2;


// The dimensions of the LCD (in pixels)...
static const byte LCD_WIDTH = 84;
static const byte LCD_HEIGHT = 48;


static PCD8544 lcd (2,1,0,3,6); // goes to (clk, din, dc, rst, ce) of the LCD. Used non-existent output pin 6 for CE. 
// Digital IO pin numbers are different from physical pin numbers.   See README.md
// it is possible to save one attiny  pin by connecting  CE of LCD to ground. It leaves ping 4 and 5 for other purpose. Check if pin 5 can be used. It is RESET pin


void setup() {
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);

}


void loop() {

  
  int v = analogRead(sensorPin);
  lcd.setCursor(0, 0);
  lcd.print("Value: ");
  lcd.print(v);
  lcd.print(" ");
  delay(200);
}


