/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-water-sensor-pump
 */

#define RELAY_PIN   13  
#define POWER_PIN   32  
#define SIGNAL_PIN  36  

#define THRESHOLD   1000 

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN,   OUTPUT); 
  pinMode(POWER_PIN, OUTPUT);   
  digitalWrite(POWER_PIN, LOW); 
  digitalWrite(RELAY_PIN, LOW); 
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  
  delay(10);                     
  int value = analogRead(SIGNAL_PIN); 
  digitalWrite(POWER_PIN, LOW);   
Serial.print(value);
  if (value > THRESHOLD) {
    Serial.print("The water is detected");
    digitalWrite(RELAY_PIN, HIGH);  
  } else {
    digitalWrite(RELAY_PIN, LOW);   
  }

  delay(1000); 
}
