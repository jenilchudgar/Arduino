const int LDR = A0;
const int LED_PIN = 4;

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int val = analogRead(LDR);
  Serial.println(val);

  int brightness = map(val, 0, 1023, 0, 255);
  analogWrite(LED_PIN, brightness);

  delay(500);
}
