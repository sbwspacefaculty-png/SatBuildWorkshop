//TURN ON ONE LED VIA SERIAL WITH STRING
#define LED_D1 4

void setup() {
  Serial.begin(9600);
  pinMode(LED_D1, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming byte
    String command = Serial.readStringUntil('\n');
    command.trim(); //Cuts the string when you click RETURN (\n)

    // Check the received command
    if (command.equals("ON")) {
      // Turn on the LED
      digitalWrite(LED_D1, HIGH);
    } else if (command.equals("OFF")) {
      // Turn off the LED
      digitalWrite(LED_D1, LOW);
    }
  }
}