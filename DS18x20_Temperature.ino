//orange as power (positive), black as ground, and yellow as the signal pin 

#include <OneWire.h>
#include <DallasTemperature.h>

// Pin where the DS18B20 is connected
#define ONE_WIRE_BUS 2

// Setup a oneWire instance
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();  // Send command to get temperatures
  float temperatureF = sensors.getTempFByIndex(0); // Get temperature in Fahrenheit
  
  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.println(" °F");
  
  delay(1000); // Wait a second between readings
}