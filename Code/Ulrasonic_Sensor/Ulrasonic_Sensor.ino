// #13 Ultrasonic Sensor

// Functions

// 1. Height Measuring
// 2. Blind Person Helping Stick
// 3. Obstacle Avoiding Car
// 4. Odometer

// Variables
int echo = 10;
int trigg = 9;
int LED = 2;
int buzzer = 3;
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

  if (distance >= 25 && distance <= 50){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }

  if (distance <= 10)
  {
    digitalWrite(buzzer, HIGH);

  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
  
  delay(500);
}
