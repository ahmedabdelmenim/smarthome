#include "check_led.h"
#include "EEPROM.h"
#include "SPI.h"
void check_led(){
if(EEPROM_ReadByte(0x111)!=0xff){
	SPI_ui8TransmitRecive(ROOM1_TURN_ON);
	}
if(EEPROM_ReadByte(0x112)!=0xff){
		SPI_ui8TransmitRecive(ROOM2_TURN_ON);
	}
if(EEPROM_ReadByte(0x113)!=0xff){
		SPI_ui8TransmitRecive(ROOM3_TURN_ON);
	}
if(EEPROM_ReadByte(0x114)!=0xff){
	SPI_ui8TransmitRecive(AIR_COND_TURN_ON);
}
}