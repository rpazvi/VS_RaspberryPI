/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/

#include "ssd1306_i2c.h"

void demo_ssd1306() {

	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);

	ssd1306_display(); //Adafruit logo is visible
	ssd1306_clearDisplay();
	delay(5000);

	char* text = "This is demo for SSD1306 i2c driver for Raspberry Pi";
	ssd1306_drawString(text);
	
	ssd1306_display();
	delay(5000);

	ssd1306_dim(1);
	ssd1306_startscrollright(00,0xFF);
	delay(5000);

	ssd1306_clearDisplay();
	ssd1306_fillRect(10,0, 50, 16, WHITE);
	ssd1306_fillRect(80, 0, 130, 64, WHITE);
	ssd1306_display();
}
