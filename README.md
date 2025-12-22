
# 🛰️ StratoView - CubeSAT

A near-space exploration project using an ESP32-based CubeSAT designed to reach 30–40 km altitude, capture environmental data, take photos, and transmit telemetry to a ground station in real time.
## 🖥️ Tech Stack
**Imaging (ESP32):**
Platform: Visual Studio Code + PlatformIO

Framework: Espressif IDF

Language: C

**Flight computer (STM32):**
In progress ...

**Ground Station:**
Language: Python


## 💡 Hardware Components

 ESP32 (for deep sleep)

 STM32

 BMP180 – Altitude / Temperature / Pressure

 MPU6050 – Gyroscope + Accelerometer (IMU)

 LoRa Radio Module (with ground-station receiver)

 Camera Module

 GPS NEO-6M (coordinates + speed)

 LiPo Battery (high-altitude safe)

 SD Card Module (local data + image storage)

 3D-Printed Enclosure (CubeSAT frame)

 Parachute System (recovery after descent)
 
## Authors

- [@rozybakievv](https://www.github.com/rozybakievv)

