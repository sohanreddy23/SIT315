const int temperatureSensorPin = A0;  // Temperature sensor connected to analog pin A0
const int ledPin = 13;  // LED connected to digital pin 13
const float baselineTemp = 25.0;  // Baseline temperature in Celsius

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  // Sense: Read the temperature sensor
  int sensorValue = analogRead(temperatureSensorPin);
  
  // Convert the sensor reading to voltage
  float voltage = (sensorValue / 1024.0) * 5.0;
  
  // Convert the voltage to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;
  
  // Think: Compare with baseline temperature
  if (temperatureC > baselineTemp) {
    // Act: Turn on LED if temperature is above baseline
    digitalWrite(ledPin, HIGH);
    Serial.print("Temperature above baseline. LED ON. Temperature: ");
  } else {
    // Act: Turn off LED if temperature is at or below baseline
    digitalWrite(ledPin, LOW);
    Serial.print("Temperature at or below baseline. LED OFF. Temperature: ");
  }
  
  // Print the temperature
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  delay(1000);  // Wait for a second before next reading
}