#include <DHT.h>
#define DHT_TYPE DHT11
#define DHT_PIN 13
DHT dht(DHT_PIN, DHT_TYPE);
const int analogPin = A0;  
const int digitalPin = 2; 
const int waterLevelPin = 3;
const int raindropPin = A1; 
void setup() {
Serial.begin(9600);
dht.begin();
pinMode(digitalPin, INPUT);
pinMode(waterLevelPin, INPUT);
}
void loop() 
{
  int sensorValue = analogRead(raindropPin);

  // Print the sensor value to the Serial Monitor
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  delay(1000); 
  int waterLevel = digitalRead(waterLevelPin);

  // Print the water level (HIGH or LOW) to the Serial Monitor
  if (waterLevel == HIGH) {
    Serial.println("Water level: HIGH (Water detected)");
  } else {
    Serial.println("Water level: LOW (No water detected)");
  }

  delay(1000); // Wait for 1 second before taking another reading
  int analogValue = analogRead(analogPin);  
  int digitalValue = digitalRead(digitalPin);  

  Serial.print("Analog Value: ");
  Serial.println(analogValue);
  Serial.print("Digital Value: ");
  Serial.println(digitalValue);

  if (digitalValue == HIGH) {
    Serial.println("Smoke detected!");
    
  } else {
    Serial.println("No smoke detected");
    
  }

  delay(1000); 
float temperature = dht.readTemperature();
if (!isnan(temperature)) {
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.print(" °C\n");
delay(2000);
} 
else 
{
Serial.println("Failed to read from DHT sensor. Please check the wiring.");
}

}
