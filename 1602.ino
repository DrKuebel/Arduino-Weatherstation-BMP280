#include <LiquidCrystal.h>
#include <Seeed_BME280.h>
#include <Wire.h>

BME280 bme280;

int interval = 5000;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the number of columns and rows on the LCD 
  lcd.begin(16, 2);

  if(!bme280.init()){
 lcd.print("Device error!");
}
}

void loop() {
  
  lcd.setCursor(0, 0);
 lcd.print("Temperatur");
  lcd.setCursor(0, 1);
 lcd.print(bme280.getTemperature(),1);
 lcd.print(" C");

 delay(interval);
 lcd.clear();

lcd.setCursor(0, 0);
 lcd.print("Luftdruck");
 lcd.setCursor(0, 1);
 lcd.print(bme280.getPressure());
 lcd.print(" Pa");

 delay(interval);
 lcd.clear();

 lcd.setCursor(0, 0);
 lcd.print("Luftfeuchtigkeit");
 lcd.setCursor(0, 1);
 lcd.print(bme280.getHumidity());
 lcd.print("%");

 delay(interval);
 lcd.clear();
  }

