//This program is an example of how to set up a MINUTES and SECONDS counter

int elapsedTimeSeconds = 0;  // Variable to store the elapsed time in seconds
int elapsedTimeMinutes = 0;  // Variable to store the elapsed time in minutes

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  delay(1000); // Delay for 1 second

  elapsedTimeSeconds++; // Increment the elapsed time in seconds

  if (elapsedTimeSeconds == 60) {
    elapsedTimeSeconds = 0;  // Reset seconds
    elapsedTimeMinutes++; // Increment the elapsed time in minutes
  }

  Serial.print("TIME = ");
  Serial.print(elapsedTimeMinutes);
  Serial.print("m ");
  Serial.print(elapsedTimeSeconds);
  Serial.println("s");
}
