#define LED_PIN 2  

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("ESP32 READY");
}

void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  }
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();

    if (ch >= '1' && ch <= '4') {
      blinkLED(ch - '0');
    }
  }
}
