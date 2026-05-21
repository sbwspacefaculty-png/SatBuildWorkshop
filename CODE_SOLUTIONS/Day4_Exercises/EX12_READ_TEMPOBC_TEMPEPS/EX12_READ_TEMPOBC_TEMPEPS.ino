//This code reads both TEMPEPS and TEMPOBC and you can call them via serial input

#define PIN_OBCTEMP A1
#define PIN_EPSTEMP A2

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String keyboardInput = Serial.readStringUntil('\n');
    keyboardInput.trim();
    if (keyboardInput == "TEMPOBC") {
      readTEMPOBC();
    } else if (keyboardInput == "TEMPEPS") {
      readTEMPEPS();
    }
  }
}

void readTEMPOBC() {
  float obcReading = analogRead(PIN_OBCTEMP);
  float obcTemp = (obcReading * (5100.00 / 1024.00)) / 10.00;
  
  Serial.print("TEMPOBC: ");
  Serial.print(obcTemp);
  Serial.println("°C");
}

void readTEMPEPS() {
  float epsReading = analogRead(PIN_EPSTEMP);
  float epsTemp = (epsReading * (5100.00 / 1024.00)) / 10.00;
  
  Serial.print("TEMPEPS: ");
  Serial.print(epsTemp);
  Serial.println("°C");
}
