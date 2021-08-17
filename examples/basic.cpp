#include <Arduino.h>
#include <Wire.h>
#include "MS56XX.h"

#define Serial SerialUSB
#define BAUD_RATE 115200

MS56XX ms_baro(MS56XX_ADDR_HIGH, MS5607);

void setup(){
  Serial.begin(BAUD_RATE);
  while(!ms_baro.begin()){
    Serial.println("BARO-FAIL");
    delay(1000);
  }
  ms_baro.configBaro(BARO_PRESS_D1_OSR_4096, BARO_TEMP_D2_OSR_4096);
}

void loop(){
  int prevMillis = millis();
  ms_baro.doBaro();

  Serial.print(ms_baro.pressure);
  Serial.print(", ");
  Serial.print(ms_baro.temperature);
  Serial.print(", ");
  Serial.print(ms_baro.altitude);
  Serial.print(", ");
  Serial.println(millis()-prevMillis);
}