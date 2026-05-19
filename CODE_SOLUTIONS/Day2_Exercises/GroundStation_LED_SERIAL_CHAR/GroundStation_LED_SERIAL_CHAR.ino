//TURN ON ONE LED VIA SERIAL WITH CHAR
#define LED_D1 4

void setup() {
  Serial.begin(9600);
  pinMode(LED_D1, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming byte
    char command = Serial.read();

    // Check the received command
    if (command == '1') {
      // Turn on the LED
      digitalWrite(LED_D1, HIGH);
    } else if (command == '0') {
      // Turn off the LED
      digitalWrite(LED_D1, LOW);
    }
  }
}