const int ledPins[6] = {2, 3, 4, 5, 6, 7};  
const int oddMinuteLedPin = 8;            
const int evenMinuteLedPin = 9;           

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(oddMinuteLedPin, OUTPUT);
  pinMode(evenMinuteLedPin, OUTPUT);


  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  digitalWrite(oddMinuteLedPin, LOW);
  digitalWrite(evenMinuteLedPin, LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  int elapsedMinutes = (currentMillis / 1000) / 60;  // 已经过的分钟数
  int currentMinute = elapsedMinutes % 60;          // 当前分钟数（限制在 0-59）

  int currentSecond = (currentMillis / 1000) % 60;  // 当前秒数（限制在 0-59）

  // Update the binary display of the seconds LED
  for (int i = 0; i < 6; i++) {
    int bitValue = (currentSecond >> i) & 1;  // 提取秒数的二进制位
    digitalWrite(ledPins[5 - i], bitValue);  // 更新对应 LED 的状态
  }

  // Updated odd and even minute LEDs
  if (currentMinute % 2 == 0) {  // 双数分钟
    digitalWrite(oddMinuteLedPin, LOW);
    digitalWrite(evenMinuteLedPin, HIGH);
  } else {  // 单数分钟
    digitalWrite(oddMinuteLedPin, HIGH);
    digitalWrite(evenMinuteLedPin, LOW);
  }

  delay(100);  
}
