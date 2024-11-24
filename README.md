# **HW11 Arduino Clock Using LEDs**

## **Description**
This project is an LED-based clock that visualizes the passage of time using seconds and minutes. The seconds are displayed in binary form using six LEDs, while two additional LEDs represent whether the current minute is odd or even.

### **How Seconds Are Encoded Into Lights**
- **Binary Representation of Seconds**:
  - Seconds (0–59) are represented using 6 LEDs, where each LED corresponds to a binary bit (from the least significant bit (LSB) to the most significant bit (MSB)).
  - For example:
    - Second `0`: Binary `000000` (all LEDs OFF).
    - Second `37`: Binary `100101` (LEDs 1, 3, and 6 ON).
    - Second `59`: Binary `111011` (LEDs 1, 2, 3, 5, and 6 ON).
  - The binary bits are extracted using bitwise operations in the Arduino code:
    ```cpp
    int bitValue = (currentSecond >> i) & 1;  // Extract the i-th bit
    ```

- **Odd/Even Minute LEDs**:
  - Two additional LEDs indicate whether the current minute is odd or even:
    - If the minute is odd (e.g., 1, 3, 5...), the odd-minute LED is ON.
    - If the minute is even (e.g., 0, 2, 4...), the even-minute LED is ON.
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



## **Schematic Drawing**
![Schematic Drawing](https://app.cirkitdesigner.com/project/3bca6508-02b4-48fa-b752-842b3e8803e5)

- Each LED is connected to a digital pin via a resistor.
- Pins 2–7 handle the binary representation of seconds.
- Pins 8 and 9 control the odd and even minute LEDs.


