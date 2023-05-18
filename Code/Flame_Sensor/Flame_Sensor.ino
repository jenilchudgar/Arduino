// #1 Boiler Plate Code

// Variables
int sensor = 9;
int buzzer = 11;
int val = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  pinMode(buzzer,OUTPUT);

  Serial.print("Program Ended.");
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
  Serial.println(val);

  if (val==LOW){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
  delay(1000);
}
