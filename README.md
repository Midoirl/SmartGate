
# SmartGate 🚗🔓

**SmartGate** is a compact Arduino-based entry system that detects incoming vehicles using an ultrasonic sensor, opens a mini gate with a servo motor, and greets users via a 16x2 LCD display. It includes visual (LED) and auditory (buzzer) feedback to simulate a real-world smart parking gate. Ideal for learning automation and embedded systems.

---

## 🎯 Features
- Ultrasonic distance sensing for vehicle detection
- Automatic gate control using a servo motor
- LCD welcome message with character-by-character animation
- Buzzer alert and LED indication upon detection
- Smooth gate opening and closing motion
- Clean, well-commented code with modular functions

---

## 🧠 How It Works
1. **Idle State**: LCD displays “Awaiting Entry...”
2. **Vehicle Detected (<20 cm)**:
   - LED lights up
   - Buzzer beeps once
   - LCD displays a welcome message
   - Gate smoothly opens and closes
3. Returns to idle state, awaiting the next vehicle.

---

## 🧩 Hardware Components
| Component           | Quantity |
|---------------------|----------|
| Arduino Uno         | 1        |
| HC-SR04 Ultrasonic Sensor | 1  |
| SG90 Servo Motor    | 1        |
| 16x2 I2C LCD Display| 1        |
| Buzzer              | 1        |
| Green LED           | 1        |
| 220Ω Resistor (for LED) | 1   |
| Breadboard + Wires  | As needed |

---

## 🛠️ Circuit Schematic
[📄 View PDF Schematic](SmartGate_Schematic.pdf)

---

## 💾 Code
The full Arduino `.ino` file is in this repo:
- [`SmartGate.i.ino`](SmartGate.i.ino)

---

## Demo

🎬 **Click here to watch the video demo**  
[▶️ Watch on Google Drive](https://drive.google.com/file/d/1yDplklDpdX-9Eut-AjtAmjA7VQzlC_tD/view?usp=drive_link)
---

## 📦 Setup
1. Upload the `SmartGate.i.ino` to your Arduino Uno using the Arduino IDE.
2. Wire your components based on the schematic.
3. Power up the Arduino. The LCD will display “Awaiting Entry...”
4. Move an object (like your hand) within 20 cm of the ultrasonic sensor to trigger the gate.

---

## 📌 Notes
- Adjust the `threshold` value in the code if needed.
- Use a proper power source for the servo if you notice jittering.
- You can modify the LCD messages to match your environment.

---

##  Author
 Mahmod Kirresh 

---

##  License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

