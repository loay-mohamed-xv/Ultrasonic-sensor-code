const int trigPin = 3;
const int echoPin = 2;
const int led = 8;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  //
  int safeDistance = 10;
  if(distance <= safeDistance){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
    }
  Serial.print("Distance: ");
  Serial.println(distance);
}
