#include "EEPROM.h"

uint8 EEPROM_ReadByte(const uint16 u16Address)
{
	while (((EECR & (1 << EEWE))>>EEWE)==1);
	EEAR = u16Address;
	EECR |= (1 << EERE);
	return EEDR;
}

void EEPROM_ReadBlock(const uint16 uiAddress, uint8* dist,const uint16 size)
{
	while (((EECR & (1 << EEWE))>>EEWE)==1);

	uint16 counter = 0;
	while (counter < size) 
	{
		EEAR = uiAddress + counter;
		EECR |= (1 << EERE);
		*(dist + counter) = EEDR;

		counter++;
	}
}

void EEPROM_WriteByte(const uint16 uiAddress, const uint8 uiData)
{

	while ( ( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
	;
	EEAR = uiAddress;

	EECR |= (1 << EERE);
	if (EEDR != uiData)
	{
		EEDR = uiData;

		EECR |= (1 << EEMWE);
		EECR |= (1 << EEWE);
	}
	else
	{

	}

}

void EEPROM_WriteBlock(const uint16 uiAddress, const uint8* uiData,const uint16 size)
{
	uint16 counter = 0;
	while (counter < size)
	{
		while (( (EECR & (1 << EEWE) ) >>EEWE ) == 1);
		EEAR = uiAddress + counter;

		EECR |= (1 << EERE);
		if (EEDR != (*(uiData + counter)))
		{
			EEDR = *(uiData + counter);

			EECR =EECR| (1 << EEMWE);
			EECR |= (1 << EEWE);
		}
		else
		{

		}
		counter++;
	}
}
uint8 ui8ComparePass(const uint8* pass1,const uint8* pass2,const uint8 size)
{
	uint8 pin_counter=0;//the offset of the character of the pin
	uint8 ret_value = 1;
	while (pin_counter<size)//loop till the pin is fully entered
	{
		if (*(pass1+pin_counter)!=*(pass2+pin_counter))//if the two characters of the entered pin and the stored pin are not equal
		{
			ret_value= 0;//returns false that means the two PINs are not equal
			break;//break the loop
		}
		pin_counter++;//increase thee offset by one
	}
	return ret_value;//returns false that means the two PINs are equal since all characters of the PINs are equal
}
