//This program reads the temperature from the OBC Sensor

#define PIN_OBCTEMP A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A1);
  float temp = (reading * (5100.00 / 1024.00)) / 10.00;

  Serial.print("OBC Temp is: ");
  Serial.print(temp);
  Serial.println("°C");

  delay(2000); // Delay for 2 seconds before next temperature reading
}
