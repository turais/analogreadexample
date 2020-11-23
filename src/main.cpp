#include <Arduino.h>

int analogPin = A0;
float read_voltage = 0.0;
float ref_voltage = 3.3;
float adc_intervals = 1023.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  read_voltage = analogRead(analogPin) * (ref_voltage / adc_intervals); 
  Serial.println(read_voltage);        
}