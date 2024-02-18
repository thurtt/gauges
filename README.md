# Automotive Gauges
Automotive Gauges Firmware. This firmware runs on the RP2040 microcontroller using multiple ssd1306 OLED displays. The schematic describes the layout of the gauges circuit.

## Gauge Features
All gauge readings use a signal level of 5V. A level shifter is used to interface with the RP2040. The following are the supported gauge measurements:
* Voltage - Calibrated by a voltage divider network
* Oil Pressure - Using a sender that translates 0-100 PSI to 0-4.5V
* Coolant Temperature - Using an autometer sender that uses an NTC thermistor
* Fuel Level - Uses a Ford style fuel sender, calibrated via a voltage divider network
* Tachometer - The tach circuit contains a signal filter to filter any coil ringback, and an opto-isolated Shmitt trigger to protect the circuit from any unexpected voltage spikes.

## Display Readout
The display readout consists of 4 SSD1306 OLED displays wired to run in I2C mode. An I2C mux is used so all displays can be addressed.

## Project Dependencies
The following dependencies are required to build this project:
* Cmake
* ARM compiler backend support
* Raspberry Pi Pico SDK[https://github.com/raspberrypi/pico-sdk]
* Pico SSD1306 support[https://github.com/Harbys/pico-ssd1306]

## Building the Project
Set the SDK and library paths:
```
$ export PICO_SDK_PATH=/path/to/pico-sdk
$ export SSD1306_LIB_PATH=/path/to/ssd1306_lib
```

Switch to the build directory and run the build:
```
$ cd build
$ cmake ..
$ make
