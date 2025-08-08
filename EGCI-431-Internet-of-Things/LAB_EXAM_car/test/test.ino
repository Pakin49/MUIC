// left motor
#define MotorPin1 18
#define MotorPin2 19
// #define PWMLeft 2
// right motor
#define MotorPin3 23
#define MotorPin4 22
// #define PWMRight 4 

void setup() {
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  // pinMode(PWMLeft, OUTPUT);

  pinMode(MotorPin3,OUTPUT);
  pinMode(MotorPin4,OUTPUT);
  // pinMode(PWMRight, OUTPUT);

  // analogWrite(PWMLeft, 254);
  // analogWrite(PWMRight,254);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, HIGH);
  digitalWrite(MotorPin4, LOW);

}