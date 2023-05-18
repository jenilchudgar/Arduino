// #4 Get Value of Potentiometer

// Variables 
int po = A0;
int val = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(po,INPUT);

  Serial.print("Program Ended.");
}

void loop() {
  Serial.println("Loop Started.");

  // put your main code here, to run repeatedly:

  val = analogRead(po);

  Serial.println(val);

  Serial.println("Loop Finished.");
  delay(100);
}
