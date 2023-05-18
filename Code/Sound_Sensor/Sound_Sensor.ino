// #22 Sound Sensor

int sensor = A2;
int a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = analogRead(sensor);

  Serial.println(a);

  delay(500);
}
