//Transmit the temperature from the OBC via radio
//The output should look like: 
//[NAME OF GROUP] | TEMPOBC = 20.4

#include <SPI.h>
#include <LoRa.h>

#define PIN_OBCTEMP A1

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(434E6)) { // Set the frequency to 434 MHz
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  float reading = analogRead(PIN_OBCTEMP);
  float temp = (reading * (5100.00 / 1024.00)) / 10.00;

  // send packet
  LoRa.beginPacket();
  LoRa.print("[NAME OF GROUP] | TEMPOBC = ");
  LoRa.print(temp);
  LoRa.println("°C");
  LoRa.endPacket();

  delay(5000); // Delay for 5 seconds before sending the next packet
}
