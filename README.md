# 🚨 Ultrasonic Distance Alert System (HC-SR04)

This project uses an **HC-SR04 ultrasonic sensor** to measure distance and trigger
visual and audio alerts based on how close an object is.

- 🟢 **Green LED** turns ON when the object is at a safe distance
- 🔴 **Red LED + Buzzer** activate when the object is too close

This system can be used for **obstacle detection, parking sensors, proximity alarms,
or basic robotics projects**.

---

## 🧠 How It Works

1. The Arduino sends a **10 µs trigger pulse** to the HC-SR04 sensor.
2. The sensor emits an **ultrasonic sound wave (40 kHz)**.
3. When the wave hits an object, it reflects back to the sensor.
4. The sensor outputs an **ECHO pulse**, whose duration depends on the distance.
5. The Arduino calculates the distance using:

\[
\text{Distance} = \frac{\text{Time} \times \text{Speed of Sound}}{2}
\]

6. Based on a preset distance threshold:
   - Distance **above threshold** → Green LED ON
   - Distance **below threshold** → Red LED ON + Buzzer ON

---

## 🧰 Components Used

- Arduino Uno (or compatible)
- HC-SR04 Ultrasonic Sensor
- Green LED
- Red LED
- Buzzer
- Resistors (220 Ω for LEDs)
- Breadboard
- Jumper wires

---

## 🔌 Wiring Overview

| Component | Arduino Pin |
|---------|-------------|
| HC-SR04 TRIG | Digital Pin X |
| HC-SR04 ECHO | Digital Pin Y |
| Green LED | Digital Pin A |
| Red LED | Digital Pin B |
| Buzzer | Digital Pin C |

> 📷 See the `circuit/` folder for the wiring diagram.

---

## ⚙️ Distance Threshold

The distance threshold is defined in the code:

```cpp
const int thresholdDistance = 20; // in centimeters
