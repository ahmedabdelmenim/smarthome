

#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_config.h"
#define CLR_SCREEN           0X01
#define DISPLAY_ON_CURSOR_ON 0X0E
#define EIGHT_BIT_MODE       0X38
#define FOUR_BIT_MODE_I      0X02
#define FOUR_BIT_MODE_II     0X28


void LCD_Init(void);
void LCD_Send_cmd(uint8 cmd);
void LCD_Send_char(uint8 data);
void LCD_Send_string(char *data);
void LCD_clearscreen(void);
void LCD_movecursor(uint8 row,uint8 column);
void LCD_WriteInteger(uint16 num);
#endif /* LCD_H_ */