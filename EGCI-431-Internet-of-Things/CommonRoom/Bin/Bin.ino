#include "mqtt.h"
#define SensorTrigger 5
#define SensorEcho  18
#define SOUND_SPEED 0.034
void setup() {

  Serial.begin(115200);
  //********************** Ultrasonic *************************
  // insert code here
  pinMode(SensorTrigger, OUTPUT);
  pinMode(SensorEcho, INPUT);
  //************************* MQTT ****************************
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

int bin_status;
float bin_sensor;
long duration;
void loop() {
  //********************** Ultrasonic *************************
  // insert code here
  digitalWrite(SensorTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(SensorTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(SensorTrigger, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(SensorEcho, HIGH);
  
  // Calculate the distance in CM
  bin_sensor = duration * SOUND_SPEED/2;
  Serial.println(bin_sensor);
 
  if (bin_sensor <= 10)
    bin_status = 1; // 1 = bin is FULL
  else
    bin_status = 0;

  delay(1000);
  //************************* MQTT ****************************
  if (!client.connected()) {
    reconnect();  
  }
  client.loop();

  String mqttData = String(bin_status); // Convert the int to a string
  client.publish("Bin", mqttData.c_str());
  
  delay(10000);
}
