#include <Wire.h>
#define FSRPIN1 34
#define FSRPIN2 35
#include "mqtt.h"
#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHT11);


void setup() {
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  // client.setCallback(callback); uncomment if want to use callback()
  // to receive msg from mqtt
  Serial.println(F("DHT11 test!"));
  dht.begin();  
}

int seatA;
int seatB;
int seatAvailable;

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  // this is non block delay
  if (now - lastMsg > 10000) {
    lastMsg = now;

    int analogReadingA = analogRead(FSRPIN1);
    int analogReadingB = analogRead(FSRPIN2);

    if(analogReadingA > 100)
      seatA = 0;
    else
      seatA = 1;

    if(analogReadingB > 100)
      seatB = 0;
    else
      seatB =1;

  seatAvailable = seatA + seatB;
  Serial.printf("Seat Available: %d \n", seatAvailable);

  String mqttData = String(seatAvailable); // Convert the int to a string
  client.publish("Seat", mqttData.c_str());
  }
//********************* temp ***********************
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }


  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));

  String mqttData = "Humidity: " + String(h) + 
                    "%, Temperature: " + String(t) + 

  client.publish("Temp", mqttData.c_str());
}