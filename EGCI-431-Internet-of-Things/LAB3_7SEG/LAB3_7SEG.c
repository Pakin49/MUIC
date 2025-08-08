#include "LedControl.h"
int count = 0;
int SWPIN = 18;
LedControl lc=LedControl(13,14,12,1);

void setup() {
  Serial.begin(115200);
  pinMode(SWPIN,INPUT_PULLUP);
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() {
  int data = digitalRead(SWPIN);
  if(data == 0)
  { 
    count++;
    int value = count;
    for(int i=0;i<=7;i++)
    {
      lc.setDigit(0,i,value%10,false);
      value = value/10;
    }
    while(data==0)
    {
      data = digitalRead(SWPIN);
      Serial.printf("%d %d\n",data,count);
      delay(20);
    }
  }
  Serial.printf("%d %d\n",data,count);
  delay(100);
}
