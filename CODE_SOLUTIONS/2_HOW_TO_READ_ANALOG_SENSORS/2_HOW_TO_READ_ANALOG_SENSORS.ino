// Define the pin connected to the analog sensor
const int sensorPin = Ax;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the value from the sensor
  int sensorValue = analogRead(sensorPin);

  // Convert the analog value (0-1023) to voltage (0-5V)
  float conversionUnit = sensorValue * (5.0 / 1023.0);

  // Print the sensor value and voltage to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("Voltage: ");
  Serial.print(conversionUnit);
  // Delay for a short time before reading again
  delay(1000);
}
