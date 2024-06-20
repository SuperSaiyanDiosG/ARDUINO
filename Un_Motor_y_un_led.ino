const int ledPin = 13;
const int motorPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'A':
        digitalWrite(ledPin, HIGH);
        break;
      case 'a':
        digitalWrite(ledPin, LOW);
        break;
      case 'M':
        analogWrite(motorPin, 255);
        break;
      case 'm':
        analogWrite(motorPin, 0);
        break;
      default:
        Serial.println("SISTEMA ON/OFF");
    }
  }
}
