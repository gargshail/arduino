#include <IRremote.h>
int enablepin = 11;
int enablepin1 = 6;
int in = 4;
int intwo = 7;
int in11 = 5;
int in22 = 8;
int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;
int lastcom = 0;

const int  fwd  = 0x20DFA25D ;
const int bwd = 0x20DF629D;
const int right = 0x20DF12ED;
const int left = 0x20DFE21D;
const int stp = 0x20DF22DD;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}




void loop() {
  int com = 0;
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value != 0xFFFFFFFF){      
      com = results.value;
    }
    else {
      com = lastcom;
    }
    switch (com) {
    case fwd :          
     forward();
      break;
    case bwd :          
      backward(); 
      break;
    case right :         
      digitalWrite(in,LOW);
      digitalWrite(intwo,HIGH);
      analogWrite(enablepin,100);
      digitalWrite(in11,HIGH);
      digitalWrite(in22,LOW);
      analogWrite(enablepin1,250);
      break;
    case left :
      digitalWrite(in,LOW);
      digitalWrite(intwo,HIGH);
      analogWrite(enablepin,100);
      digitalWrite(in11,LOW);
      digitalWrite(in22,HIGH);
      analogWrite(enablepin1,250);
      break;
    default:
      digitalWrite(in,HIGH);
      digitalWrite(intwo,HIGH);
      analogWrite(enablepin,0);
      digitalWrite(in22,LOW);
      digitalWrite(in11,LOW); 
      analogWrite(enablepin1,0); 
      break;
    }
    lastcom = com;

    //dump(&results);
    irrecv.resume(); // Receive the next value
  }  

}
void forward () {
    digitalWrite(in,LOW);
      digitalWrite(intwo,HIGH);
      analogWrite(enablepin,100);
}

void backward() {
      digitalWrite(in,HIGH);
      digitalWrite(intwo,LOW);
      analogWrite(enablepin,100);
}
