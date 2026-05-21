#define PIN_OBCTEMP A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove leading and trailing whitespace

    if (command.equals("TEMPOBC")) {
      int reading = analogRead(A1);
      float temp = (reading * (5100.00 / 1024.00)) / 10.00;

      Serial.print("OBC Temp is: ");
      Serial.print(temp);
      Serial.println("°C");
    }
  }
}
