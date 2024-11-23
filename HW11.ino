const int ledPins[6] = {2, 3, 4, 5, 6, 7};  // Pins connected to the LEDs
unsigned long previousMillis = 0;

void setup() {
  // Set all pins as outputs
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Calculate the current second using millis()
  unsigned long currentMillis = millis();
  int currentSecond = (currentMillis / 1000) % 60;  // Wall seconds [0-59]

  // Display the binary representation of the second
  for (int i = 0; i < 6; i++) {
    int bitValue = (currentSecond >> i) & 1;  // Extract each bit
    digitalWrite(ledPins[5 - i], bitValue);  // Update LEDs (MSB to LSB)
  }

  // Optional: Add a delay to make the LEDs more stable visually
  delay(100);
}
