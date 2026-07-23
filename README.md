# RFID Automated Boom Gate System 🚗💳

An automated Boom system using an RFID module and a microcontroller. This project simulates a real-world boom system where registered RFID tags open a boom gate, while unauthorized are denied entry.

## 📋 Table of Contents
- [Overview](#overview)
- [Components Used](#components-used)
- [System Architecture & Steps](#system-architecture--steps)
- [Circuit Diagram](#circuit-diagram)
- [Software Setup](#software-setup)
- [System Operation](#system-operation)
- [Demonstration Video](#demonstration-video)

---

## 🔍 Overview
This project was designed to demonstrate seamless vehicle access control. When a vehicle approaches, the driver scans their RFID card/tag. The system reads the Unique ID (UID), and either grants access (rotating a servo motor to open the gate) or denies it, displaying real-time feedback on an LCD.

## 🛠️ Components Used
*   **Microcontroller:** Arduino Uno
*   **RFID Reader:** MFRC522 Module
*   **Gate Actuator:** SG90 Micro Servo Motor
*   **Display:** 16x2 LCD with I2C module
*   **Miscellaneous:** Breadboard, Jumper Wires, Power Supply

---

## ⚙️ System Architecture & Steps

The project was built and tested in distinct, modular phases to ensure reliability and create a reference for future implementations of the project into other systems

### Part 1: RFID Module Integration
1. Wired the MFRC522 module to the microcontroller via SPI communication.
2. Utilized standard RFID libraries to read the UID of standard tags.
3. Implemented logic to recognize valid and invalid tags based on their UIDs.

### Part 2: Display & User Feedback
1. Connected the 16x2 I2C LCD to the SDA and SCL pins.
2. Programmed dynamic display states

### Part 3: Servo Motor Actuation (The Gate)
1. Attached the Servo motor to a PWM-enabled pin.
2. Created a function to map the servo to 90 degrees (open gate) when an authorized tag is read.
3. Added a delay before automatically returning the servo to 0 degrees (closed gate) to allow the vehicle to pass.

### Part 4: Main Logic
1. Integrated all modules into a single control loop.
2. Created a simulated "database" in the code (variables/arrays) holding the Authorised UID number.
3. Programmed the boom logic: If a card is scanned, UID number is obtained, and checked if it matches numbers within 'database', if so boom is opened, if not, boom is left closed.

---

## 🔌 Circuit Diagram

![RFID BOOM System Circuit Diagram](RFID_TOLL/Design/circuit_image.png)

*Figure 1: Schematic showing the connections between the Microcontroller, MFRC522, Servo, LCD*

---

## 💻 Software Setup

1. Clone this repository:
   ```bash
   git clone [https://github.com/Hatidani/RFID_Toll.git](https://github.com/Hatidani/RFID_Boom.git)
## Demonstration Video
<iframe src="https://www.linkedin.com/embed/feed/update/urn:li:ugcPost:7473825145732788225?compact=1" height="399" width="504" frameborder="0" allowfullscreen="" title="Embedded post"></iframe>
