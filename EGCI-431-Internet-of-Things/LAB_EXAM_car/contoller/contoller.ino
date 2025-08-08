#include "mqtt.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

#define ForceSensorD 18
#define ForceSensorR 19

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {
  pinMode(ForceSensorD,INPUT_PULLUP);
  pinMode(ForceSensorR,INPUT_PULLUP);
  Serial.begin(9600);
//********************** ADXL345 **************************     
  Serial.println("Accelerometer Test"); Serial.println("");

  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  /* Set the range to whatever is appropriate for your project */
  // accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
  accel.setRange(ADXL345_RANGE_2_G);
    
  //************************* MQTT ****************************
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop(void){

//******************** FORCE SENSOR ************************ 
  int forward = digitalRead(ForceSensorD);
  int backward = digitalRead(ForceSensorR);
//*********************** SENSOR *************************** 
  sensors_event_t event; 
  accel.getEvent(&event);
  // Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  // Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  // Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  // Serial.print("Forward: ");Serial.print(foward); Serial.print("  ");
  // Serial.print("Backward: ");Serial.print(backward); Serial.print("  ");  

//************************* MQTT ****************************
  if (!client.connected()) {
    reconnect();  
  }
  client.loop();

  StaticJsonDocument<200> doc;
  doc["x-axis"] = event.acceleration.x;
  // doc["y=axis"] = event.acceleration.y;
  doc["forward"] = forward;
  doc["backward"] = backward;
  String mqttData;
  serializeJson(doc, mqttData);
  client.publish("sensor", mqttData.c_str());
  
//**********************************************************
  delay(50);
}
