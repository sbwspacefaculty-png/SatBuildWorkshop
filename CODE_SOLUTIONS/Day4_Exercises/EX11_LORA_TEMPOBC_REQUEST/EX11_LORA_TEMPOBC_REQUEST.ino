#include <SPI.h>
#include <LoRa.h>

#define PIN_OBCTEMP A1

void setup() {
  Serial.begin(9600);
  
  Serial.println("LoRa Sender");
  
  if (!LoRa.begin(434E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    if (input == "TEMPOBC") {
      float reading = analogRead(PIN_OBCTEMP);
      float temp = (reading * (5100.00 / 1024.00)) / 10.00;
      
      LoRa.beginPacket();
      LoRa.print("[NAME OF GROUP] | TEMPOBC = ");
      LoRa.print(temp);
      LoRa.println(" deg");
      LoRa.endPacket();
    }
  }
  
  // Add other code here if needed
  
  delay(100); // Delay for debounce and to allow other tasks
}
