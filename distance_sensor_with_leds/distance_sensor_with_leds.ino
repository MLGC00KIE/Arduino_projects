// red led in pin 3
// orange led in pin 4
// green led in pin 5

// trigger from ultrasonic sensor in pin 9
// echo from ultrasonic sensor in pin 10

//Libraries 
#include <Wire.h>  
#include <NewPing.h>

int closeLed = 3;
int mediumLed = 4;k
int farLed = 5;

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 300
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
  Serial.begin(9600); // Starts the serial communication
  pinMode(closeLed, OUTPUT);
  pinMode(mediumLed, OUTPUT);
  pinMode(farLed, OUTPUT);
  
}

void loop(){
unsigned int distance = sonar.ping_cm();
  delay(300);
  Serial.println(distance);

  if(distance < 10) {
    digitalWrite(closeLed, HIGH);
    digitalWrite(mediumLed, LOW);
    digitalWrite(farLed, LOW);
  }

  if(distance >= 10 && distance < 20) {
    digitalWrite(closeLed, HIGH);
    digitalWrite(mediumLed, HIGH);
    digitalWrite(farLed, LOW);
  }

  if(distance >= 20) {
    digitalWrite(closeLed, HIGH);
    digitalWrite(mediumLed, HIGH);
    digitalWrite(farLed, HIGH);
  }
}
