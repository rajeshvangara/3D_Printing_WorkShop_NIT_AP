#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

char data1;
const int M1 = 13;
const int M2 = 12;
const int M3 = 14;
const int M4 = 27;

void setup() {
  // put your setup code here, to run once:
pinMode(M1,OUTPUT);
pinMode(M2,OUTPUT);
pinMode(M3,OUTPUT);
pinMode(M4,OUTPUT);
pinMode(2, OUTPUT);

SerialBT.begin("toy_car");
Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:
if (SerialBT.available()) {
     data1 = SerialBT.read();
     //Serial.println(data1); 
     digitalWrite(2,HIGH);  
  }
if ( data1 == 'u'){
  digitalWrite(M1,HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4,LOW);
  Serial.println("Forward");
}
else if( data1 == 'd'){
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3,LOW);
  digitalWrite(M4, HIGH);
  Serial.println("Backward");
}
else if (data1 == 'r'){
  digitalWrite(M1, HIGH);/// Left Motor
  digitalWrite(M2, LOW);///
  digitalWrite(M3, LOW);//// Right Motor
  digitalWrite(M4, HIGH);
  Serial.println("Right");
}
else if (data1 == 'l'){
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M4, LOW);
  Serial.println("Left");
}
else if (data1 == '0'){
   digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4, LOW);
  Serial.println("stop");
}

  delay(10);
digitalWrite(2,LOW);
  
}
