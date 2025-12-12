
# 🛰️ StratoView - CubeSAT

A near-space exploration project using an ESP32-based CubeSAT designed to reach 30–40 km altitude, capture environmental data, take photos, and transmit telemetry to a ground station in real time.
## 🖥️ Tech Stack
**Platform**: Visual Studio Code + PlatformIO

**Framework**: Espressif IDF

**Language**: C

## 📡 Architecture Overview
- Periodically collect sensor data

- Package telemetry (header + payload + CRC checksum)

- Transmit packets via LoRa radio

- Capture images periodically or on event trigger

- Store backup data on SD card

- Enter deep-sleep mode to save power between cycles

## 💡 Hardware Components

 ESP32 (deep sleep for power efficiency)

 BMP180 – Altitude / Temperature / Pressure

 MPU6050 – Gyroscope + Accelerometer (IMU)

 LoRa Radio Module (with ground-station receiver)

 Low-power Camera Module

 GPS NEO-6M (coordinates + speed)

 LiPo Battery (high-altitude safe)

 SD Card Module (local data + image storage)

 3D-Printed Enclosure (CubeSAT frame)

 Parachute System (recovery after descent)
## Authors

- [@rozybakievv](https://www.github.com/rozybakievv)

