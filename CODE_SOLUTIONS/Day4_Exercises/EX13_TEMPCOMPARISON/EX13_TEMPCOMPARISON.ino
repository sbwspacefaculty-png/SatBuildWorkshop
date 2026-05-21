//Create a function, maxTemp(), that compares two temperatures. Invoke the function by entering 'TEMPCOMPARISON' via serial.

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
    } else if (keyboardInput == "TEMPCOMPARISON") {
      maxTemp();
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
  
  if (obcTemp > epsTemp) {
    Serial.println("TEMPOBC is greater than TEMPEPS");
  } else if (epsTemp > obcTemp) {
    Serial.println("TEMPEPS is greater than TEMPOBC");
  } else {
    Serial.println("Both temperatures are equal");
  }
}
