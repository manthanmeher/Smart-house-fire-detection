# Testing Documentation

## Purpose
This document records the component tests performed for the Arduino Uno Smart House Fire Detection and Alert System.

## Component Testing

### 1. Flame Sensor
The flame sensor was tested using its digital output. During testing, the output changed from HIGH under normal conditions to LOW when a flame was detected nearby.

### 2. DHT11 Sensor
The DHT11 was tested to check whether it provided temperature and humidity readings.

### 3. LCD Display
The 16×2 I2C LCD was tested to display temperature, humidity, and system status.

### 4. LED Indicator
The LED was tested to confirm that it could illuminate through a current-limiting resistor.

### 5. Buzzer
The buzzer was tested using an Arduino tone signal to confirm that it produced an audible sound.

### 6. Servo Motor and Rocker Switch
The servo was tested to confirm that it could physically operate the rocker switch between its ON and OFF positions.

### 7. Water Pump
The low-voltage DC water pump was tested using its separate battery supply to confirm that it could pump water.

## Integrated System Testing
The components were assembled into the prototype. The final integrated behavior should be checked to confirm that flame detection activates the LED, buzzer, and servo-operated pump switch, and that clearing the detection signal turns them off.

## Testing Notes
Record any additional integrated tests, observations, and issues here. Do not report an integrated test as successful unless it has actually been performed.

## Safety
The pump uses a separate low-voltage power supply. Keep water away from the Arduino and other electronic components. This prototype is for educational demonstration and is not a certified fire-protection system.
