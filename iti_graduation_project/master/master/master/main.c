#include "main_config.h"
#include "LCD.h"
#include "EEPROM.h"
#include "timer_driver.h"
#include "keypad_driver.h"
#include "SPI.h"
#include "LED.h"
#include "smart_home.h"
#include "check_led.h"
	
int main(void){
	LCD_Init();
	keypad_Init();
	SPI_vInitMaster();
	check_led();
	LCD_Send_string("welcom");
	delay_ms(1000);
	LCD_clearscreen();
	first_time();
	uint8 value =chose_user();
	if (value=='1')
	{
		check_pass_admin();
	}
	else
	{
		check_pass_gust();
	}
	controll(value);


return 0;
}

