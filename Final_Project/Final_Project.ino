#include <LiquidCrystal.h>
#include <DHT.h>   
#include <Servo.h>

LiquidCrystal lcd(8, 7, 6, 5, 4, 3); 

const int hot_1 = 22;
const int hot_2 = 28;
const int warm = 22;
const int mid_1 = 22;
const int mid_2 = 32;
const int cold = 26;
const int frigid_1 = 26;
const int frigid_2 = 32;

void setup() {

pinMode(22, OUTPUT);
pinMode(24, OUTPUT);
pinMode(26, OUTPUT);
pinMode(28, OUTPUT);
pinMode(30, OUTPUT);
pinMode(32, OUTPUT);

Serial.begin(9600);
lcd.begin(16,2);
lcd.clear();    

}

void loop() {

lcd.setCursor(0, 0);
lcd.print("Initializing");
lcd.setCursor(0, 1);
lcd.print("Home Control.");

digitalWrite(frigid_2, HIGH);
digitalWrite(frigid_1, HIGH);

}