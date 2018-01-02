using System;
using System.Runtime.InteropServices;

namespace lcd1602i2c_wrapper
{
	public class LCD1602I2C
	{
		private static readonly int LCD_CMD = 0;
		private static readonly int LCD_CHR = 1;

		public static readonly int LINE1 = 0x80;
		public static readonly int LINE2 = 0xC0;

		[DllImport ("liblcd1602i2c.so", EntryPoint = "lcd_init")]
		public static extern int lcd_init (int addr);

		[DllImport ("liblcd1602i2c.so", EntryPoint = "lcd_byte")]
		public static extern void lcd_byte (int bits, int mode, int fd);

		[DllImport ("liblcd1602i2c.so", EntryPoint = "lcd_toggle_enable")]
		public static extern void lcd_toggle_enable (int bits, int fd);

		// clr lcd go home loc 0x80
		public static void ClrLcd (int fd)
		{
			lcd_byte (0x01, LCD_CMD, fd);
			lcd_byte (0x02, LCD_CMD, fd);
		}

		// go to location on LCD
		public static void LcdLoc (int line, int fd)
		{
			lcd_byte (line, LCD_CMD, fd);
		}

		// out char to LCD at current position
		public static void TypeChar (char val, int fd)
		{
			lcd_byte (val, LCD_CHR, fd);
		}

		// this allows use of any size string
		public static void TypeLn (string s, int fd)
		{
			var tmp = s.ToCharArray ();
			for (var i = 0; i < tmp.Length; i++)
				lcd_byte ((byte)tmp [i], LCD_CHR, fd);
		}
	}
}

