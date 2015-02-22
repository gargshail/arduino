#Programming AtTiny 

I've used following ways to program AtTiny

#Use an Arduino as a programmer

1. Files->Examples->Arduino ISP
use six different colored wires to connect arduino pins to breadboard

select arduino ISP from  Tools->Programmer->Arduino ISP

prepare breadboard as described in image. 



#Use usbasp programmer



# Pin Functions


	
## Digital I/O

	IC pin	PinNumberInProgram
	5	0
	6	1
	7	2
	2	3
	3	4
	1	5(only usable if fuse is burned otherwise acts as RESET pin.). In general you can assume that only 5 digital I/O pins are available.



## Analog read 

	
	IC pin	PinNameInProgram
	7	A1
	2	A3
	3	A2
	

	pinMode(A1, INPUT);
	analogRead(A1); // returns value between 0 to 1023 

## Analog write (PWM)
	
only two pins supports PWM output using analogWrite()


	IC pin	PinNameInProgram
	5	0
	6	1

usage
	
	pinMode(0, OUTPUT); // remember to connect part on relevant physical pin number as described in above table.
	analogWrite(0, 200); // write value can be range of  0 to 255
	

	use following to map analogRead value to map to value suitable for analogWrite. 
	analogWrite(map(val, 0,1023, 0,255));
		

