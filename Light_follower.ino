#include <Servo.h>
unsigned long leftPin = A0;
unsigned long rightPin = A5;
unsigned long interval = 500;
unsigned long begin = 0;
const int servo_pin = 9;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  servo.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float left_pin_value = (analogRead(leftPin));
  float right_pin_value = (analogRead(rightPin));

  float temp_range_left = ((left_pin_value - right_pin_value)/(left_pin_value + right_pin_value));
  float degree = 180*(1-temp_range_left);

  unsigned long current = millis();
  if(current - begin >= interval){
    begin = begin + interval;
    Serial.print("Left Pin Degree = ");
    Serial.println(temp_range_left); 
  }
  servo.write(degree-90);
}
