/*
 * EduSmart Home - ESP32 with Sinric Pro
 * Created by: Asilbek Vaxobov
 * Description: Basic implementation of Smart Home Switch using Sinric Pro
 */

#ifdef ENABLE_DEBUG
       #define DEBUG_ESP_PORT Serial
       #define NODEBUG_WEBSOCKETS
       #define NDEBUG
#endif 

#include <Arduino.h>
#include <WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID         "YOUR_WIFI_NAME"    
#define WIFI_PASS         "YOUR_WIFI_PASSWORD"
#define APP_KEY           "YOUR_SINRIC_APP_KEY"      
#define APP_SECRET        "YOUR_SINRIC_APP_SECRET"   
#define SWITCH_ID         "YOUR_DEVICE_ID"    

#define RELAY_PIN         5  // GPIO pin connected to Relay

bool onPowerState(const String &deviceId, bool &state) {
  Serial.printf("Device %s turned %s (via SinricPro) \r\n", deviceId.c_str(), state?"on":"off");
  digitalWrite(RELAY_PIN, state ? HIGH : LOW); // Control the relay
  return true; // request handled properly
}

void setupWiFi() {
  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("connected!\r\n[Wifi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}

void setupSinricPro() {
  SinricProSwitch &mySwitch = SinricPro[SWITCH_ID];
  mySwitch.onPowerState(onPowerState);

  // setup SinricPro
  SinricPro.onConnected([](){ Serial.printf("Connected to SinricPro\r\n"); }); 
  SinricPro.onDisconnected([](){ Serial.printf("Disconnected from SinricPro\r\n"); });
  SinricPro.begin(APP_KEY, APP_SECRET);
}

void setup() {
  Serial.begin(115200); delay(1000);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Initialize relay off

  setupWiFi();
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
}
