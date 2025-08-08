#include "mqtt.h"
#define SensorTrigger1 5
#define SensorEcho1  18
#define SensorTrigger2 19
#define SensorEcho2 21
#define SOUND_SPEED 0.034

long duration1, duration2;
float usSensor1, usSensor2;
int doorStatus, walkStatus;

void getUS()
{
  digitalWrite(SensorTrigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(SensorTrigger1, HIGH);
  delayMicroseconds(10);
  digitalWrite(SensorTrigger1, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(SensorEcho1, HIGH);
  usSensor1 = duration1 * SOUND_SPEED/2;
  if(usSensor1<90 && usSensor1!= 0)
    doorStatus = 1;
  else
    doorStatus = 0;

    
  digitalWrite(SensorTrigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(SensorTrigger2, HIGH);
  delayMicroseconds(10);
  digitalWrite(SensorTrigger2, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(SensorEcho2, HIGH);
  usSensor2 = duration2 * SOUND_SPEED/2;
  if(usSensor2<90 && usSensor2!= 0)
    walkStatus = 1;
  else
    walkStatus = 0;
}

void setup() {
  pinMode(SensorTrigger1, OUTPUT);
  pinMode(SensorEcho1, INPUT);
  pinMode(SensorTrigger2, OUTPUT);
  pinMode(SensorEcho2, INPUT);
  Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

int wait = 20;
int peopleCount = 0;
int lastPeopleCount = -1;
void debug(){
  Serial.printf("usSensor1 : %f => doorStatus : %d, ",usSensor1,doorStatus);
  Serial.printf("usSensor2 : %f => walkStatus : %d, ",usSensor2,walkStatus);
  Serial.printf("people count : %d\n",peopleCount);

}
void loop(){  
    if (!client.connected()) {
    reconnect();  
  }
  client.loop();

  getUS();
  if(doorStatus == 1 && walkStatus == 0)// walkin
  {
    for(int i=0;i<wait;i++)
    { 
      getUS();
      if(walkStatus == 1)
      {
        peopleCount++;
        break;
      }
      debug();
      delay(100);
    }
  }

  else if (doorStatus == 0 && walkStatus== 1)
  {
    for(int i = 0;i<wait;i++)
    { 
      getUS();
      if(doorStatus == 1) 
      {
        peopleCount--;
        if (peopleCount <0)
          peopleCount = 0;
        break;
      }
      debug();
      delay(100);
    }
  }
  debug();
  if (peopleCount != lastPeopleCount)
  {
    String mqttData = String(peopleCount);
    client.publish("Door", mqttData.c_str());
    lastPeopleCount = peopleCount;
    delay(500);
  }
  delay(100);
}

