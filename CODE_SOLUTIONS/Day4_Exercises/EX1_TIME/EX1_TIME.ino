//This program displays the elapsed time since the OBC is turned on by incrementing a variable by 1 each second
//This is just an example, you can also use the millis() function

int elapsedTime = 0;  // Variable to store the elapsed time in seconds

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  delay(1000); // Delay for 1 second

  elapsedTime++; // Increment the elapsed time

  Serial.print("TIME = ");
  Serial.print(elapsedTime);
  Serial.println("s");
}
