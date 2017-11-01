#define motorPin A0

// Ultrasonic pins
#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

void setup() {
  Serial.begin (9600);

  // Ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

  // Motor pin
  pinMode(motorPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

   if (distance < 10) {
     digitalWrite(led,HIGH);
     digitalWrite(led2,LOW);
    // digitalWrite(motorPin, HIGH);
   } else {
     digitalWrite(led,LOW);
     digitalWrite(led2,HIGH);
   //  digitalWrite(motorPin, LOW);
   }

//  if (distance >= 10 || distance <= 50) {
//      digitalWrite(led,HIGH);
//      digitalWrite(led2,LOW);
//      digitalWrite(motorPin, HIGH);
//  } else {
//      digitalWrite(led,LOW);
//      digitalWrite(led2,HIGH);
//      digitalWrite(motorPin, LOW);
//  }

  delay(500);
}
