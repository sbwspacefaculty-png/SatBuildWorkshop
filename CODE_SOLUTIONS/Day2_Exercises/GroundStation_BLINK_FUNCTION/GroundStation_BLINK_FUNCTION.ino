// Define the pins for the LEDs
#define LED1  4
#define LED2  6
#define LED3  8

void setup() {
  // Set the LED pins as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // Call the blink function with a delay of 500 milliseconds
  blink(500);
}

// Blink function definition
void blink(int delayDuration) {
  // Turn all LEDs on
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(delayDuration);  // Wait for the specified duration

  // Turn all LEDs off
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(delayDuration);  // Wait for the specified duration
}
