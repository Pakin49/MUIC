int LEDPIN = 4;
int SWPIN = 18;
int count = 0;
void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN,OUTPUT);
  pinMode(SWPIN,INPUT_PULLUP);
}

void loop() {
  int data = digitalRead(SWPIN);
  if(data == 0)
  { 
    count++;
    if(count == 4)
      digitalWrite(LEDPIN,HIGH);
    if(count == 5)
    {
      digitalWrite(LEDPIN,LOW);
      count = 1;
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
