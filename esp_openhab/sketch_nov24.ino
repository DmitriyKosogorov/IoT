#include "Config.h"
#include "Server.h"
#include "WIF.h"
#include "MQTT.h"


String unique_topic="da";
void setup() {
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
  pinMode(A0,INPUT);
  WIFI_init(MODE_AP);
  server_init();
  MQTT_init();
  //String unique_topic="da";
  mqtt_client.subscribe((unique_topic+"/command").c_str());
}

void loop() {
  server.handleClient();
  int sensor = Serial.read();
  Serial.println(sensor);
  mqtt_client.publish((unique_topic+"/state").c_str(), (String(sensor)).c_str());
  mqtt_client.loop();
  delay(1000);
}
