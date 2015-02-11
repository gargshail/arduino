int led = 9;
void setup() {  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (255.0 / 1024.0);
  Serial.println(voltage);
  analogWrite(led, voltage);
}




