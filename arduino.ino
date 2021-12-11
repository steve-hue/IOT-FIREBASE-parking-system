int trigPin = 9;
int echoPin = 8;
int mtp1 = 11;
int mtp2 = 12;
long duration;
int distance;

void setup() {
  Serial.begin(91200);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(trigPin, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 25){digitalWrite(1, HIGH);}
  else{digitalWrite(1, LOW);}
  digitalWrite(11, HIGH);
  delay(333);
  digitalWrite(11, LOW);
  delay(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 30){digitalWrite(2, HIGH);}
  else{digitalWrite(2, LOW);}
  digitalWrite(11, HIGH);
  delay(333);
  digitalWrite(11, LOW);
  delay(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 25){digitalWrite(3, HIGH);}
  else{digitalWrite(3, LOW);}
  digitalWrite(11, HIGH);
  delay(333);
  digitalWrite(11, LOW);
  delay(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 25){digitalWrite(4, HIGH);}
  else{digitalWrite(4, LOW);}
  digitalWrite(12, HIGH);
  delay(915);
  digitalWrite(12, LOW);
}
