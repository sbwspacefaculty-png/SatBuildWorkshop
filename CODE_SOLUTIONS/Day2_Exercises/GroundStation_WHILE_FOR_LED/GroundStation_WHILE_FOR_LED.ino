#define LED1  4
int blinkCount = 0; //Initialise the counter

void setup() {
  // Set the LED pin as output
  pinMode(LED1, OUTPUT);
}

void loop() {
  
  // Keep the loop running until blinkCount is less than 1
  while (blinkCount < 1) {
    // Blink LED1 5 times
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED1, HIGH); // Turn LED1 on
      delay(1000); // Wait for 1 second
      digitalWrite(LED1, LOW); // Turn LED1 off
      delay(1000); // Wait for 1 second
    }
    blinkCount++; // Increment blink count
  }
  digitalWrite(LED1, LOW);
}