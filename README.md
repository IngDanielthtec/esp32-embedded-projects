# ESP32 Embedded Projects

Personal learning projects in Arduino C++ for the ESP32 (Heltec board):
sensor reading, display output and DC motor control.
Not affiliated with any company or client.

## Projects

| Folder | Description | Hardware |
|---|---|---|
| LecturaSensorHumedadSuelo | Reads soil moisture via ADC and scales it to 0-100 % | Analog soil moisture sensor |
| LecturaSensorTemperatura | Converts sensor voltage to °C (T = (Vout - 0.5 V) / 0.01 V) | MCP9700A |
| proyecto_max6675 | Reads a thermocouple over SPI, prints °C and °F | MAX6675 + K-type thermocouple |
| dht22_y_lcd2x16 | Shows temperature and humidity on a 16x2 I2C LCD | DHT22 + LCD 2x16 (I2C) |
| DriverL298N | Controls two DC motors with PWM speed steps | L298N driver |
| ControlMotores_ConUART | Controls motor direction and speed with serial commands (A, T, S, P) | L298N driver |

## Libraries
- MAX6675 library
- DHT sensor library
- LiquidCrystal_I2C

## Usage
Open any .ino file in Arduino IDE, select the ESP32 board,
upload, and open the Serial Monitor (see baud rate in each sketch).

## About
Personal project developed for learning and prototyping
IoT sensor nodes. Not affiliated with any company or client.
