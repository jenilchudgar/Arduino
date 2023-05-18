// #17 LCD
#include<LiquidCrystal.h>

// Variables
LiquidCrystal LCD(3,12,4,5,6,7);

void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  LCD.begin(16, 2);

  Serial.print("Program Ended.");
}

void loop() {
  // put your main code here, to run repeatedly:
  LCD.setCursor(0, 0);
  LCD.print("Hello World!");

  LCD.setCursor(0, 1);
  LCD.print("By:- Jenil");
}
