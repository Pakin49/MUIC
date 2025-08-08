#include "mqtt.h" 
#include <Wire.h>

// left motor
#define MotorPin1 18
#define MotorPin2 19
// #define PWMLeft 2
// right motor
#define MotorPin3 23
#define MotorPin4 22
// #define PWMRight 4
// receive value from mqtt [car] in mqtt.h callback()

char go;

void setup(){
  Serial.begin(9600);
  
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  // pinMode(PWMLeft, OUTPUT);

  pinMode(MotorPin3,OUTPUT);
  pinMode(MotorPin4,OUTPUT);
  // pinMode(PWMRight, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop(void){
    if (!client.connected()) {
    reconnect();
  }
  client.loop();

  switch (go)
  {
    case '1':
      digitalWrite(MotorPin1, LOW);
      digitalWrite(MotorPin2, LOW);
      digitalWrite(MotorPin3, HIGH);
      digitalWrite(MotorPin4, LOW);
      Serial.println("front left");
      break;
    case '2':
      digitalWrite(MotorPin1, HIGH);
      digitalWrite(MotorPin2, LOW);
      digitalWrite(MotorPin3, HIGH);
      digitalWrite(MotorPin4, LOW); 
      Serial.println("front");
      break;
    case '3':
      digitalWrite(MotorPin1, HIGH);
      digitalWrite(MotorPin2, LOW);
      digitalWrite(MotorPin3, LOW);
      digitalWrite(MotorPin4, LOW); 
      Serial.println("front right"); //
      break;
    case '-':
      digitalWrite(MotorPin1, LOW);
      digitalWrite(MotorPin2, HIGH);
      digitalWrite(MotorPin3, LOW);
      digitalWrite(MotorPin4, HIGH); 
      Serial.println("back");
      break;
    case '0' :
      digitalWrite(MotorPin1, LOW);
      digitalWrite(MotorPin2, LOW);
      digitalWrite(MotorPin3, LOW);
      digitalWrite(MotorPin4, LOW); 
      Serial.println("stay");
      break;
  }
  delay(25);
  // Serial.printf("go : %s, turn :%s\n",go,turn);
} 






