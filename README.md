# Laser based Security System with wireless notification circuit using NRF-24 Radio module

This Repo shows how you can create a laser based security system for your requirements.

### ! you can increase the number of laser beams with the help of plane mirrors by diverging the laser in a zig-zag way if you need to cover more area.

## Usage
- There are three circuits in this system 
  - Laser transmitter consists only a laser diode and power supply
  - TX Circuit
    - Laser Receiver (LDR) and Radio Transmitter
  - RX Circuit
    - Radio Receiver
- when an object interfere with the laser beam Buzzer at the RX circuit starts beeping.
- To turn off the beeping press the notified button. this resets the state and again starts looking for object interferences.


> **_!you can refer block diagrams for understanding the working principle._**

## Components
- **Laser Transmitter**

| Components |
| ----------- |
| A Good Quality Laser Diode |
| Power Supply|

- **TX Circuit**

| Components |
| ----------- |
| Arduino UNO/Nano/Pro mini |
| NRF-24 module |
| Power Supply|
| Light Dependent Resistor (LDR) |
| Resister 10k ohm |

- **RX Circuit**

| Components |
| ----------- |
| Arduino UNO/Nano/Pro mini |
| NRF-24 module |
| Power Supply|
| Buzzer |
| Push Button |
| Dropdown Resistor 680K to 1M ohms|
| current limiting Resistor 220 to 480 ohms|
| LED |

