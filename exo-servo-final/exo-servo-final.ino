/*
exocet supercharger bypass controller

*/

const int inputPin = 7;     // input pin from Megasquirt
const int ledPin =  13;      // the number of the LED pin

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int throttleState = 0;         // variable for reading the pushbutton status
const int angleOff = 150;
const int angleOn = 40;

void setup() {
  myservo.attach(2); 
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
}

void loop() {
  throttleState = digitalRead(inputPin);

  if (throttleState == HIGH) {
    digitalWrite(ledPin, HIGH);
    myservo.write(angleOff);              
    delay(100);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    myservo.write(angleOn);              
    delay(100);
  }
}
