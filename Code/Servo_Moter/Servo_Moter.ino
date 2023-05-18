// #19 Servo Motor
#include<Servo.h>

// Variables
int pos = 0;
Servo servo_9;

void setup() {
  // put your setup code here, to run once:
  servo_9.attach(9,500,2500);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos=0;pos<180;pos++){
    servo_9.write(pos);
    delay(5);
  }

  for (pos=180;pos>=0;pos--){
    servo_9.write(pos);
    delay(5);
  }
}
