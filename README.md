# HW11
## **Arduino Clock Using LEDs**

### **Description**
This project is an LED-based clock that visualizes the passage of time using seconds and minutes. The seconds are displayed in binary form using six LEDs, while additional LEDs represent whether the current minute is odd or even and toggle a minute LED every 60 seconds.

#### **How Seconds Are Encoded Into Lights**
- **Binary Representation of Seconds**:
  - Seconds (0-59) are represented using 6 LEDs, where each LED corresponds to a binary bit (from the least significant bit (LSB) to the most significant bit (MSB)).
  - For example:
    - Second `0`: Binary `000000` (all LEDs OFF).
    - Second `37`: Binary `100101` (LEDs 1, 3, and 6 ON).
    - Second `59`: Binary `111011` (LEDs 1, 2, 3, 5, and 6 ON).
  - The binary bits are extracted using bitwise operations in the Arduino code:
    ```cpp
    int bitValue = (currentSecond >> i) & 1;  // Extract the i-th bit
    ```

- **Minute LED**:
  - An additional LED toggles ON/OFF every 60 seconds to represent the passage of a full minute.

- **Odd/Even Minute LEDs**:
  - A separate LED lights up for odd minutes, while another lights up for even minutes:
    - If the minute is odd (e.g., 1, 3, 5), the odd-minute LED is ON.
    - If the minute is even (e.g., 0, 2, 4), the even-minute LED is ON.
  - This is determined using a modulus operation:
    ```cpp
    if (currentMinute % 2 == 0) {  // Even minute
        digitalWrite(evenMinuteLedPin, HIGH);
        digitalWrite(oddMinuteLedPin, LOW);
    } else {  // Odd minute
        digitalWrite(evenMinuteLedPin, LOW);
        digitalWrite(oddMinuteLedPin, HIGH);
    }
    ```

---

### **Schematic Drawing**
Below is a simple schematic of the circuit:

```
+5V ---[220Ω]---|>|--- Pin X (LEDs for seconds 1-6)
+5V ---[220Ω]---|>|--- Pin 8 (Minute Toggle LED)
+5V ---[220Ω]---|>|--- Pin 9 (Odd Minute LED)
+5V ---[220Ω]---|>|--- Pin 10 (Even Minute LED)
                 |
                GND
```

For clarity, here's a graphical schematic:
```
          +5V
           |
    [220Ω] |---|>|--- Pin 2 (LSB of Seconds)
           |---|>|--- Pin 3
           |---|>|--- Pin 4
           |---|>|--- Pin 5
           |---|>|--- Pin 6
           |---|>|--- Pin 7 (MSB of Seconds)
           |---|>|--- Pin 8 (Minute Toggle)
           |---|>|--- Pin 9 (Odd Minute)
           |---|>|--- Pin 10 (Even Minute)
           |
          GND
```

- Each LED is connected to a digital pin via a 220Ω resistor.
- Pins 2-7 handle the binary representation of seconds.
- Pins 8, 9, and 10 control the additional minute-related LEDs.

---

### **How to Run**
1. **Connect the Circuit**:
   - Follow the schematic to connect your LEDs to the Arduino board.
   - Use pins `2-7` for the seconds LEDs, `8` for the minute toggle, `9` for odd minutes, and `10` for even minutes.

2. **Upload Code**:
   - Upload the Arduino sketch to your board.

3. **Observe Behavior**:
   - LEDs 2-7 display the seconds in binary form.
   - LED 8 toggles ON/OFF every minute.
   - LED 9 lights up for odd minutes, and LED 10 lights up for even minutes.

---


