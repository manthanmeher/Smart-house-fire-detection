# Wiring Documentation

## Arduino Uno Pin Connections

| Component | Arduino Connection |
|---|---|
| Flame sensor digital output | D2 |
| DHT11 data pin | D4 |
| Buzzer signal | D8 |
| LED through a current-limiting resistor | D9 |
| Servo signal | D10 |
| I2C LCD SDA | A4 |
| I2C LCD SCL | A5 |

## Breadboard Power Connections
- Arduino 5V connects to the breadboard positive (+) rail.
- Arduino GND connects to the breadboard negative (−) rail.
- Components powered from the Arduino's 5V supply use the appropriate breadboard power and ground rails, according to their requirements.

## LCD Connections
The 16×2 I2C LCD uses SDA and SCL for communication with the Arduino Uno. Its I2C address in the program is `0x27`.

## Servo and Water Pump
The servo mechanically operates a rocker switch. The switch controls the separate low-voltage battery circuit supplying the DC water pump. The pump is not powered directly by an Arduino output pin.

## Important Notes
- Verify every connection against the final circuit diagram and the actual hardware.
- Check component pin labels before connecting power.
- Keep the pump and water away from the Arduino, breadboard, and other electronics.
- Do not connect the low-voltage pump circuit to household mains electricity.

