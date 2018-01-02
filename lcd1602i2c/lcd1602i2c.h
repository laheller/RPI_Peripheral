#ifndef __LCD1602I2C_H__
#define __LCD1602I2C_H__

/* Add function prototypes here */
extern int lcd_init(int addr);
extern void lcd_byte(int bits, int mode, int fd);
extern void lcd_toggle_enable(int bits, int fd);

#endif
