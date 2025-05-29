int ledPin = 6;
int buzPin = 5;
const int trigPin = 3;
const int echoPin = 2;
int maxDistance = 50;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buzPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  long duration = pulseIn(echoPin,HIGH);
  int distance = duration * 0.0343/2;

  if (distance <= maxDistance && distance > 2  ) {
    activateAlert();
    Serial.println("An object is detected:");
  } else {
     deactivateAlert();
     Serial.println("no object is detected yet:");
  }

  Serial.println(distance);
  Serial.println("cm");
}

void activateAlert() {
  digitalWrite(ledPin,HIGH);
  digitalWrite(buzPin,HIGH);
  delay(500);
}
void deactivateAlert() {
  digitalWrite(ledPin,LOW);
  digitalWrite(buzPin,LOW);
  delay(500);
}