<div align="center">
  <h1>🚄 Smart Railway Platform Crowd Monitoring and Safety Alert System</h1>
  <p>An IoT-based Mini Project using ESP32 for monitoring crowd density and ensuring safety on railway platforms.</p>
  
  [![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/ansari6926/DPSM_miniproject/blob/main/LICENSE)
  [![Wokwi Simulation](https://img.shields.io/badge/Wokwi-Simulation%20Ready-brightgreen)](https://wokwi.com/)
  [![C++](https://img.shields.io/badge/Language-C++-00599C.svg)](https://isocpp.org/)
</div>

---

## 📌 Project Overview
The **Smart Railway Platform Crowd Monitoring and Safety Alert System** is an industrial IoT solution built to prevent overcrowding on railway platforms, which can lead to stampedes or accidents. The system utilizes an **ESP32** microcontroller, an **Ultrasonic Sensor** for estimating crowd density, and a **PIR Motion Sensor** for detecting movement. It provides real-time status updates via an **OLED display** and local alerts using **LEDs** and a **Buzzer**.

This project is professionally structured for university submission and portfolio showcasing, focusing on safety automation and IoT integration.

## ✨ Features
- **Real-time Crowd Estimation**: Uses ultrasonic proximity sensing to simulate and estimate crowd density.
- **Motion Detection**: Employs a PIR sensor to track active movement in restricted or platform zones.
- **Visual & Audio Alerts**:
  - 🟢 **Green LED**: Safe (Low Crowd)
  - 🟡 **Yellow LED**: Warning (Medium Crowd)
  - 🔴 **Red LED + Buzzer**: Danger (Overcrowded)
- **Live Status Dashboard**: 128x64 OLED display providing on-site status analytics.
- **Serial Monitor Analytics**: Continuous data logging for backend monitoring.
- **Cloud/IoT Ready**: Based on ESP32, which allows future expansion to Wi-Fi/MQTT-based cloud dashboards.

## 🛠️ Technologies & Hardware Used
- **Microcontroller**: ESP32 DevKitC V4
- **Sensors**: 
  - HC-SR04 Ultrasonic Sensor
  - PIR Motion Sensor
- **Actuators/Display**:
  - SSD1306 128x64 I2C OLED Display
  - 5mm LEDs (Green, Yellow, Red)
  - Piezo Buzzer
- **Software/Tools**:
  - Arduino IDE (C++ Code)
  - Wokwi IoT Simulator

## 🔌 Circuit Explanation & Pin Mapping
| Component | ESP32 Pin | Description |
|-----------|-----------|-------------|
| **HC-SR04 TRIG** | GPIO 5 | Sends ultrasonic pulse |
| **HC-SR04 ECHO** | GPIO 18 | Receives echo pulse |
| **PIR Sensor OUT** | GPIO 19 | Digital motion signal |
| **Green LED** | GPIO 25 | Safe indication |
| **Yellow LED** | GPIO 26 | Warning indication |
| **Red LED** | GPIO 27 | Danger indication |
| **Buzzer** | GPIO 14 | Overcrowding alarm |
| **OLED SDA** | GPIO 21 | I2C Data |
| **OLED SCL** | GPIO 22 | I2C Clock |

## 🚀 Setup & Simulation Instructions

### Running in Wokwi (Recommended)
1. Navigate to the `circuit/` folder of this repository.
2. Open [Wokwi](https://wokwi.com/) and create a new ESP32 project.
3. Replace the contents of `diagram.json` in Wokwi with the provided `circuit/diagram.json`.
4. Copy the code from `code/esp32_project.ino` into your `sketch.ino` file in Wokwi.
5. Ensure you have added the required libraries (`Adafruit GFX Library`, `Adafruit SSD1306`) in the Library Manager or `libraries.txt`.
6. Click the **Play** button to start the simulation.
7. Click on the PIR sensor to simulate motion.
8. Click on the Ultrasonic sensor and adjust the distance slider to change the crowd density level.

### Hardware Setup
1. Connect the components to the ESP32 according to the Pin Mapping table.
2. Install the **Arduino IDE** and the **ESP32 Board Package**.
3. Install the `Adafruit_GFX` and `Adafruit_SSD1306` libraries via the Library Manager.
4. Open `code/esp32_project.ino`, select your COM port and ESP32 board.
5. Compile and upload the code.

## 🔮 Future Enhancements
- **Wi-Fi Integration**: Send live crowd data to cloud dashboards like ThingSpeak or Blynk.
- **Computer Vision**: Replace the ultrasonic sensor with an ESP32-CAM for precise head-counting using ML.
- **Mobile App**: Create an app to alert railway authorities remotely.

---
**Author:** sabithansari
**University Project Submission**
