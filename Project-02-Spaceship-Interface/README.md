# Project 02: Spaceship Interface

**Source:** Arduino Projects Book (Pages 32-41)

## Description
This project creates a "control panel" for a spaceship. It demonstrates the use of digital inputs and outputs to control LEDs based on a user action.
* **Standby Mode:** When the button is released, the system is "Ready" (Green LED is ON).
* **Engaged Mode:** When the button is pressed, the system "Engages" (Green LED OFF, Red LEDs flash alternately).

## Circuit Components
* **1x Arduino Uno**
* **1x Breadboard**
* **3x LEDs** (1 Green, 2 Red)
* **3x 220Ω Resistors** (Current limiting for LEDs)
* **1x Pushbutton**
* **1x 10kΩ Resistor** (Pull-down)

## Key Learning Points
### 1. The Pull-Down Resistor
This project introduced the concept of a **pull-down resistor**. Without the 10kΩ resistor connecting the button pin to Ground, the pin would be "floating" (picking up random electrical noise) when the button is open. The resistor ensures the pin reads a clean `0` (LOW) until the button connects it to 5V.

### 2. Digital I/O Logic
I used variables to store the state of the button:
```cpp
int switchState = 0;
switchState = digitalRead(2); // Checks if voltage is present
```
### 3. Conditional Logic
The code uses an if/else statement to determine which mode the ship is in:
* **if (switchState == LOW):** Green LED acts as a "Ready" indicator.
* **else:** The delay(250) function creates a simple blinking animation for the Red LEDs.

<table>
  <tr>
    <th width="50%">The Logic (Snippet)</th>
    <th width="50%">The Demo</th>
  </tr>
  <tr>
    <td valign="top">
<pre>
// Check if button is pressed
switchState = digitalRead(2);

if(switchState == LOW){
  // Button NOT pressed
  // Green LED ON
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
else{
  // Button IS pressed
  // Toggle Red LEDs
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  
  delay(250); // Wait
  
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(250); // Wait
}
</pre>
    </td>
    <td valign="top">
      <video src="https://github.com/user-attachments/assets/8addf695-d783-4024-8d30-ab2893f28854" controls="controls" style="max-width: 100%;">
      </video>
    </td>
  </tr>
</table>
