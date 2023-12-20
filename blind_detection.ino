#include <Servo.h>

Servo servo1;

const int x_key = A2; 
const int y_key = A3; 
const int trigPin = 9;
const int echoPin = 10;

int x_pos;
int y_pos;
int servo1_pin = 8;
int initial_position = 90;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

 
  servo1.attach(servo1_pin);
  servo1.write(initial_position);
  pinMode(x_key, INPUT);
  pinMode(y_key, INPUT);

 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  x_pos = analogRead(x_key);
  y_pos = analogRead(y_key);

 
  if (x_pos < 300) {
    if (initial_position < 10) {
     
    } else {
      initial_position = initial_position - 1;
      servo1.write(initial_position);
      delay(10);
    }
  }

  if (x_pos > 700) {
    if (initial_position > 180) {
      
    } else {
      initial_position = initial_position + 1;
      servo1.write(initial_position);
      delay(10);
    }
  }

 
  int mapped_y = map(y_pos, 0, 1023, 10, 170); 
  servo1.write(mapped_y);

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Servo Position: ");
  Serial.print(mapped_y);
  Serial.print(" | Joystick Positions: x=");
  Serial.print(x_pos);
  Serial.print(" y=");
  Serial.println(y_pos);
}
