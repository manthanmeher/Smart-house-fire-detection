Project Overview

Project Title

Arduino Uno Based Smart House Fire Detection and Alert System

Introduction

This project is an Arduino Uno-based prototype designed to detect a flame and provide visual and audible alerts. It also demonstrates a water-pump response using a servo-operated rocker switch.

Objectives

Detect flames using a flame sensor.

Display temperature, humidity, and detection status on a 16×2 I2C LCD.

Activate an LED and buzzer when a flame is detected.

Operate a low-voltage water pump using a servo-operated rocker switch.

Hardware Components

Arduino Uno R3

Flame sensor

DHT11 temperature and humidity sensor

16×2 I2C LCD

LED and current-limiting resistor

Buzzer module

Servo motor

Rocker switch

DC water pump and separate battery supply

Breadboard and jumper wires

Software

The system is programmed in Arduino C++ using the Arduino IDE and the required sensor, LCD, and servo libraries.

Working Principle

The flame sensor sends a digital signal to the Arduino. When a flame-detection signal is received, the Arduino activates the LED and buzzer and moves the servo to operate the rocker switch, turning on the separate battery-powered pump.

When the flame-detection signal clears, the alarm is turned off and the servo returns the rocker switch to the OFF position. The DHT11 provides temperature and humidity readings for the LCD; these readings do not independently trigger the alarm.

Project Status

The Arduino source code, circuit diagram, architecture diagram, flowchart, and project photograph have been uploaded. The final project report is still in progress.

Limitations

This is an educational prototype, not a certified fire-protection system. Its performance depends on sensor placement, power availability, and the pump's limited water supply. The current version does not provide remote mobile notifications.
