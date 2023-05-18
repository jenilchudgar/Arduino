// #10 Traffic Light System (RED and GREEN Only)

// Variables
int LED_GRP_1[2]={2,3};
int LED_GRP_2[2]={4,5};
int LED_GRP_3[2]={6,7};
int LED_GRP_4[2]={8,9};


void setup() {
  Serial.begin(9600);
  Serial.print("Program Started.");
  
  // put your setup code here, to run once:
  pinMode(LED_GRP_1[0],INPUT);
  pinMode(LED_GRP_1[1],INPUT);

  pinMode(LED_GRP_2[0],INPUT);
  pinMode(LED_GRP_2[1],INPUT);

  pinMode(LED_GRP_3[0],INPUT);
  pinMode(LED_GRP_3[1],INPUT);

  pinMode(LED_GRP_4[0],INPUT);
  pinMode(LED_GRP_4[1],INPUT);


  Serial.print("Program Ended.");
}

void loop() {
  Serial.println("Loop Started.");

  // put your main code here, to run repeatedly:

  // 1st LED is Green
  first_led();

  delaySeconds(5);

  // 2nd LED is Green
  sec_led();

  delaySeconds(5);

  // 3rd LED is Green
  third_led();

  delaySeconds(5);

  // 4rth LED is Green
  fourth_led();

  delaySeconds(5);
  
  Serial.println("Loop Finished.");
}

void first_led(){
  digitalWrite(LED_GRP_1[1],HIGH);

  // Rest are Red
  digitalWrite(LED_GRP_2[0],HIGH);
  digitalWrite(LED_GRP_3[0],HIGH);
  digitalWrite(LED_GRP_4[0],HIGH);

  // Reset Others
  digitalWrite(LED_GRP_1[0],LOW);

  digitalWrite(LED_GRP_2[1],LOW);
  digitalWrite(LED_GRP_3[1],LOW);
  digitalWrite(LED_GRP_4[1],LOW);
}

void sec_led(){
  digitalWrite(LED_GRP_2[1],HIGH);

  // Rest are Red
  digitalWrite(LED_GRP_1[0],HIGH);
  digitalWrite(LED_GRP_3[0],HIGH);
  digitalWrite(LED_GRP_4[0],HIGH);

  // Reset Others
  digitalWrite(LED_GRP_2[0],LOW);

  digitalWrite(LED_GRP_1[1],LOW);
  digitalWrite(LED_GRP_3[1],LOW);
  digitalWrite(LED_GRP_4[1],LOW);
}

void third_led(){
  digitalWrite(LED_GRP_3[1],HIGH);

  // Rest are Red
  digitalWrite(LED_GRP_1[0],HIGH);
  digitalWrite(LED_GRP_2[0],HIGH);
  digitalWrite(LED_GRP_4[0],HIGH);

  // Reset Others
  digitalWrite(LED_GRP_3[0],LOW);

  digitalWrite(LED_GRP_1[1],LOW);
  digitalWrite(LED_GRP_2[1],LOW);
  digitalWrite(LED_GRP_4[1],LOW);
}

void fourth_led(){
  digitalWrite(LED_GRP_4[1],HIGH);

  // Rest are Red
  digitalWrite(LED_GRP_1[0],HIGH);
  digitalWrite(LED_GRP_2[0],HIGH);
  digitalWrite(LED_GRP_3[0],HIGH);

  // Reset Others
  digitalWrite(LED_GRP_4[0],LOW);

  digitalWrite(LED_GRP_1[1],LOW);
  digitalWrite(LED_GRP_2[1],LOW);
  digitalWrite(LED_GRP_3[1],LOW);
}

void delaySeconds(int ms){
  delay(ms*1000);
}
