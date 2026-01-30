# 🚨 Ultrasonic Distance Alert System (HC-SR04)

An embedded systems project that uses an **HC-SR04 ultrasonic sensor** to measure the distance of nearby objects and trigger **visual (LEDs)** and **audio (buzzer)** alerts based on predefined safety thresholds.

This project demonstrates **basic sensor interfacing, timing-based distance calculation, and decision logic** using an Arduino.

---

## 🧠 System Overview

The system continuously measures the distance between the sensor and an obstacle:

- 🟢 **Green LED** → Object is at a safe distance  
- 🔴 **Red LED + Buzzer** → Object is too close  
- ❌ **No echo received** → Object is out of range

Distance measurement is based on the **time-of-flight** of ultrasonic sound waves.

---

## ⚙️ How It Works

1. The Arduino sends a **10 µs trigger pulse** to the HC-SR04 sensor.
2. The sensor emits an ultrasonic wave at **40 kHz**.
3. The wave reflects off an object and returns to the sensor.
4. The sensor outputs a HIGH pulse on the **ECHO pin**.
5. The duration of this pulse is used to calculate distance:

\[
\text{Distance (cm)} = \frac{\text{Echo Time (µs)} \times 0.034}{2}
\]

6. The system compares the measured distance with a preset safety threshold and reacts accordingly.

---

## 🧰 Components Used

- Arduino Uno (or compatible)
- HC-SR04 Ultrasonic Sensor
- Green LED
- Red LED
- Active buzzer
- 220 Ω resistors (for LEDs)
- Breadboard
- Jumper wires

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
|--------|-------------|
| HC-SR04 TRIG | 11 |
| HC-SR04 ECHO | 10 |
| Green LED | 6 |
| Red LED | 3 |
| Buzzer | 9 |

---

## 📏 Distance Thresholds

```cpp
const int SAFE_DISTANCE = 40; // centimeters
