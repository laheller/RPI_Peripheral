#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include "lcd1602i2c.h"

// Define some device parameters
//#define I2C_ADDR   0x27 // I2C device address

// Define some device constants
#define LCD_CHR  1 // Mode - Sending data
#define LCD_CMD  0 // Mode - Sending command

#define LINE1  0x80 // 1st line
#define LINE2  0xC0 // 2nd line

#define LCD_BACKLIGHT   0x08  // On
// LCD_BACKLIGHT = 0x00  # Off

#define ENABLE  0b00000100 // Enable bit

/* Add function definitions here */

void lcd_byte(int bits, int mode, int fd)   {

  //Send byte to data pins
  // bits = the data
  // mode = 1 for data, 0 for command
  int bits_high;
  int bits_low;
  // uses the two half byte writes to LCD
  bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
  bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;

  // High bits
  wiringPiI2CReadReg8(fd, bits_high);
  lcd_toggle_enable(bits_high, fd);

  // Low bits
  wiringPiI2CReadReg8(fd, bits_low);
  lcd_toggle_enable(bits_low, fd);
}

void lcd_toggle_enable(int bits, int fd)   {
  // Toggle enable pin on LCD display
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits | ENABLE));
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
  delayMicroseconds(500);
}


int lcd_init(int addr)   {
  if (wiringPiSetup() == -1) exit(1);
  int fd = wiringPiI2CSetup(addr);

  // Initialise display
  lcd_byte(0x33, LCD_CMD, fd); // Initialise
  lcd_byte(0x32, LCD_CMD, fd); // Initialise
  lcd_byte(0x06, LCD_CMD, fd); // Cursor move direction
  lcd_byte(0x0C, LCD_CMD, fd); // 0x0F On, Blink Off
  lcd_byte(0x28, LCD_CMD, fd); // Data length, number of lines, font size
  lcd_byte(0x01, LCD_CMD, fd); // Clear display
  delayMicroseconds(500);

  return fd;
}
