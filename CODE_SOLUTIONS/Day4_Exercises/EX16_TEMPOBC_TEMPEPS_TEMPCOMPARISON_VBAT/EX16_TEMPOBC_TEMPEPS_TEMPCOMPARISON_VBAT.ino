#define PIN_OBCTEMP A1
#define PIN_EPSTEMP A2
#define PIN_VBAT A0

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
    } else if (keyboardInput == "TEMPCOMPARISON") {
      maxTemp();
    } else if (keyboardInput == "VBAT") {
      readVBAT();
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

void maxTemp() {
  float obcReading = analogRead(PIN_OBCTEMP);
  float obcTemp = (obcReading * (5100.00 / 1024.00)) / 10.00;
  float epsReading = analogRead(PIN_EPSTEMP);
  float epsTemp = (epsReading * (5100.00 / 1024.00)) / 10.00;
  
  float tempDiff = abs(obcTemp - epsTemp);
  
  if (obcTemp > epsTemp) {
    Serial.print("TEMPOBC is greater than TEMPEPS - Difference = ");
    Serial.print(tempDiff);
    Serial.println("°C");
  } else if (epsTemp > obcTemp) {
    Serial.print("TEMPEPS is greater than TEMPOBC - Difference = ");
    Serial.print(tempDiff);
    Serial.println("°C");
  } else {
    Serial.println("Both temperatures are equal");
  }
}

void readVBAT() {
  float vbat = analogRead(PIN_VBAT) * (5.10 / 1023.00);
  Serial.print("Battery voltage: ");
  Serial.print(vbat);
  Serial.println("V");
}
