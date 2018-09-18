/*
exocet supercharger bypass controller

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  myservo.attach(2); 
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    myservo.write(150);              // tell servo to go to position in variable 'pos'
    delay(100);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    myservo.write(40);              // tell servo to go to position in variable 'pos'
    delay(100);
  }
}
