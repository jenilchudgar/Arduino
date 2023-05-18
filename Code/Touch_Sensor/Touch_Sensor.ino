// #6 Touch Sensor

// Variables
int sensor = 9;
int buzzer = 10;
int state = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Program Started.");
  
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  pinMode(buzzer,OUTPUT);

  Serial.println("Program Ended.");
}

void loop() {
  Serial.println("Loop Started.");

  // put your main code here, to run repeatedly:
  state = digitalRead(sensor);
  Serial.println(state);

  // Check State of Sensor (if touched)
  if (state==HIGH){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }

  Serial.println("Loop Finished.");
  delay(100);
}
