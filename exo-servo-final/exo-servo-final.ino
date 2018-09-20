/*
exocet supercharger bypass controller

*/

const int inputPin = 7;     // input pin from Megasquirt
const int servoPin = 2;
#include <Servo.h>

Servo myservo; 

int throttleState = 0;         
const int angleOff = 150;
const int angleOn = 40;

void setup() {
  myservo.attach(servoPin); 
  pinMode(inputPin, INPUT_PULLUP);
}

void loop() {
  throttleState = digitalRead(inputPin);

  if (throttleState == HIGH) {
    myservo.write(angleOff);              
    delay(100);
  } else {
    myservo.write(angleOn);              
    delay(100);
  }
}
