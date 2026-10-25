# Smart House Fire Detection and Alert System

An Arduino Uno-based educational prototype that detects flame signals, activates visual and audible alerts, displays temperature and humidity, and demonstrates water-pump activation through a servo-operated rocker switch.

## Project Overview

The system uses a flame sensor to detect a flame signal. When detection is active, the Arduino turns on an LED and buzzer and commands a servo motor to operate a rocker switch for a separate battery-powered DC water pump.

The DHT11 measures temperature and humidity, which are displayed on a 16×2 I2C LCD. These readings do not independently trigger the alarm.

## Features

- Flame detection using a digital flame sensor
- Temperature and humidity display using DHT11
- 16×2 I2C LCD status display
- LED visual alert and buzzer audible alert
- Servo-operated rocker switch for a separate low-voltage water pump
- Arduino Uno-based control

## Hardware Components

- Arduino Uno R3
- Flame sensor
- DHT11 temperature and humidity sensor
- 16×2 I2C LCD
- LED and current-limiting resistor
- Buzzer module
- Servo motor
- Rocker switch
- Low-voltage DC water pump and separate battery supply
- Breadboard and jumper wires

## Software

- Arduino C++
- Arduino IDE
- Servo library
- DHT sensor library
- LiquidCrystal_I2C library

## System Diagrams and Photos

| Resource | Description |
|---|---|
| [Circuit Diagram](assets/SmartHouse_Circuit_Diagram.png) | Circuit layout |
| [Architecture Diagram](assets/architecture-diagram.png) | Main system components |
| [Program Flowchart](assets/flowchart.png) | Program decision flow |
| [Project Photograph](assets/smart-house-model.jpeg) | Physical model |

## Documentation

- [Project Overview](docs/PROJECT-OVERVIEW.md)
- [Testing Documentation](docs/TESTING.md)
- [Wiring Documentation](docs/WIRING.md)
- [Final Project Report (PDF)](docs/Smart_House_Fire_Detection_Report.pdf)
- [Source Code Folder](src/SmartHouseFireDetection/)

## Working Principle

1. The Arduino initializes the sensors, LCD, LED, buzzer, and servo.
2. The flame sensor is checked continuously.
3. When a flame signal is detected, the LED and buzzer turn on, and the servo operates the rocker switch to turn on the pump.
4. When the flame detection signal clears, the LED and buzzer turn off, and the servo returns the switch to the OFF position.
5. The DHT11 readings and system status are displayed on the LCD.
6. The process repeats continuously.

## Limitations

- This is an educational prototype, not a certified fire-detection or fire-suppression system.
- Detection performance depends on sensor placement and environmental conditions.
- The pump has a limited water supply.
- The current version does not provide Wi-Fi or mobile notifications.

## Future Scope

- Add remote notifications using a suitable Wi-Fi module.
- Incorporate additional sensors.
- Develop a monitoring dashboard.
- Improve the water-delivery mechanism.

## Safety Note

The pump uses a separate low-voltage power supply. Keep water away from the Arduino and other electronics. Do not connect the pump circuit to household mains electricity. This prototype is not a replacement for certified smoke alarms or fire-suppression equipment.

## Project Status

The source code, diagrams, project photograph, documentation, and final project report are included in the repository.
