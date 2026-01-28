# 🏠 EduSmart Home ESP32

**An Educational IoT Project for Robotics Students**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-ESP32-blue)](https://www.espressif.com/)
[![Powered By](https://img.shields.io/badge/Powered%20By-Sinric%20Pro-orange)](https://sinric.pro/)

## 📖 About The Project
**EduSmart Home** is an open-source hardware project designed to teach students the fundamentals of the Internet of Things (IoT) and Home Automation. 

As a robotics teacher and a student myself, I noticed that students often struggle with messy wiring on breadboards when learning IoT. This project provides a dedicated PCB design that integrates an **ESP32** microcontroller with the **Sinric Pro** platform, allowing students to focus on coding and logic rather than troubleshooting loose wires.

### 🎯 Key Features
* **Voice Control:** Compatible with Alexa & Google Home via Sinric Pro.
* **App Control:** Turn devices on/off remotely using a smartphone.
* **Educational Design:** Clearly labeled components for learning purposes.
* **Cost-Effective:** Uses affordable components accessible to students.

## 🛠️ Hardware Required
* **Microcontroller:** ESP32 Development Board (DOIT DEVKIT V1)
* **Relay Module:** 5V 2-Channel or 4-Channel Relay
* **Platform:** Sinric Pro (Free tier)
* **Power Supply:** 5V USB or External Power Source
* **Connectors:** Screw terminals for easy wiring

## ⚙️ How It Works
1.  The ESP32 connects to the local WiFi network.
2.  It establishes a WebSocket connection with the **Sinric Pro** server.
3.  When a user speaks a command ("Turn on the Light") or uses the app, the signal is sent to the ESP32.
4.  The ESP32 triggers the Relay, turning the connected appliance ON or OFF.

## 🚀 Getting Started

### Prerequisites
* Install [Arduino IDE](https://www.arduino.cc/en/software)
* Install **Sinric Pro** library from Library Manager.
* Install **WebSockets** library by Markus Sattler.

### Installation
1.  Clone this repository:
    ```bash
    git clone [https://github.com/YOUR_USERNAME/EduSmart-Home-ESP32.git](https://github.com/YOUR_USERNAME/EduSmart-Home-ESP32.git)
    ```
2.  Open `src/main.ino` in Arduino IDE.
3.  Update your WiFi credentials and Sinric Pro App Key:
    ```cpp
    #define WIFI_SSID       "YOUR_WIFI_NAME"
    #define WIFI_PASS       "YOUR_WIFI_PASSWORD"
    #define APP_KEY         "YOUR_SINRIC_APP_KEY"
    #define APP_SECRET      "YOUR_SINRIC_APP_SECRET"
    ```
4.  Upload the code to your ESP32.

## 📸 Schematics & PCB
*(Place your EasyEDA screenshot or Gerber file image here. Example: `![PCB Design](schematic/pcb_preview.png)`)*

You can find the Gerber files in the `schematic/` folder to manufacture this board.

## 🤝 Contributing
This project is open for students and hobbyists! Feel free to fork the repo and submit Pull Requests.

## 📜 License
Distributed under the MIT License. See `LICENSE` for more information.

---
*Made with ❤️ in Uzbekistan for future engineers.*
