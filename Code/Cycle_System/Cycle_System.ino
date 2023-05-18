// #25 Cycle System

// Varibles
const int buzzer = 9;
const int LED_1 = 7;
const int LED_2 = 4;
const int touch_sensor = 11;
const int switch_toggle = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(touch_sensor,INPUT);
  pinMode(switch_toggle,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int switch_state = digitalRead(switch_toggle);

  if (switch_state == HIGH)
  {
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2,HIGH);
  }
  else
  {
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2,LOW);
  }

  int touch_state = digitalRead(touch_sensor);

  if (touch_state == HIGH)
  {
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
}
