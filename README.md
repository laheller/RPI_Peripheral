# RPI_Peripheral
C# Mono Raspberry Pi LCD 1602 I2C library

This library is actually a C# wrapper around C functions inspired by Lewis Loflin's work published here:
http://www.bristolwatch.com/rpi/i2clcd.htm

Use this library in your C# Mono project to access 1602 LCD display via Raspberry Pi I2C bus.

To install required packages:
sudo apt-get install wiringpi mono-complete monodevelop

Optional package:
sudo apt-get install i2c-tools

Steps:
1. Open and build solution in MonoDevelop
2. Run Test.App console application and check your LCD display

Notes:
- After (re)build the "liblcd1602i2c.so" shared library is automatically created and registered in the system (/usr/lib)
- Address of LCD display on I2C bus can be asked via command: i2cdetect -y 1
- Default address of display in sample Test.App application is 0x27
