/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-cooling-system-using-ds18b20-temperature-sensor
 */

#include <OneWire.h>
#include <DallasTemperature.h>


//
#define SENSOR_PIN     23  // 
#define RELAY_FAN_PIN  17 // 

OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);

void setup() {
  Serial.begin(9600);  
  DS18B20.begin();    
  pinMode(17, OUTPUT);
  
}

void loop() {
  DS18B20.requestTemperatures();                 
  int temperature = DS18B20.getTempCByIndex(0); 
Serial.print(temperature);
  
  if(temperature > 30){
    digitalWrite(RELAY_FAN_PIN, HIGH);
  }
  else{
    digitalWrite(RELAY_FAN_PIN, LOW);
  }
}
