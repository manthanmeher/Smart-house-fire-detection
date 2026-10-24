# Smart House Fire Detection and Alert System

## Project Overview
The Smart House Fire Detection and Alert System is an Arduino Uno-based prototype designed to detect flames and provide an audible and visual alert. It also demonstrates automatic water-pump activation using a servo-operated rocker switch.

## Objectives
- Detect a flame using a flame sensor.
- Display temperature, humidity, and detection status on a 16×2 I2C LCD.
- Activate an LED and buzzer when a flame is detected.
- Operate a low-voltage water pump through a servo-operated rocker switch.

## Hardware Components
- Arduino Uno R3
- Flame sensor
- DHT11 temperature and humidity sensor
- 16×2 I2C LCD
- LED and current-limiting resistor
- Buzzer module
- Servo motor
- Rocker switch
- Low-voltage DC water pump
- Separate pump battery supply
- Breadboard and jumper wires

## Software and Libraries
- Arduino C++
- Arduino IDE
- Servo library
- DHT sensor library
- LiquidCrystal_I2C library

## Working Principle
The flame sensor sends a digital signal to the Arduino Uno. When a flame-detection signal is received, the Arduino activates the LED and buzzer and commands the servo to operate the rocker switch, turning on the separate battery-powered water pump.

The DHT11 measures temperature and humidity. The LCD displays these readings and the current detection status. When the flame-detection signal clears, the alarm is turned off and the servo returns the switch to the OFF position.

## Repository Structure
- `assets/` — Circuit diagram and project photographs
- `docs/` — Project report and supporting documentation
- `src/SmartHouseFireDetection/` — Arduino source code
- `README.md` — Project overview and instructions

## Project Status
The Arduino source code, circuit diagram, and project photographs have been uploaded. The project report is currently in progress.

## Limitations
- The prototype is intended for educational demonstration and is not a certified fire-protection system.
- Detection performance depends on sensor placement and environmental conditions.
- The pump has a limited water supply.
- The current prototype does not provide Wi-Fi or mobile notifications.

## Future Scope
- Add remote alerts using a suitable Wi-Fi module.
- Improve detection using multiple sensors.
- Add a monitoring dashboard.
- Improve the water-delivery mechanism.

## Safety Note
The pump uses a separate low-voltage power supply. This prototype should not be treated as a replacement for certified smoke alarms or fire-suppression equipment.
