/*

               |1--  --8| -- VCC
               |2      7|  
     pot-> A2  |3      6|
       GND--   |4------5|  LED -- to --GND



*/

int led1 = 0;

int input = A2;
void setup() {
  pinMode(led1, OUTPUT);

  pinMode(input, INPUT);
}

void loop() {

  int val = analogRead(input);
  
  long brightness = map(val, 0,1023,0,255);
 
  analogWrite(led1, brightness);
  delay(50);
}
