/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-soil-moisture-sensor-pump
 */

#define RELAY_PIN    17 
#define MOISTURE_PIN 34 
#define ESIK 3000   

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  int value1 = analogRead(MOISTURE_PIN); 

  if (value1 > ESIK) {
    Serial.print("TOPRAK KURU => activate pump");
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    Serial.print("TOPRAK ISLAK=> deactivate the pump");
    digitalWrite(RELAY_PIN, LOW);
  }

  Serial.print(" (");
  Serial.print(value1);
  Serial.println(")");

  delay(1000);
}
