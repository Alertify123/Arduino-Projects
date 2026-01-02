# Project 03: Love-O-Meter

This project measures your body temperature using an analog sensor and visually displays "how hot" you are using a set of three LEDs. It is based on **Project 03** from the [Arduino Projects Book](https://www.eitkw.com/wp-content/uploads/2020/03/Arduino_Projects_Book.pdf).

## 📖 Overview
The goal of this project is to convert a physical change (temperature) into a digital display. The Arduino reads a continuous analog signal from a sensor, converts it to a digital value, calculates the temperature in Celsius, and lights up LEDs as the temperature rises above a specific baseline.

## 🛠 Hardware Required
* **1x** Arduino Board (Uno, Leonardo, etc.)
* **1x** Temperature Sensor (TMP36 or equivalent)
* **3x** LEDs (Red)
* **3x** 220-ohm Resistors
* **1x** Breadboard & Jumper Wires

## 🔌 Circuit Connections
Based on the code configuration:

| Component | Pin on Arduino | Description |
| :--- | :--- | :--- |
| **Temp Sensor** | `A0` | Analog Input Pin  |
| **LED 1** | `Pin 2` | Digital Output (Low Heat)  |
| **LED 2** | `Pin 3` | Digital Output (Medium Heat)  |
| **LED 3** | `Pin 4` | Digital Output (High Heat)  |

## 💻 Code Explanation

### 1. Variables & Setup
We define a constant `sensorPin` for the analog input and a `baselineTemp` of **24.0°C**.
In the `setup()`, we initialize the Serial Monitor at **9600 baud** to view data on the computer and set the LED pins (2, 3, 4) as **OUTPUTS**.

### 2. Analog Sensing
In the `loop()`, the code reads the state of the temperature sensor:
```cpp
int sensorVal = analogRead(sensorPin);
```
### 3. The Math (Voltage to Degrees)
To get the real temperature, we perform two conversions:
1. **ADC to Voltage:** We convert the 0-1023 reading back to 0.0-5.0 Volts.

   ```cpp
   float voltage = (sensorVal/1024.0) * 5.0;
   ```
2. **Voltage to Temperature:** We convert volts to degrees Celsius. The offset of `0.5` accounts for the sensor's offset (500mV at 0°C), and we multiply by 100 because the sensor scales at 10mV per degree.
```cpp
float temperature = (voltage - 0.5) * 100;
```
### 4. Logic Control
The LEDs light up based on how far the temperature rises above the `baselineTemp` (27°C):
* **< 24°C:** All LEDs OFF.
* **26°C - 28°C:** 1 LED ON (Pin 2).
* **28°C - 30°C:** 2 LEDs ON (Pins 2 & 3).
* **> 30°C:** 3 LEDs ON (Pins 2, 3 & 4).

<h3>The Logic & The Demo</h3>
<table>
  <tr>
    <th width="50%">The Logic (Snippet)</th>
    <th width="50%">The Demo</th>
  </tr>
  <tr>
    <td valign="top">
      <p>The code checks if the temperature exceeds the baseline. As it gets hotter, we turn on more digital pins.</p>
      <pre lang="cpp">
// Logic Control for LEDs
if(temperature < baselineTemp){
  // Cold: All OFF
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
} else if (temperature >= baselineTemp + 2 && 
           temperature < baselineTemp + 4){
  // Warm: 1 LED ON
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
} else if (temperature >= baselineTemp + 6){
  // Hot: All ON
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
}</pre>
    </td>
    <td valign="top">
      <br>
      <video src="https://github.com/user-attachments/assets/e8a22688-aad1-4287-a9a9-3ab94e8411dd" controls="controls" style="max-width: 100%;">
      </video>
    </td>
  </tr>
</table>  
