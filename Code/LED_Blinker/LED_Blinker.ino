// #2 LED Blinker

// Variables
int LED = 9;

void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);

  Serial.print("Program Ended.");
}

void loop() {
  Serial.println("Loop Started.");

  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);

  // Wait For 1000 ms
  delay(500);

  digitalWrite(LED,LOW);

  Serial.println("Loop Finished.");
  delay(500);
}
