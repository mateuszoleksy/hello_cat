# Hello Cat – Automated Pet Feeder (2018)

**Hello Cat** is an IoT pet-feeding system built on the ATmega328P (Arduino) platform. Designed for automated cat and dog feeding, the device receives schedule triggers and manual commands over Bluetooth via a dedicated Android application to operate a dispensing servo motor.

### Key Features
* **Custom Android Management App:** Set feeding schedules, adjust dispensing times, and manually trigger feed cycles from a smartphone interface.
* **Bluetooth Connectivity:** Wireless communication using the HC-05 Bluetooth module operating over UART (SoftwareSerial).
* **High-Torque Servo Mechanism:** Uses an MG995 servo motor powered by an external supply to control the feeding dispenser hatch.
* **Limit Switch & Signal Feedback:** Integrated limit switch on pin 2 paired with a status LED for feedback during operation.
* **Hardware Protection & Logic:** Custom resistor voltage divider ($22\,\text{k}\Omega$ / $10\,\text{k}\Omega$) on the RX line to match logic signal levels for the HC-05.

---

### App Interface

<div align="center">
  <img src="https://github.com/user-attachments/assets/5a59b48f-08d8-4230-892e-76080338b5c7" width="300" alt="Hello Cat Android App Interface"/>
</div>

---

### Hardware & Circuit Architecture

| Component | Description / Wiring |
| :--- | :--- |
| **Microcontroller** | ATmega328P / Arduino Uno |
| **Servo Motor** | MG995 high-torque servo connected to **Pin 8** (Powered by external 5V Supply) |
| **Bluetooth Module** | HC-05 (TXD $\rightarrow$ **Pin 10**, RXD $\leftarrow$ Voltage Divider on **Pin 11**) |
| **Limit Switch** | Connected to **Pin 2** (Triggering indicator LED logic) |
| **Voltage Divider** | $22\,\text{k}\Omega$ + $10\,\text{k}\Omega$ resistors on signal line for 3.3V logic translation |
| **Power Supply** | Dedicated external 5V power supply for the high-draw servo motor |
