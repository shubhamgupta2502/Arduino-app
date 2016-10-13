#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readdata;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  while (BT.available()){  
  delay(10); 
  char c = BT.read(); 
  readdata += c; 
  } 
  if (readdata.length() > 0) {
    Serial.println(readdata);

  if(readdata == "forward")
  {
    digitalWrite(2, HIGH);
    digitalWrite (3, LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(100);
  }

  else if(readdata == "reverse")
  {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5,HIGH);
    delay(100);
  }

  else if (readdata == "right")
  {
    digitalWrite (2,HIGH);
    digitalWrite (3,LOW);
    digitalWrite (4,LOW);
    digitalWrite (5,LOW);
    delay (100);
   
  }

 else if ( readdata == "left")
 {
   digitalWrite (2, LOW);
   digitalWrite (3, LOW);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   delay (100);
 }

 else if (readdata == "right ninety")
  {
    digitalWrite (2,HIGH);
    digitalWrite (3,LOW);
    digitalWrite (4,LOW);
    digitalWrite (5,HIGH);
    delay (100);
   
  }

  else if (readdata == "left ninety")
  {
    digitalWrite (2,LOW);
    digitalWrite (3,HIGH);
    digitalWrite (4,HIGH);
    digitalWrite (5,LOW);
    delay (100);
   
  }

 else if (readdata == "stop")
 {
   digitalWrite (2, LOW);
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   delay (100);
 }
   else if (readdata == "buzz")
 {
   analogWrite (9,255);
   delay(1000);
   analogWrite(9,0);
 }
 else if (readdata == "red")
 {
   digitalWrite (13,HIGH);
   delay(1000);
   digitalWrite(13,LOW);
 }
else if (readdata == "green")
 {
   analogWrite (6,255);
   delay(1000);
   analogWrite(6,0);
 }
else if (readdata == "blue")
 {
   analogWrite (10,255);
   delay(1000);
   analogWrite(10,0);
 }
  
readdata="";}}
