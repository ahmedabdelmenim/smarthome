#include "smart_home.h"
#include "LED.h"
#include "DIO.h"
#include "EEPROM.h"
void first_time(void){
	if(EEPROM_ReadByte(EEPROM_ADMIN_ADDRESS)==0xff){
		uint8 key_pressed = NOT_PRESSED;
		LCD_clearscreen();
		LCD_Send_string("Login for");
		LCD_movecursor(2,1);
		LCD_Send_string("first time");
		delay_ms(1000);
		LCD_clearscreen();
		LCD_Send_string("Set Admin pass");
		LCD_movecursor(2,1);
		LCD_Send_string("Admin pass:");
		uint8 pass_counter=0;
		uint8 pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};

		while (pass_counter<PASS_SIZE)
		{
			key_pressed = NOT_PRESSED;
			while (key_pressed == NOT_PRESSED)
			{
				key_pressed = keypad_press();
			}
			pass[pass_counter]=key_pressed;
			LCD_Send_char(key_pressed);
			delay_ms(100);
			LCD_movecursor(2,12+pass_counter);
			LCD_Send_char('*');
			delay_ms(100);
			pass_counter++;
		}
		
		EEPROM_WriteBlock(EEPROM_ADMIN_ADDRESS,pass,PASS_SIZE);
		LCD_clearscreen();
		LCD_Send_string("Pass Saved");
		delay_ms(1000);
		LCD_clearscreen();
		
		key_pressed = NOT_PRESSED;

		LCD_Send_string("Set Gest pass");
		LCD_movecursor(2,1);
		LCD_Send_string("Gest pass:");
		pass_counter=0;

		while (pass_counter<PASS_SIZE)
		{
			key_pressed = NOT_PRESSED;
			while (key_pressed == NOT_PRESSED)
			{
				key_pressed = keypad_press();
			}
			pass[pass_counter]=key_pressed;
			LCD_Send_char(key_pressed);
			delay_ms(100);
			LCD_movecursor(2,11+pass_counter);
			LCD_Send_char('*');
			delay_ms(100);
			pass_counter++;
		}
		
		EEPROM_WriteBlock(EEPROM_GUEST_ADDRESS,pass,PASS_SIZE);
		LCD_clearscreen();
		LCD_Send_string("Pass Saved");
		delay_ms(1000);
		LCD_clearscreen();
	}
}
	

uint8 chose_user(void){
		LCD_clearscreen();
		LCD_Send_string("please chose");
		LCD_movecursor(2,1);
		LCD_Send_string("1:admin");
		LCD_movecursor(2,9);
		LCD_Send_string("2:Gust");
		uint8 key_pressed ;
		
		key_pressed = NOT_PRESSED;
		while (key_pressed == NOT_PRESSED)
		{
			key_pressed = keypad_press();
		}
		if (key_pressed=='1' || key_pressed=='2'){
			LCD_clearscreen();
			
			return key_pressed;
			
		}
		
		else{
			LCD_clearscreen();
			delay_ms(50);
			LCD_Send_string("incorrect input");
			LCD_movecursor(2,1);
			LCD_Send_string("try again");
			delay_ms(1000);
			
		
	}
}
void check_pass_admin(void){
	delay_ms(100);
	int number=0;
		uint8 key_pressed = NOT_PRESSED;
		uint8 counter;
		admin_check	:
		LCD_Send_string("enter _pass");
		LCD_movecursor(2,4);
		LCD_Send_string("admin:");
		uint16 pass_counter=0;
		uint8 pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};

		while (pass_counter<PASS_SIZE)
		{
			while (key_pressed == NOT_PRESSED)
			{
				key_pressed = keypad_press();
			}
			pass[pass_counter]=key_pressed;
			LCD_Send_char(key_pressed);
			delay_ms(100);
			LCD_movecursor(2,10+pass_counter);
			LCD_Send_char('*');
			delay_ms(100);
			pass_counter++;
			key_pressed = NOT_PRESSED;
		}
		uint8 stored_pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};
		
		EEPROM_ReadBlock(EEPROM_ADMIN_ADDRESS,stored_pass,PASS_SIZE);
		EEPROM_ReadBlock(EEPROM_ADMIN_ADDRESS,stored_pass,PASS_SIZE);

		uint8 a=0;
		
		if ((ui8ComparePass(pass,stored_pass,PASS_SIZE)) == TRUE){
			LCD_clearscreen();
			LCD_Send_string("Right pass");
			LCD_movecursor(2,1);
			LCD_Send_string("GUEST mode");
			delay_ms(1000);
			LCD_clearscreen();
		}
		else
		{	counter++;
			if (counter==3)
			{
				LCD_clearscreen();
				LCD_Send_string("block");
				delay_ms(50);
				LED_vInit(BLOCK_LED_PORT,BLOCK_LED_PIN);
				LED_vTurnOn(BLOCK_LED_PORT,BLOCK_LED_PIN);
				delay_ms(15000);
				LED_vInit(BLOCK_LED_PORT,BLOCK_LED_PIN);
				LED_vTurnOff(BLOCK_LED_PORT,BLOCK_LED_PIN);
				LCD_clearscreen();
				counter=2;
				goto admin_check;
			}
			LCD_clearscreen();
			LCD_Send_string("wrong pass");
			LCD_movecursor(2,1);
			LCD_Send_string("try again");
			delay_ms(1000);
			LCD_clearscreen();
			goto admin_check;

		}
	
}
void check_pass_gust(void){
	int number=0;
		delay_ms(200);
		uint8 key_pressed = NOT_PRESSED;
				uint8 counter;

		gust_check:
		LCD_Send_string("enter _pass");
		LCD_movecursor(2,4);
		LCD_Send_string("GUEST:");
		uint16 pass_counter=0;
		uint8 pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};

		while (pass_counter<PASS_SIZE)
		{
			while (key_pressed == NOT_PRESSED)
			{
				key_pressed = keypad_press();
			}
			pass[pass_counter]=key_pressed;
			LCD_Send_char(key_pressed);
			delay_ms(100);
			LCD_movecursor(2,10+pass_counter);
			LCD_Send_char('*');
			delay_ms(100);
			pass_counter++;
			key_pressed = NOT_PRESSED;
		}
		uint8 stored_pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};
		EEPROM_ReadBlock(EEPROM_GUEST_ADDRESS,stored_pass,PASS_SIZE);
		if ((ui8ComparePass(pass,stored_pass,PASS_SIZE)) == TRUE){
			LCD_clearscreen();
			LCD_Send_string("Right pass");
			LCD_movecursor(2,1);
			LCD_Send_string("GUEST mode");
			delay_ms(1000);
			LCD_clearscreen();
			}
	else
	{	counter++;
		if (counter==3)
		{
		LCD_clearscreen();
		LCD_Send_string("block");
		delay_ms(50);
		LED_vInit(BLOCK_LED_PORT,BLOCK_LED_PIN);
		LED_vTurnOn(BLOCK_LED_PORT,BLOCK_LED_PIN);
		delay_ms(15000);
		LED_vInit(BLOCK_LED_PORT,BLOCK_LED_PIN);
		LED_vTurnOff(BLOCK_LED_PORT,BLOCK_LED_PIN);
		LCD_clearscreen();
		counter=2;
		goto gust_check;
		}
		LCD_clearscreen();
		LCD_Send_string("wrong pass");
		LCD_movecursor(2,1);
		LCD_Send_string("try again");
		delay_ms(1000);
		LCD_clearscreen();
		goto gust_check;

		
		}
}
void controll(uint8 vale){
	if(vale=='1'){
		controllmenu:
			delay_ms(50);
     LED_vInit(ADMIN_LED_PORT,ADMIN_LED_PIN);
     LED_vTurnOn(ADMIN_LED_PORT,ADMIN_LED_PIN);

	LCD_clearscreen();
	delay_ms(50);
	LCD_Send_string("1:room1");
	LCD_movecursor(1,10);
	LCD_Send_string("2:room2");
	LCD_movecursor(2,1);
	LCD_Send_string("3:room3");
	LCD_movecursor(2,10);
	LCD_Send_string("4:air_c");
	uint8 pressed=NOT_PRESSED;
	while(pressed==NOT_PRESSED){
		pressed=keypad_press();
	}
	if(pressed=='1'|| pressed=='2'|| pressed=='3' ||pressed=='4'){
	if (pressed=='1'){
		 room1();
		 goto controllmenu;
	}
	else if (pressed=='2'){
			 room2();
			 goto controllmenu;
		}
   else if (pressed=='3'){
			room3();
			goto controllmenu;
		}
	else if(pressed=='4'){
				air_condation();
				goto controllmenu;
		}
		
	
	}
   else
		{
			 LCD_clearscreen();
			 LCD_Send_string("incorect input");
			 delay_ms(1000);
			 LCD_clearscreen();
			 goto controllmenu;
		 
	
	}
	}
	
	
	
	else {
			LED_vInit(GUEST_LED_PORT,GUEST_LED_PIN);
			LED_vTurnOn(GUEST_LED_PORT,GUEST_LED_PIN);
				controllmenu_slave:
	            LCD_clearscreen();
				delay_ms(50);
				LCD_Send_string("1:room1");
				LCD_movecursor(1,10);
				LCD_Send_string("2:room2");
				LCD_movecursor(2,1);
				LCD_Send_string("3:room3");
				uint8 pressed=NOT_PRESSED;
				while(pressed==NOT_PRESSED){
					pressed=keypad_press();
				}
				delay_ms(50);
	if(pressed=='1'||pressed=='2'||pressed=='3'){
      	if (pressed=='1'){
					room1();
					goto controllmenu_slave;
				}
       else if (pressed=='2'){
					room2();
					goto controllmenu_slave;
				}
	  else if (pressed=='3'){
					room3();
					goto controllmenu_slave;
				}
				}
			
		
	else{
		LCD_clearscreen();
		LCD_Send_string("incorect input");
		delay_ms(1000);
		LCD_clearscreen();
		goto controllmenu_slave;
	}
	
	
	}
	


	

}
	
	
	
	
	
	
	
	
	
	
	
	
	
