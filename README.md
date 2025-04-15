# 🚗 Wi-Fi Controlled RC Car – Torque 4.0 Project

A NodeMCU-based, Wi-Fi-enabled RC car built for **Torque 4.0**, organized by the **Phoenix Robotics Club, LNMIIT**. This 4WD bot is controlled through a mobile web interface and responds to directional commands via HTTP requests.

---

## 📌 Overview

This project demonstrates the use of the **ESP8266 (NodeMCU)** microcontroller to control a robotic car over Wi-Fi. Commands are sent from a mobile app/web interface, and the bot responds with corresponding movements like forward, backward, left, and right. LEDs indicate the current motion state.

---

## 🧠 Features

- 📱 Controlled via mobile phone through a Wi-Fi hotspot
- 🔁 Real-time movement handling: forward, reverse, left, right
- 🎚️ Variable speed control using different request types
- 🚥 LED indicators for direction and status feedback
- ⚙️ GPIO interfacing for motor and LED control

---

## 🛠️ Hardware Components

- NodeMCU ESP8266
- L298N Motor Driver
- BO Motors (4)
- Chassis + Wheels
- Li-ion Battery
- LED Indicators (Green, Red, Yellow)
- Jumper Wires
- Buck Converter (for power regulation)

---

## 📡 How It Works

1. The ESP8266 creates a local Wi-Fi hotspot (SSID: `Mars Rover`, Password: `Spacex23`)
2. Mobile device connects to the hotspot and sends HTTP GET requests (e.g., `/move?dir=forward`)
3. Based on the request:
   - Motors are controlled via PWM signals
   - Directional movement is executed
   - LEDs provide visual cues
4. Speed levels are adjusted via `/action?type=1`, `/action?type=2`, etc.

---

## 📄 Code Structure

Main logic is written in Arduino-compatible C++. It handles:
- HTTP parsing
- Motor control logic
- Speed switching
- LED feedback

```cpp
WiFi.softAP("Mars Rover", "Spacex23");  // Creates access point
analogWrite(l1, speed);  // Moves left motor forward
analogWrite(r1, speed);  // Moves right motor forward
