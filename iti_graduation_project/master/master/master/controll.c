#include "controll.h"
#include "smart_home.h"
#include "LCD.h"


uint8 pressed =NOT_PRESSED;
void air_condation(void){
	condation:
	pressed =NOT_PRESSED;
	delay_ms(50);
	LCD_clearscreen();
	LCD_Send_string("air condation");
	LCD_movecursor(2,1);
	LCD_Send_string("1:on");
	LCD_movecursor(2,6);
	LCD_Send_string("2:off");
	LCD_movecursor(2,12);
	LCD_Send_string("3:ret");
	while(pressed==NOT_PRESSED){
		pressed=keypad_press();
	}
	delay_ms(100);
	if (pressed=='1' || pressed=='2'|| pressed=='3'){
	if(pressed=='1'){
			SPI_ui8TransmitRecive(AIR_COND_TURN_ON);
			EEPROM_WriteByte(0x0114,1);
		    return 0;
	}
	else if(pressed=='2'){
		SPI_ui8TransmitRecive(AIR_COND_TURN_OFF);
		EEPROM_WriteByte(0x0114,0xff);

		
		  return 0;
		
	}
	else if(pressed=='3'){
		delay_ms(100);
		  return 0;
		}
	else{
		
	}
	}
	else{
		LCD_clearscreen();
		delay_ms(50);
		LCD_Send_string("incorect input");
		delay_ms(1000);
		goto condation;
	}
	

}
void room1(void){
	
	room1:
	LCD_clearscreen();
	LCD_Send_string("controll rom1");
	LCD_movecursor(2,1);
	LCD_Send_string("1:on");
	LCD_movecursor(2,6);
	LCD_Send_string("2:off");
	LCD_movecursor(2,11);
	LCD_Send_string("3:RET");
	pressed=NOT_PRESSED;
	while(pressed==NOT_PRESSED){
		pressed=keypad_press();
	}
	if(pressed=='1'||pressed=='2'||pressed=='3'){
		if(pressed=='1'){
			SPI_ui8TransmitRecive(ROOM1_TURN_ON);
			EEPROM_WriteByte(0x0111,1);
			return 0;
		}
		else if(pressed=='2'){
			SPI_ui8TransmitRecive(ROOM1_TURN_OFF);
		EEPROM_WriteByte(0x0111,0xff);

			return 0;
		}
		else if(pressed=='3'){
			return 0;
		}
		else{
			
		}
	}
	else{
		LCD_clearscreen();
		delay_ms(50);
		LCD_Send_string("incorrct input");
		delay_ms(1000);
		LCD_clearscreen();
		goto room1;
	}
}

void room2(void){

	room2:
	LCD_clearscreen();
	LCD_Send_string("controll rom2");
	LCD_movecursor(2,1);
	LCD_Send_string("1:on");
	LCD_movecursor(2,6);
	LCD_Send_string("2:off");
	LCD_movecursor(2,11);
	LCD_Send_string("3:RET");
	pressed=NOT_PRESSED;
	while(pressed==NOT_PRESSED){
		pressed=keypad_press();
	}
	if(pressed=='1'||pressed=='2'||pressed=='3'){
		if(pressed=='1'){
			SPI_ui8TransmitRecive(ROOM2_TURN_ON);
			EEPROM_WriteByte(0x0112,1);
			return 0;
		}
		else if(pressed=='2'){
			SPI_ui8TransmitRecive(ROOM2_TURN_OFF);
			EEPROM_WriteByte(0x0112,0xff);
			return 0;
		}
		else if(pressed=='3'){
			return 0;
		}
		else{
			
		}
	}
	else{
		LCD_clearscreen();
		delay_ms(50);
		LCD_Send_string("incorrct input");
		delay_ms(1000);
		LCD_clearscreen();
		goto room2;
		}

}
void room3(void){

			room3:
		LCD_clearscreen();
		LCD_Send_string("controll rom3");
		LCD_movecursor(2,1);
		LCD_Send_string("1:on");
		LCD_movecursor(2,6);
		LCD_Send_string("2:off");
		LCD_movecursor(2,11);
		LCD_Send_string("3:RET");
		pressed=NOT_PRESSED;
		while(pressed==NOT_PRESSED){
			pressed=keypad_press();
		}
		if(pressed=='1'||pressed=='2'||pressed=='3'){
			if(pressed=='1'){
				SPI_ui8TransmitRecive(ROOM3_TURN_ON);
				EEPROM_WriteByte(0x0113,1);
			return 0;
			}
			else if(pressed=='2'){
				SPI_ui8TransmitRecive(ROOM3_TURN_OFF);
				EEPROM_WriteByte(0x0113,0xff);
			return 0;
			}
			else if(pressed=='3'){
			return 0;
			}
			
			else{
				
			}
		}
		
		else{
			LCD_clearscreen();
			delay_ms(50);
			LCD_Send_string("incorrct input");
			delay_ms(1000);
			LCD_clearscreen();
			goto room3;
		}
		
		
}


  

