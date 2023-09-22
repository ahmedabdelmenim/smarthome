#include "SPI.h"
#include "STD_MESSAGES.h"
#include "DIO.h"
#include "LED.h"
#include "ADC_driver.h"
#include "timer_driver.h"
#include "APP_slave_Macros.h"
#define  requried_temp 23
volatile uint16 temp=0;
volatile uint8 counter=0;
volatile air_conadtion_stat =0;
uint8 request;
int main(void)
{

	
		ADC_vinit();
	timer0_initializeCTC();
	SPI_vInitSlave();
	LED_vInit(AIR_COND_PORT,AIR_COND_PIN);
	LED_vInit(ROOM1_PORT,ROOM1_PIN);
	LED_vInit(ROOM2_PORT,ROOM2_PIN);
	LED_vInit(ROOM3_PORT,ROOM3_PIN);
	while(1)
	{
		request = SPI_ui8TransmitRecive(DEFAULT_ACK);
		switch (request)
		{
			case ROOM1_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM1_PIN);
			break;
			case ROOM2_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM2_PIN);
			break;
			case ROOM3_TURN_ON:
			LED_vTurnOn(ROOM3_PORT,ROOM3_PIN);
			break;
			
			case AIR_COND_TURN_ON:
			timer0_initializeCTC();
			LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);
			air_conadtion_stat=1;
			break;
			case ROOM1_TURN_OFF:
			LED_vTurnOff(ROOM1_PORT,ROOM1_PIN);
			break;
			case ROOM2_TURN_OFF:
			LED_vTurnOff(ROOM2_PORT,ROOM2_PIN);
			break;
			case ROOM3_TURN_OFF:
			LED_vTurnOff(ROOM3_PORT,ROOM3_PIN);
			break;
			
			case AIR_COND_TURN_OFF:
			timer0_stop();
			LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);
			air_conadtion_stat=0;
			break;
			
		}
	}
}

ISR(TIMER0_COMP_vect)
{
	counter++;
	if(counter>=10){
		counter=0;
		if (air_conadtion_stat){
			temp =(0.25*ADC_u16Read());
			if ( requried_temp>=temp  ){
				LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);

			}
			else
			{
				LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);

			}
		}
	}
}