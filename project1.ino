#include <DHT.h>
#define Type DHT11
#include <LiquidCrystal.h>
int sensePin = 2;
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
int trigPin = 6;
int echoPin = 5;
float Humidity;
int distance;

float TempC;
float TempF;
int duration;
int setTime;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
DHT HT(sensePin,Type);

void setup() {

  HT.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(4,OUTPUT);
  pinMode(13,OUTPUT);

 
}

void loop() {

  
  Humidity = HT.readHumidity();
  TempC = HT.readTemperature();
  TempF = HT.readTemperature(true);

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" ");
  
  if(distance<20)
  {
    digitalWrite(4,HIGH);
    analogWrite(13,1000);
  }
  else
  {
    digitalWrite(4,LOW);
  }

  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(Humidity);

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(TempC);
  lcd.print("C");

  Serial.print("Humidity: ");
  Serial.print(Humidity);
  Serial.print("TempC: ");
  Serial.print(TempC);
  Serial.print("TempF: ");
  Serial.println(TempF);
  delay(1000);



}