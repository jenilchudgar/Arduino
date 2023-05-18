// #21 LCD With Raindrop Sensor
#include <LiquidCrystal.h>

// Variables
LiquidCrystal LCD(3, 12, 4, 5, 6, 7);

int sensor_d = 9;
int sensor_a = A3;
int buzzer = 10;

int digital_values;
int analog_values;

byte Water[8] = {
  0b00000,
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00000
};

byte Tick[8] = {
  0b00000,
  0b00000,
  0b00001,
  0b00010,
  0b10100,
  0b01000,
  0b00000,
  0b00000
};

byte Cross[8] = {
  0b00000,
  0b10001,
  0b01010,
  0b00100,
  0b01010,
  0b10001,
  0b00000,
  0b00000
};

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
  LCD.begin(16, 2);

  // Set Up Pin Modes
  pinMode(sensor_d, INPUT);
  pinMode(sensor_a, INPUT);
  pinMode(buzzer, OUTPUT);

  // Reset LCD
  LCD.clear();
  delay(1000);

  // Create Character
  LCD.createChar(0, Water);
  LCD.createChar(1, Tick);
  LCD.createChar(2, Cross);

  // Part - 1 (Introduction)
  for (int i = 0; i <= 4; i++) {
    if (i != 0) {
      LCD.setCursor(i - 1, 0);
      LCD.print(" ");
    }
    LCD.setCursor(i, 0);
    LCD.print("Raindrop");
    delay(500);
  }

  delay(1000);

  for (int i = 9; i >= 5; i--) {
    if (i != 9) {
      LCD.setCursor(i + 6, 1);
      LCD.print(" ");
    }
    LCD.setCursor(i, 1);
    LCD.print("Sensor");
    if (i != 5) {
      delay(500);
      LCD.setCursor(i, 1);
      LCD.print("     ");
    }
  }

  delay(1000);


  // lcdPrintln("Raindrop",0,0,true,true);
  // lcdPrintln("Sensor",1,1000,true,false);

  // Part - 2 (Person who Made It)
  lcdPrintln("By:-", 0, 500, true, false);
  lcdPrintln("Jenil Chudgar :)", 1, 1500, false, false);

  // Part - 3 (Detecting Water)
  lcdPrintln("Detecting Water", 0, 500, true, true);
  for (int i = 0; i <= 15; i++) {
    if (i != 0) {
      LCD.setCursor(i - 1, 1);
      LCD.print(" ");
    }
    LCD.setCursor(i, 1);
    LCD.write(byte(0));

    delay(200);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  // Part - 4 (Measuring)
  lcdPrintln("Water Detected:", 0, 0, true, true);
  lcdPrintln("Values:", 1, 0, false, false);

  bool detected = detectWater();
  LCD.setCursor(15, 0);

  if (detected) {
    LCD.write(byte(1));
    LCD.setCursor(7, 1);
    LCD.print(String(detectWaterValues()));
    digitalWrite(buzzer, HIGH);
  } else {
    LCD.write(byte(2));
    LCD.setCursor(7, 1);
    LCD.print(String(detectWaterValues()));
    digitalWrite(buzzer, LOW);
  }
  delay(1000);
}

void lcdPrintln(String text, int line, int delayMs, bool clear, bool center) {
  if (clear) {
    LCD.clear();
  }
  if (center) {
    text = centerText(text);
  }

  LCD.setCursor(0, line);
  LCD.print(text);
  delay(delayMs);
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

bool detectWater() {
  digital_values = digitalRead(sensor_d);

  if (digital_values == LOW) {
    return true;
  } else {
    return false;
  }
}

int detectWaterValues() {
  analog_values = analogRead(sensor_a);
  return analog_values;
}