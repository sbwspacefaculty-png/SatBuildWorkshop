// Define the pin for LED1
#define LED1  4;

void setup() {
  // Set the LED pin as output
  pinMode(LED1, OUTPUT);
}

void loop() {
  // Blink LED1 5 times
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED1, HIGH); // Turn LED1 on
    delay(1000); // Wait for 1 second
    digitalWrite(LED1, LOW); // Turn LED1 off
    delay(1000); // Wait for 1 second
  }
  
  // Keep LED1 off for 5 seconds
  delay(5000); // Wait for 5 seconds
}
