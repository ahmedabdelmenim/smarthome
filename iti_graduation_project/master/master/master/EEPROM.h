

#ifndef HEADERS_EEPROM_H_
#define HEADERS_EEPROM_H_c

#include "STD_Types.h"
#include "atmega_registers.h"

uint8 EEPROM_ReadByte(const uint16 u16Address);


void EEPROM_ReadBlock(const uint16 u16Address, uint8* dist,const uint16 size);


void EEPROM_WriteByte(const uint16 u16Address, const uint8 u8Data);


void EEPROM_WriteBlock(const uint16 u16Address, const uint8* u8Data,const uint16 size);


uint8 ui8ComparePass(const uint8* pass1,const uint8* pass2,const uint8 size);


#endif 
