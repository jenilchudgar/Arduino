// #14 Get In The Room (Light Stays On/Off)

// Variables
int echo = 10;
int trigg = 9;
int LED = 2;
int buzzer = 3;
int flag = 0;
long duration;
long distance;


void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(echo,INPUT);
  pinMode(trigg,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
 // put your main code here, to run repeatedly:

  // Creating a Pulse
  // __|-|__
  digitalWrite(trigg,LOW);
  delay(2/1000);

  digitalWrite(trigg,HIGH);
  delay(10/1000);

  digitalWrite(trigg,LOW);

  duration = pulseIn(echo,HIGH);

  // d = duration x 0.034
  //    __________________
  //           2

  distance = (duration * 0.034)/2;
  Serial.println(distance);

  soundBuzzer();

  if (isUltrasonicSensorHigh()){
    if (flag == 1){
      flag = 0;
    }
    else{
      flag = 1;
    }
  }
  
  if (flag == 1){
    digitalWrite(LED,HIGH);
    delay(100);
  }
  else{
    digitalWrite(LED,LOW);
    delay(100);
  }
  
  delay(1000);
}


bool isUltrasonicSensorHigh(){
  if (distance >= 15 && distance <=100){
    delay(100);
    return true;
  }
  else{
    delay(100);
    return false;
  }
}

void soundBuzzer(){
  if (distance <= 10){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}
