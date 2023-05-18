// #15 Burglar Detection

// Variables
int echo = 10;
int trigg = 9;
int buzzer = 3;
long duration;
long distance;
long pre_distance = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trigg, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Creating a Pulse
  // __|-|__
  digitalWrite(trigg, LOW);
  delayMicroseconds(2);

  digitalWrite(trigg, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigg, LOW);

  duration = pulseIn(echo, HIGH);

  // d = duration x 0.034 / 2
  distance = (duration * 0.034) / 2;
  Serial.println(distance);

  distance = int( (distance / 10) ) * 10;

  if (pre_distance != 0 && distance != pre_distance) {
    bangBuzzer();
  } 

  pre_distance = distance;

  delay(500);
}

void bangBuzzer(){
  while (true) {
    digitalWrite(buzzer, HIGH);
  }
}
