int SWPIN = 18;
int LEDPIN = 4;
void setup() {
  Serial.begin(115200);
  pinMode(SWPIN, INPUT_PULLUP);
  pinMode(LEDPIN,OUTPUT);
}

void loop() {
  int data = digitalRead(SWPIN);
  if(data == 0)
  {
    for(int i=0;i<3;i++)
    {
      digitalWrite(LEDPIN,HIGH);
      delay(500);
      digitalWrite(LEDPIN,LOW);
      delay(500);
    }
  }
  Serial.println(data);
  delay(100);
}