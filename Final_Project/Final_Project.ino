#include <LiquidCrystal.h>
#include <DHT.h>   
#include <Servo.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7); 

#define DHTPIN // add DHT pin number here
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {

pinMode( , INPUT); // add DHT pin number here

Serial.begin(9600);
lcd.begin(16,2);
lcd.print("Home System Activated");
lcd.clear();    

}

void loop() {

lcd.setCursor(0, 0);
lcd.print("Lucas > Luke LMAO");

}