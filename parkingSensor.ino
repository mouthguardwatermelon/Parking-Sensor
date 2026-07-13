// C++ code
#include <math.h>
const int redLight = 4;
const int greenLight = 7;
const int buzzerPin = 2;
const int trigPin =10;
const int echoPin = 12;
float prev = 0.0;
float dist = 0.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLight,OUTPUT);
  pinMode(greenLight,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
};

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  unsigned long duration = pulseIn(echoPin,HIGH,30000);
  if (duration==0) {
    Serial.println("No object detected");
  } else {
  prev = dist;
  dist = duration /2.0 *0.0343;
    Serial.println(dist);
    if (dist <= 120.0) {
      if (dist < prev) {
        if ((prev-dist)>1.5){
        digitalWrite(greenLight,LOW);
        digitalWrite(redLight,HIGH);
        tone(2,1000,100);
        delay(1000);
        digitalWrite(greenLight,HIGH);
        digitalWrite(redLight,LOW);
        noTone(2);
        };
      } else if (dist >= prev){
        if ((dist-prev)>1.5){
        digitalWrite(greenLight,HIGH);
        digitalWrite(redLight,LOW);
        };
      };
    } else{
    	digitalWrite(greenLight,LOW);
      digitalWrite(redLight,LOW);
    };
  };
  delay(100);
  };
