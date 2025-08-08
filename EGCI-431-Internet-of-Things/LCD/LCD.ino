#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int count = 0;

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello World!");
  lcd.setCursor(0,1);
  delay(1000);
}
void loop()
{
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Count");
  lcd.setCursor(10,1);
  lcd.print(count);
  count = count + 1;
  delay(1000);
}