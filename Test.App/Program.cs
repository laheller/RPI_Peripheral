using System;
using System.Threading;
using lcd1602i2c_wrapper;

namespace Test.App
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			var msg = "Hello World!";
			Console.WriteLine (msg);
			var fd = LCD1602I2C.lcd_init (0x27);

			LCD1602I2C.LcdLoc (LCD1602I2C.LINE1, fd);
			LCD1602I2C.TypeLn (msg, fd);

			LCD1602I2C.LcdLoc (LCD1602I2C.LINE2, fd);
			LCD1602I2C.TypeLn ("Waiting 3 secs", fd);
			Thread.Sleep (3000);

			LCD1602I2C.ClrLcd (fd);
			LCD1602I2C.LcdLoc (LCD1602I2C.LINE1, fd);
			LCD1602I2C.TypeChar ('#', fd);

			LCD1602I2C.LcdLoc (LCD1602I2C.LINE2, fd);
			LCD1602I2C.TypeLn ("This is sparta", fd);
		}
	}
}
