#include <LiquidCrystal.h>
#include <DHT.h>   
#include <Servo.h>

LiquidCrystal lcd(8, 7, 6, 5, 4, 3); 

const int hot_1 = 22;
const int hot_2 = 28;
const int warm = 22;
const int mid_1 = 32;
const int mid_2 = 22;
const int cold = 32;
const int frigid_1 = 26;
const int frigid_2 = 32;

int lastSection = -1;

void setup() {

pinMode(22, OUTPUT);
pinMode(24, OUTPUT);
pinMode(26, OUTPUT);
pinMode(28, OUTPUT);
pinMode(30, OUTPUT);
pinMode(32, OUTPUT);

Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(0, 0);
lcd.print("Initializing");
lcd.setCursor(0, 1);
lcd.print("Home Control.");
delay(2000);
lcd.clear();    

}

void loop() {

lcd.setCursor(0, 0);

int color_potValue = analogRead(A0);

int section;

if (color_potValue > 670) 
{
  section = 4;
}
else {
  section = color_potValue * 5 / 1024;
}  

Serial.println(section);
Serial.println(color_potValue);
  if(section != lastSection) {

    // Turn everything off ONCE
    digitalWrite(22, LOW);
    digitalWrite(24, LOW);
    digitalWrite(26, LOW);
    digitalWrite(28, LOW);
    digitalWrite(30, LOW);
    digitalWrite(32, LOW);

switch(section) {

case 0:  // 2 blue
digitalWrite(frigid_2, HIGH);
digitalWrite(frigid_1, HIGH);

break;

case 1: // 1  blue
digitalWrite(cold, HIGH);
digitalWrite(26, LOW);

break;

case 2: //mid
digitalWrite(mid_1, HIGH);
digitalWrite(mid_2, HIGH);

break;

case 3: //warm
digitalWrite(warm, HIGH);
digitalWrite(30, LOW);

break;

case 4: //hot
digitalWrite(hot_1, HIGH);
digitalWrite(hot_2, HIGH);

break;

default: 
  digitalWrite(22, LOW);
  digitalWrite(24, LOW);
  digitalWrite(26, LOW);
  digitalWrite(28, LOW);
  digitalWrite(30, LOW);
  digitalWrite(32, LOW);
}

 lastSection = section;
  }
}