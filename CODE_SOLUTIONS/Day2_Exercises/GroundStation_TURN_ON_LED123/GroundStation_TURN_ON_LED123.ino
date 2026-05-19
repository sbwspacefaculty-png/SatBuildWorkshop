//THIS PROGRAM TURNS ON LED1, LED2 and LED3 ON THE ARDUINO NANO GROUND STATION

#define LED1 4
#define LED2 6
#define LED3 8

void setup() {
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);

}