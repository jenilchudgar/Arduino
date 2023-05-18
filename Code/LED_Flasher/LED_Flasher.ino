// #3 LED Fader

// Vraibales
int LED = 9;

void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(LED,OUTPUT);

  Serial.print("Program Ended.");
}

void loop() {
  Serial.println("Loop Started.");

  // put your main code here, to run repeatedly:

  // Increment
  for(int i=0;i<=255;i+=5){
    analogWrite(LED,i);
    delay(30);
  }

  // Decrement
  for(int i=255;i>=0;i-=5){
    analogWrite(LED,i);
    delay(30);
  }

  Serial.println("Loop Finished.");
  delay(100);
}
