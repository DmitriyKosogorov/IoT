#include <PubSubClient.h>

PubSubClient mqtt_client(wificlient);

void callback(char* topic, byte* payload, unsigned int len)
{
  String payload_string = "";
  
  for (auto i = 0; i < len; i++) {
    payload_string += char(payload[i]);
    Serial.print(char(payload[i]));
  }
/*
  if (payload_string == "LOW") {
    digitalWrite(led_pin, LOW);
  } else {
    digitalWrite(led_pin, HIGH);
  }
  */
  if (payload_string == "OFF") {
    digitalWrite(led_pin, HIGH);
  } else 
  if (payload_string == "ON") {
    digitalWrite(led_pin, LOW);
  }
  Serial.println("--------------------------");
}

void MQTT_init()
{
  mqtt_client.setServer(mqtt_broker, mqtt_port);
  mqtt_client.setCallback(callback);
  String client_id="esp8266-"+String(WiFi.macAddress());
  while(! mqtt_client.connected())
  {
    if(mqtt_client.connect(client_id.c_str()))
    {
      Serial.println("MQTT CONNECTED");
      Serial.println(client_id);
    }
    else
    {
      Serial.println("MQTT FAILED");
      delay(1000);
    }
  }
}
