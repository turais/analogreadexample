#include <Arduino.h>

int analogPin = A0;
float read_curr_ma = 0.0;
float max_curr_ma = 20.0;
float adc_intervals = 1023.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  read_curr_ma = analogRead(analogPin) * (max_curr_ma / adc_intervals); 
  Serial.println(read_curr_ma);        
}