//Initialising the pins

const int trigPin = 9; //trig pin on ultrasonic sensor 
const int echoPin = 8; //echo pin on ultrasonic sensor 
const int relay=7;//Data pin on relay
void setup() {
  Serial.begin(9600);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay,OUTPUT);
}

void loop() {
  long duration;
  int distance;

  //Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Measure the duration of echo signal
  duration = pulseIn(echoPin, HIGH);
  //calculating the distance in cm
  distance = duration * 0.034 / 2;
  //Printing in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<=50)
  {
    digitalWrite(relay,LOW);
    delay(10000);
  }
  else
  {
    digitalWrite(relay,HIGH);
  }
  delay(100);//delay given before the next measurement
}
