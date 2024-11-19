#define led 5
#define trigger 13
#define echo 12

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);
}

void loop() {
  long t; // tiempo que demora en llegar el eco
  long d; // distancia en cm

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  t = pulseIn(echo, HIGH);
  d = t/59;

  if(d<10){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.println();
  delay(100);
}
