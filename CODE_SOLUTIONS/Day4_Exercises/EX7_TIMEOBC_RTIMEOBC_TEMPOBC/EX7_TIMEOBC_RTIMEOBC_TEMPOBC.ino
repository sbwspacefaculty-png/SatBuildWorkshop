#define PIN_OBCTEMP A1

int elapsedTimeSeconds = 0;
int elapsedTimeMinutes = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000); // Delay for 1 second

  elapsedTimeSeconds++;
  if (elapsedTimeSeconds >= 60) {
    elapsedTimeSeconds = 0;
    elapsedTimeMinutes++;
  }

  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove leading and trailing whitespace

    if (command.equals("TIMEOBC")) {
      getTimeOBC();
    } else if (command.equals("RTIMEOBC")) {
      resetTimeOBC();
    } else if (command.equals("TEMPOBC")) {
      getTempOBC();
    }
  }
}

void getTimeOBC() {
  // Function to get and print the current time of OBC
  Serial.print("TIMEOBC: ");
  Serial.print(elapsedTimeMinutes);
  Serial.print("m ");
  Serial.print(elapsedTimeSeconds);
  Serial.println("s");
}

void resetTimeOBC() {
  // Function to reset the time of OBC
  elapsedTimeSeconds = 0;
  elapsedTimeMinutes = 0;
  Serial.println("OBC time has been reset.");
}

void getTempOBC() {
  // Function to get and print the temperature of OBC
  int reading = analogRead(A1);
  float temp = (reading * (5100.00 / 1024.00)) / 10.00;

  Serial.print("TEMPOBC: ");
  Serial.print(temp);
  Serial.println("°C");
}
