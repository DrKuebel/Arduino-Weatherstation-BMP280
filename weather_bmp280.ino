#include <LiquidCrystal.h>
#include <Seeed_BME280.h>
#include <Wire.h>

BME280 bme280;

int interval = 1500;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);

  if(!bme280.init()){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Missing Sensor!");
  }
  
  lcd.setCursor(0, 0);
  lcd.print("BMP280 & LCD1602");
  lcd.setCursor(1, 1);
  lcd.print("Weatherstation");

  delay(interval*3);
  lcd.clear();
  
}

void loop() {
  lcd.setCursor(2, 0);
  lcd.print("Temperature");
  lcd.setCursor(5, 1);
  lcd.print(bme280.getTemperature(),1);
  lcd.print(" C");

 delay(interval);
 lcd.clear();

  lcd.setCursor(3, 0);
  lcd.print("Airpressure");
  lcd.setCursor(4, 1);
  lcd.print((bme280.getPressure())/100);
  lcd.print(" hPa");

 delay(interval);
 lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("Humidity");
  lcd.setCursor(6, 1);
  lcd.print(bme280.getHumidity());
  lcd.print(" %");

 delay(interval);
 lcd.clear();
}
