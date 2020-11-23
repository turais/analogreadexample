
#include <Arduino.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";


int analogPin = A0;
float read_curr_ma = 0.0;
float max_curr_ma = 20.0;
float adc_intervals = 1023.0;

BlynkTimer timer;

void timer_event() {
  read_curr_ma = analogRead(analogPin) * (max_curr_ma / adc_intervals); 
  Serial.println(read_curr_ma);  
  Blynk.virtualWrite(V5, read_curr_ma);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  timer.setInterval(1000L, timer_event);
}

void loop() {
  Blynk.run();
  timer.run();
}
