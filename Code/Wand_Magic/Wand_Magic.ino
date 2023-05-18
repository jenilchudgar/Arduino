// #16 Ultrasonic Sensor Wand Magic

// Variables
int LED = 3;
int sensor = 9;


void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  pinMode(sensor,INPUT);
  pinMode(LED,OUTPUT);

}

void loop() {
  int val = digitalRead(sensor);
  Serial.println(val);

  if (val == HIGH){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }

  delay(500);
}
