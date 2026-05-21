#include <SPI.h>
#include <LoRa.h>

int elapsedTimeSeconds = 0;  // Variable to store the elapsed time in seconds
int elapsedTimeMinutes = 0;  // Variable to store the elapsed time in minutes

void setup() {
  Serial.begin(9600);  // Initialize serial communication

  Serial.println("LoRa Sender");

  if (!LoRa.begin(434E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // Counter part
  delay(1000); // Delay for 1 second
  elapsedTimeSeconds++; // Increment the elapsed time in seconds

  if (elapsedTimeSeconds == 60) {
    elapsedTimeSeconds = 0;  // Reset seconds
    elapsedTimeMinutes++; // Increment the elapsed time in minutes
  }

  // LoRa part
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n'); // Read a line from Serial
    message.trim(); // Remove leading and trailing whitespace

    // send packet
    LoRa.beginPacket();
    LoRa.print("[");
    LoRa.print(elapsedTimeMinutes);
    LoRa.print("m ");
    LoRa.print(elapsedTimeSeconds);
    LoRa.print("s] ");
    LoRa.print(message);
    LoRa.endPacket();
  }
}
