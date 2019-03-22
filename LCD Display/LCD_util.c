#include "stm32l4xx_hal.h"
#include "LCD_util.h"

#define LCD_WRITE_ADDRESS 0x4E
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_CURSOR_LEFT 0x04
#define LCD_CURSOR_RIGHT 0x06
#define LCD_SHIFT_DISPLAY_RIGHT 0x05
#define LCD_SIFT_DISPLAY_LEFT 0x07
#define LCD_DISPLAY_OFF_CURSOR_OFF 0x08
#define LCD_DISPLAY_OFF_CURSOR_ON 0x0A
#define LCD_DISPLAY_ON_CURSOR_OFF 0x0C
0x0E
0x0F
0x10
0x14
0x18
0x1C




unsigned char buffer[4];

void LCD_init(I2C_HandleTypeDef i2cHandle) {
	lcd_send_cmd(0x02); //DB1 - Cursor Home
	lcd_send_cmd(0x28); //DB5, DB3 
	lcd_send_cmd(0x0C); //DB3, DB2
	lcd_send_cmd(0x80); //DB3
}

void LCD_send_string(char* str) {
	while(*str) LCD_send_data(*str++);
}w

void LCD_send_cmd(I2C_HandleTypeDef i2cHandle, char cmd) {
	char data_u, data_l;    
	data_u = cmd & 0xf0;
	data_l = (cmd<<4) & 0xf0;
	buffer[0] = data_u | 0x04;
	buffer[1] = data_u;
	buffer[2] = data_l | 0x04;
	buffer[3] = data_l;
	HAL_I2C_Master_Transmit (&i2cHandle, LCD_WRITE_ADDRESS, buffer, 4, 100);
   
}

void LCD_send_data(I2C_HandleTypeDef i2cHandle, char data) {
	char data_u, dat_l;
	data_u = data & 0xf0;
	data_l = (data<<4) & 0xf0;
	buffer[0] = data_u | 0x05;
	buffer[1] = data_u | 0x01;
	buffer[2] = data_l | 0x05;
	buffer[3] = data_l | 0x01;
	HAL_I2C_Master_Transmit(&i2cHandle, LCD_WRITE_ADDRESS, buffer, 4, 100);
}
