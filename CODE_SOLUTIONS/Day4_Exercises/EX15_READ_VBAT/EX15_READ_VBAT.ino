//How to read the battery voltage (VBAT) 

#define PIN_VBAT A0

void setup() {

  Serial.begin(9600);
}

void loop() {

  float vbat = analogRead(A0);
  vbat = vbat * (5.10 / 1023.00);
  Serial.print("Battery voltage: ");
  Serial.print(vbat);
  Serial.println("V");

  delay (5000);
}
