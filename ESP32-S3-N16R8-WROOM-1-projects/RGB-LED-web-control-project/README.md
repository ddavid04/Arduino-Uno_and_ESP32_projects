# ESP32 RGB Web Controller

A simple web-based RGB LED controller for the ESP32-S3-N16R8-WROOM-1 board using Wi-Fi and the onboard RGB LED (WS2812/Neopixel).

---

## 💡 Features

- ESP32 acts as a standalone Wi-Fi Access Point (no router needed)
- Users connect via phone or laptop to a local web interface
- Control the onboard RGB LED with colorful buttons (Red, Green, Blue, Off)
- Mobile-friendly responsive interface with clean button styles

---

## 🧰 Hardware Requirements

- Board: `ESP32-S3-N16R8-WROOM-1`
- Built-in WS2812 RGB LED (typically on GPIO 48)
- USB cable for flashing
- Optional: power bank or USB wall adapter for standalone use

---

## 🚀 Setup Guide

### 🔧 1. Install Arduino IDE
Download from: https://www.arduino.cc/en/software

### 📦 2. Install ESP32 Board Support
1. Open `Arduino IDE`
2. Go to `File > Preferences`
3. <a href="https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json"> Click here for **"Additional Boards Manager URLs"** </a>
4. Go to `Tools > Board > Board Manager`
5. Search for **"esp32"**, then install `esp32 by Espressif Systems`

### 🔌 3. Install the Required Library
Go to `Tools > Manage Libraries`, search for **Adafruit NeoPixel**, and install it.

### 💻 4. Flash the Sketch
1. Open the `.ino` file from the `esp32/` folder in this repository
2. Select board: `ESP32S3 Dev Module`
3. Set port (e.g., `/dev/ttyACM0` or `COMx`)
4. Upload the sketch

---

## 📱 Using the Web Interface

1. After flashing, the ESP32 will start as a Wi-Fi hotspot:
```
SSID: ESP32-RGB
Password: strongpass
```
2. Connect to that Wi-Fi from your phone or computer
3. Open a browser and go to: ```http://192.168.4.1```
4. Tap the buttons to change the RGB LED color

---

## 🔋 Powering Without USB from Laptop

- You can safely unplug the ESP32 from your PC and power it using:
- A 5V USB phone charger
- A power bank
- The sketch runs automatically on boot — no need to press BOOT

