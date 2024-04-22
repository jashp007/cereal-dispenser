//UPDATED SLAVE
#include <Servo.h>

Servo myservo;  // Create servo object to control a servo
const int green=7;
const int red=5;
const int blue=6;

void setup() {
  myservo.attach(9);  // Attach the servo on pin 9 to the servo object
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

 
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {digitalWrite(blue, HIGH);
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the incoming byte
   
    if (command == 'H') {
       digitalWrite(blue, LOW);
      digitalWrite(green, HIGH);
      myservo.write(900);
      // Move servo to half position
     
      delay(1000);  // Wait a bit for the action to complete
    digitalWrite(red, LOW);

     
      myservo.write(0);  // Return servo to initial position
     
     digitalWrite(green, LOW);
     digitalWrite(red, HIGH);
      delay(250);
      digitalWrite(red, LOW);

       
    } else if (command == 'F') {
      digitalWrite(blue, LOW);
      digitalWrite(green, HIGH);
      myservo.write(450);  // Move servo to full position
      delay(1000);  // Wait a bit for the action to complete
      myservo.write(0);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
    }
  }
}