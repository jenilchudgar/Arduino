// #21 Joystick Module

// Variables
int x_axis = A1;
int y_axis = A2;
int click = 9;

int LED_1 = 2;
// int LED_2 = 3;
// int LED_3 = 4;
// int LED_4 = 5;
// int LED_5 = 6;

void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(x_axis,INPUT);
  pinMode(y_axis,INPUT);
  pinMode(click,INPUT);

  pinMode(LED_1,OUTPUT);
  // pinMode(LED_2,OUTPUT);
  // pinMode(LED_3,OUTPUT);
  // pinMode(LED_4,OUTPUT);
  // pinMode(LED_5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x;
  int y;
  int c;

  x = analogRead(x_axis);
  y = analogRead(y_axis);
  c = digitalRead(click);

  Serial.println("X: "+String(x));
  Serial.println("Y: "+String(y));
  Serial.println("Click: "+String(c));
  Serial.println("");
  digitalWrite(LED_1,LOW);
  
  delay(250);
}
