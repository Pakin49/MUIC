#define FORCE_SENSOR_PIN 34
#include<Wire.h>
#include<hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
hd44780_I2Cexp lcd;

void setup() {
  Serial.begin(9600); 
  
    analogSetAttenuation(ADC_11db);

  lcd.begin(16,2);
  lcd.backlight();
  lcd.print("Hello World!");
  lcd.setCursor(0,1);
  delay(1000);
}

void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);

  Serial.print("The force sensor value = ");
  Serial.print(analogReading);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Value ");
  lcd.print(analogReading);
  lcd.setCursor(0,1);


  if (analogReading < 10){
    Serial.println(" -> no pressure");
    lcd.print("no pressure");
  }
  else if (analogReading < 500){
    Serial.println(" -> light touch");
    lcd.print("light touch");
  }
  else if (analogReading < 1500){
    Serial.println(" -> light squeeze");
    lcd.print("light squeeze");
  }
  else if (analogReading < 2500){
    Serial.println(" -> medium squeeze");
    lcd.print("medium squuze");
  }
  else{
    Serial.println(" -> big squeeze");
    lcd.print("big squeeze");
  }
  delay(1000);
}
