// #23 Servo Moter with Joystick
#include<Servo.h>

// Variables
int x_axis = A0;

int x;
int y;
int click;

Servo servo;

// Joystick range
const int joystickMin = 0;
const int joystickMax = 1023;

// Servo angle range
const int servoMinAngle = 0;
const int servoMaxAngle = 180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Define Servo Moter
  servo.attach(9);

  // Define other components
  pinMode(x_axis,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read Joystick
  x = analogRead(x_axis);

  // Serial.println(String(x));
  delay(10);

  // Map the values for Servo Moter
  int servoAngleX = map(x, joystickMin, joystickMax, servoMinAngle, servoMaxAngle);

  // Control the servo
  servo.write(servoAngleX);

  Serial.println(servoAngleX);

  delay(100);
}
