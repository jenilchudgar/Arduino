// #8 Gas Sensor

// Variables
int sensor = 9;
int LED = 10;
int state = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  pinMode(LED,OUTPUT);

  Serial.print("Program Ended.");
}

void loop() {
  Serial.println("Loop Started.");

  // put your main code here, to run repeatedly:
  state = digitalRead(sensor);

  if (state==HIGH){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }

  Serial.println("Loop Finished.");
  delay(100);
}
