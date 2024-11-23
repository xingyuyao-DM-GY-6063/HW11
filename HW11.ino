const int ledPins[6] = {2, 3, 4, 5, 6, 7};  // 秒数 LED 引脚
const int minuteLedPin = 8;                // 分钟切换 LED 引脚
const int oddMinuteLedPin = 9;             // 单数分钟 LED 引脚
const int evenMinuteLedPin = 10;           // 双数分钟 LED 引脚

unsigned long previousMillis = 0;
bool minuteLedState = LOW;                 // 记录分钟切换 LED 的状态

void setup() {
  // 设置秒数 LED 引脚为输出
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // 设置其他 LED 引脚为输出
  pinMode(minuteLedPin, OUTPUT);
  pinMode(oddMinuteLedPin, OUTPUT);
  pinMode(evenMinuteLedPin, OUTPUT);

  // 初始化 LED 状态
  digitalWrite(minuteLedPin, LOW);
  digitalWrite(oddMinuteLedPin, LOW);
  digitalWrite(evenMinuteLedPin, LOW);

  Serial.begin(9600);  // 启用串口监视器，用于调试
}

void loop() {
  unsigned long currentMillis = millis();
  int elapsedMinutes = (currentMillis / 1000) / 60;  // 已经过的分钟数
  int currentMinute = elapsedMinutes % 60;          // 当前分钟数（限制在 0-59）

  int currentSecond = (currentMillis / 1000) % 60;  // 当前秒数（限制在 0-59）

  // 更新秒数 LED 的二进制显示
  for (int i = 0; i < 6; i++) {
    int bitValue = (currentSecond >> i) & 1;  // 提取秒数的二进制位
    digitalWrite(ledPins[5 - i], bitValue);
  }

  // 每分钟切换分钟 LED 状态
  if (currentSecond == 0) {
    static unsigned long lastToggleMillis = 0;
    if (currentMillis - lastToggleMillis >= 1000) {  // 防止重复切换
      minuteLedState = !minuteLedState;
      digitalWrite(minuteLedPin, minuteLedState);
      lastToggleMillis = currentMillis;

      Serial.print("Minute LED toggled: ");
      Serial.println(minuteLedState);  // 输出调试信息
    }
  }

  // 更新单数和双数分钟 LED
  if (currentMinute % 2 == 0) {  // 双数分钟
    digitalWrite(oddMinuteLedPin, LOW);
    digitalWrite(evenMinuteLedPin, HIGH);
  } else {  // 单数分钟
    digitalWrite(oddMinuteLedPin, HIGH);
    digitalWrite(evenMinuteLedPin, LOW);
  }

  delay(100);
}
