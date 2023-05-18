// #12 Get Potentiometer Reading

// Variables
int PO =  A4;
int val;


void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  pinMode(PO,INPUT);
  

  Serial.print("Program Ended.");
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(PO);

  Serial.println(val);

  delay(100);
}
