# Project 04: Color Mixing Lamp

This project uses three light sensors (photoresistors) to control the color of an RGB LED. By covering or exposing the sensors to light, you can mix red, green, and blue light to create custom colors. It is based on **Project 04** from the [Arduino Projects Book](https://www.eitkw.com/wp-content/uploads/2020/03/Arduino_Projects_Book.pdf).

## 📖 Overview
The goal of this project is to use analog inputs to control Pulse Width Modulation (PWM) outputs. The Arduino reads the light levels hitting three separate sensors (representing Red, Green, and Blue channels) and adjusts the brightness of the corresponding LED colors in real-time.

## 🛠 Hardware Required
* **1x** Arduino Board (Uno, Leonardo, etc.)
* **1x** RGB LED (Common Cathode) or 3x Individual LEDs (Red, Green, Blue)
* **3x** Photoresistors (Light Sensors)
* **3x** 10k-ohm Resistors (for the sensors)
* **3x** 220-ohm Resistors (for the LEDs)
* **1x** Breadboard & Jumper Wires

## 🔌 Circuit Connections
Based on the code configuration:

| Component | Pin on Arduino | Description |
| :--- | :--- | :--- |
| **Red Sensor** | `A0` | Analog Input |
| **Green Sensor** | `A1` | Analog Input |
| **Blue Sensor** | `A2` | Analog Input |
| **Green LED** | `Pin 9` | PWM Output (Note: `~` pin) |
| **Red LED** | `Pin 10` | PWM Output (Note: `~` pin) |
| **Blue LED** | `Pin 11` | PWM Output (Note: `~` pin) |

## 💻 Code Explanation

### 1. Variables & Setup
We define constants for the pins to make the code readable. In `setup()`, we configure the digital pins as **OUTPUTS**.
* **Note:** We do not need to configure `A0`-`A2` because analog pins are Inputs by default.

### 2. Reading the Sensors (Input)
In the `loop()`, we read the ambient light level for each color channel.
* **Why the delay?** The code includes `delay(5)` between reads. This gives the Arduino's ADC (Analog-to-Digital Converter) a tiny moment to stabilize when switching between different pins.

```cpp
redSensorValue = analogRead(redSensorPin);
delay(5);
greenSensorValue = analogRead(greenSensorPin);
```
### 3. The Math
The sensor and the LED operate on different scales:
* **Input(Sensor):** Returns a value between 0 and 1023.
* **Output (LED):** Accepts a value between 0 and 255.
To fix this, we divide the sensor value by 4.
```cpp
// 1023 / 4 = ~255
redValue = redSensorValue / 4;
greenValue = greenSensorValue / 4;
blueValue = blueSensorValue / 4;
```
### 4. Changing the light (Output)
Finally, we update the LED brightness. This happens inside the `loop()` so the light changes instantly as you move your hands over the sensors.
```cpp
analogWrite(redLEDPin, redValue);
analogWrite(greenLEDPin, greenValue);
analogWrite(blueLEDPin, blueValue);
```
## 🧠 Key Concept: Pulse Width Modulation (PWM)
Even though the Arduino is a digital device (on/off), we can simulate analog "fading" using `analogWrite()`. This pulses the pin on and off very fast.
* **0:** Always off (0V)
* **127:** On 50% of the time (approx 2.5V)
* **255:** Always On (5V)
