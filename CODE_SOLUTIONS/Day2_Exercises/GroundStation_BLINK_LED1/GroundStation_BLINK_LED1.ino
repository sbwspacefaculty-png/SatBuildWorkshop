//THIS PROGRAM BLINK LED1 ON THE ARDUINO NANO GROUND STATION

#define LED1 4
void setup() {
pinMode(LED1, OUTPUT);

}

void loop() {
  delay(500);
  digitalWrite(LED1, HIGH);
  delay(500);

}
