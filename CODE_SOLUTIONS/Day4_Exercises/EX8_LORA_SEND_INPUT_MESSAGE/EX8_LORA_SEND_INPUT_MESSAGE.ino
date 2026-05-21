//THIS PROGRAM SENDS A MESSAGE THAT YOU TYPE VIA SERIAL THROUGH THE LORA RADIO MODULE

#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(434E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n'); // Read a line from Serial
    message.trim(); // Remove leading and trailing whitespace

    Serial.print("Sending packet: ");
    Serial.println(message);

    // send packet
    LoRa.beginPacket();
    LoRa.println(message);
    LoRa.endPacket();
  }

  delay(1000); // Delay to avoid continuous reading from Serial
}
