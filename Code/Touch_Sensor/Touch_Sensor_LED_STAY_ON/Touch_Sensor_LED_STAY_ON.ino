// #7 Touch Sensor (LED stays ON/OFF)

// Variables
int sensor = 9;
int LED = 10;
int state = 0;
int flag = 0;

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

  // Check State of Sensor (if touched)
  if (state==HIGH){
    // Alternate Between On and Off According to Touch
    if (flag==0){
      flag = 1;
    }
    else{
      flag = 0;
    }
  }

  if (flag==1){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }

  Serial.println("Loop Finished.");
  delay(100);
}
