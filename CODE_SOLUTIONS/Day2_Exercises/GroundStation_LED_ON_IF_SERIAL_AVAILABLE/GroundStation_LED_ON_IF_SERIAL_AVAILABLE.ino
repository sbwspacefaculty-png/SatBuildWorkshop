//TURN ON ONE LED IF SERIAL IS AVAILABLE - TEST WITH WHATEVER LETTER
#define LED_D1        4

void setup() {
  Serial.begin(9600);
  pinMode(LED_D1, OUTPUT);
}

void loop(){
if (Serial.available()) {
      // Turn on the LED
      digitalWrite(LED_D1, HIGH);
    } else{
      digitalWrite(LED_D1, LOW);
    }
      
}