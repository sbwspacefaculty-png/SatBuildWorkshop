//This code is an example of how to request the time via the keyboard input "T"

int elapsedTimeSeconds = 0;  // Variable to store the elapsed time in seconds
int elapsedTimeMinutes = 0;  // Variable to store the elapsed time in minutes

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Check if serial data is available
  if (Serial.available() > 0) {
    // Read the incoming byte
    char keyboardInput = Serial.read();
    // Check if the incoming byte is 'T'
    if (keyboardInput == 'T') {
      // Display the elapsed time
      Serial.print("TIME = ");
      Serial.print(elapsedTimeMinutes);
      Serial.print("m ");
      Serial.print(elapsedTimeSeconds);
      Serial.println("s");
    }
  }

  // Delay for 1 second
  delay(1000);

  // Increment the elapsed time in seconds
  elapsedTimeSeconds++;

  // Check if 1 minute has passed
  if (elapsedTimeSeconds == 60) {
    // Reset seconds and increment minutes
    elapsedTimeSeconds = 0;
    elapsedTimeMinutes++;
  }
}
