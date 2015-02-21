# 5510 LCD with  attiny

## Connections

	AtTiny Pin -  LCD pin
	VCC (8)  -  VCC (6)
	PB2(7)  -   CLK (5)
	PB1 (6) - DIN (4)
 	PB0 (5) - DC (3)
	GND (4) - GND(8), CE(2), Light(7)
	PB4 (3)	- 
	PB3 (2) - RST(1)
	PB5 (1) - 
	

Any change in connection need to reflect in this LCD configuration line.
static PCD8544 lcd (2,1,0,3,6); 


LCD pin configuration may be different.  Also check if Light is turned on by connection to VCC or Gnd.

Power this circuit with 3V supply. It will not work above 3V. I've tried it using three AAA batteries (4.5v)

Digital IO pin 4 is available for use. This base circuit can be used to  attach one sensor. 

