// #18 LCD With Ultrasonic Sensor

#include <LiquidCrystal.h>

// Variables
LiquidCrystal LCD(3, 12, 4, 5, 6, 7);

int echoPin = 10;
int triggerPin = 9;
int buzzer = 11;


void setup() {
  Serial.begin(9600);

  // Initialize the Ultrasonic Sensor
  pinMode(echoPin,INPUT);
  pinMode(triggerPin,OUTPUT);

  // Initialize the Buzzer
  pinMode(buzzer,OUTPUT);
  
  // Initialize the LCD
  LCD.begin(16, 2);

  // LCD Clear
  LCD.clear();

  // Delay
  delaySeconds(1);

  // Part - 1
  textDisplay_intro();  
  delaySeconds(3);
  // LCD Clear
  LCD.clear();

  // Part - 2
  textDisplay_by();
  delaySeconds(3);
  // LCD Clear
  LCD.clear();
  
  // Part - 3
  textDisplay_measuring();
  delaySeconds(2);
  // LCD Clear
  LCD.clear();

}

void loop() {
  // Main code here

  // Part - 4
  long cm = measureDistance();
  float inches = (cm / 2.54);
  inches = round2(inches);

  // Part - 4.2
  if (cm < 5){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
  
  // Part - 5
  textDisplay_measured_values(cm,inches);
  delaySeconds(1);
  // LCD Clear
  LCD.clear();
}

String centerText(String text) {
  int lcdWidth = 16;  // Width of the LCD display (adjust according to your display)
  int textLength = text.length();
  int offset = (lcdWidth - textLength) / 2;

  // Add spaces before the text to center it
  String centeredText = "";
  for (int i = 0; i < offset; i++) {
    centeredText += " ";
  }
  centeredText += text;
  
  return centeredText;
}

void textDisplay_intro(){
  String text1_ultrasonic = centerText("Ultrasonic");
  String text2_sensor = centerText("Sensor");

  // Set Text to Line 1
  LCD.setCursor(0, 0);
  LCD.print(text1_ultrasonic);
  delay(500);

  // Set Text to Line 2
  LCD.setCursor(0, 1);
  LCD.print(text2_sensor);
}

void textDisplay_by(){
  String text1_by = "By:-";
  String text2_jenil = "Jenil Chudgar :)";

  // Set Text to Line 1
  LCD.setCursor(0, 0);
  LCD.print(text1_by);
  delay(500);

  // Set Text to Line 2
  LCD.setCursor(0, 1);
  LCD.print(text2_jenil);
}

void textDisplay_measuring(){
  String text1_measure = centerText("Measuring");
  String text2_distance = centerText("Distance...");

  // Set Text to Line 1
  LCD.setCursor(0, 0);
  LCD.print(text1_measure);
  delay(500);

  // Set Text to Line 2
  LCD.setCursor(0, 1);
  LCD.print(text2_distance);
}

long measureDistance(){
  long duration;
  long distance;

  // Creating a Pulse
  // __|-|__
  digitalWrite(triggerPin,LOW);
  delay(2/1000);

  digitalWrite(triggerPin,HIGH);
  delay(10/1000);

  digitalWrite(triggerPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  // d = duration x 0.034
  //    __________________
  //           2

  distance = (duration * 0.034)/2;

  return distance;
}

void textDisplay_measured_values(long cm,float inches){
  String text1_cm = centerText("CM:" + String(cm));
  String text2_inches = centerText("Inches:" + String(inches));

  // Set Text to Line 1
  LCD.setCursor(0, 0);
  LCD.print(text1_cm);

  // Set Text to Line 2
  LCD.setCursor(0, 1);
  LCD.print(text2_inches);
}

void delaySeconds(float s){
  delay(s*1000);
}

float round2(float value) {
  return round(value * 100) / 100.0;
}