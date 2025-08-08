#include "mqtt.h"

void setup() {
  Serial.begin(9600);

  //************************* MQTT ****************************
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {

  //************************* MQTT ****************************
  if (!client.connected()) {
    reconnect();  
  }
  client.loop();

  String mqttData = String(bin_status); // Convert the int to a string
  client.publish("Bin", mqttData.c_str());

  if msg()
}
