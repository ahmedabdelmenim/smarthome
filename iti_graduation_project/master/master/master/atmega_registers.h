#include "STD_Types.h"
#ifndef ATMEGA_REGISTERIES_H_
#define ATMEGA_REGISTERIES_H_

#define PORTA (*(volatile uint8*)(0x3B))
#define DDRA  (*(volatile uint8*)(0x3A))
#define PINA  (*(volatile uint8*)(0x39))

#define PORTB (*(volatile uint8*)(0x38))
#define DDRB  (*(volatile uint8*)(0x37))
#define PINB  (*(volatile uint8*)(0x36))

#define PORTC (*(volatile uint8*)(0x35))
#define DDRC  (*(volatile uint8*)(0x34))
#define PINC  (*(volatile uint8*)(0x33))

#define PORTD (*(volatile uint8*)(0x32))
#define DDRD  (*(volatile uint8*)(0x31))
#define PIND  (*(volatile uint8*)(0x30))

//***************************************************
//External Interrupts Registers

//Status Register - Responsible for global interrupt enable
//Bit no.7 enable global interrupt (Bit no.7 initially equal 0)
#define SREG  	(*(volatile uint8*)(0x5F))

//General Interrupt Control Register - Responsible for enabling external interrupt request
//(INT1 , INT0 , INT2) -- (bit no. 7,6,5)
#define GICR  	(*(volatile uint8*)(0x5B))

//MCU Control Register - Responsible for trigger type
//For interrupt0  ( 1 , 0 )
//For interrupt1  ( 3 , 2 )
#define MCUCR 	(*(volatile uint8*)(0x55))

//MCU Control and Status Register - Responsible for trigger type
//For interrupt2
#define MCUCSR 	(*(volatile uint8*)(0x54))


//General Interrupt Flag Register
//(INT1 ,INT0 , INT2) -- (bit no. 7,6,5)
#define GIFR 	(*(volatile uint8*)(0x5A))
//***************************************************
//ADC Registers

#define ADMUX 		(*(volatile uint8*)(0x27))
#define ADCSRA 		(*(volatile uint8*)(0x26))
#define SFIOR       (*(volatile uint8*)(0x50))
#define ADC_D_VAL 	(*(volatile uint16*)(0x24))

//***************************************************
//Timer0 Registers

#define TCCR0 		(*(volatile uint8*)(0x53))
#define TIMSK 		(*(volatile uint8*)(0x59))
#define TCNT0 		(*(volatile uint8*)(0x52))
#define OCR0 		(*(volatile uint8*)(0x5C))

//***************************************************
//Timer1 Registers
#define TCCR1A 		(*(volatile uint8*)(0x4F))
#define TCCR1B 		(*(volatile uint8*)(0x4E))

#define OCR1A 		(*(volatile uint16*)(0x4A))

#define ICR1L 		(*(volatile uint8*)(0x46))
#define ICR1H		(*(volatile uint8*)(0x47))

#define ICR1 		(*(volatile uint16*)(0x46))

#define ACSR 		(*(volatile uint8*)(0x28))

//**************************************************
//WatchDog Register
#define WDTCR  		(*(volatile uint8*)(0x41))

//****************************************************
//UART

#define UBRRH   (*(volatile uint8*)(0x40))
#define UBRRL   (*(volatile uint8*)(0x29)) //baudrate register
#define UCSRA   (*(volatile uint8*)(0x2B))
#define UCSRB   (*(volatile uint8*)(0x2A))
#define UCSRC   (*(volatile uint8*)(0x40))
#define UDR     (*(volatile uint8*)(0x2C))
#define PORTA (*(volatile uint8*)(0x3B))
#define DDRA  (*(volatile uint8*)(0x3A))
#define PINA  (*(volatile uint8*)(0x39))

#define PORTB (*(volatile uint8*)(0x38))
#define DDRB  (*(volatile uint8*)(0x37))
#define PINB  (*(volatile uint8*)(0x36))

#define PORTC (*(volatile uint8*)(0x35))
#define DDRC  (*(volatile uint8*)(0x34))
#define PINC  (*(volatile uint8*)(0x33))

#define PORTD (*(volatile uint8*)(0x32))
#define DDRD  (*(volatile uint8*)(0x31))
#define PIND  (*(volatile uint8*)(0x30))

//***************************************************
//External Interrupts Registers

//Status Register - Responsible for global interrupt enable
//Bit no.7 enable global interrupt (Bit no.7 initially equal 0)
#define SREG  	(*(volatile uint8*)(0x5F))

//General Interrupt Control Register - Responsible for enabling external interrupt request
//(INT1 , INT0 , INT2) -- (bit no. 7,6,5)
#define GICR  	(*(volatile uint8*)(0x5B))

//MCU Control Register - Responsible for trigger type
//For interrupt0  ( 1 , 0 )
//For interrupt1  ( 3 , 2 )
#define MCUCR 	(*(volatile uint8*)(0x55))

//MCU Control and Status Register - Responsible for trigger type
//For interrupt2
#define MCUCSR 	(*(volatile uint8*)(0x54))


//General Interrupt Flag Register
//(INT1 ,INT0 , INT2) -- (bit no. 7,6,5)
#define GIFR 	(*(volatile uint8*)(0x5A))
//***************************************************
//ADC Registers

#define ADMUX 		(*(volatile uint8*)(0x27))
#define ADCSRA 		(*(volatile uint8*)(0x26))
#define SFIOR       (*(volatile uint8*)(0x50))
#define ADC_D_VAL 	(*(volatile uint16*)(0x24))

//***************************************************
//Timer0 Registers

#define TCCR0 		(*(volatile uint8*)(0x53))
#define TIMSK 		(*(volatile uint8*)(0x59))
#define TCNT0 		(*(volatile uint8*)(0x52))
#define OCR0 		(*(volatile uint8*)(0x5C))

//***************************************************
//Timer1 Registers
#define TCCR1A 		(*(volatile uint8*)(0x4F))
#define TCCR1B 		(*(volatile uint8*)(0x4E))

#define OCR1A 		(*(volatile uint16*)(0x4A))

#define ICR1L 		(*(volatile uint8*)(0x46))
#define ICR1H		(*(volatile uint8*)(0x47))

#define ICR1 		(*(volatile uint16*)(0x46))

#define ACSR 		(*(volatile uint8*)(0x28))

//**************************************************
#define SPCR 		(*(volatile uint8*)(0x2D))
#define SPDR 		(*(volatile uint8*)(0x2F))
#define SPSR 		(*(volatile uint8*)(0x2E))

#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0
#define SPIF    7
#define WCOL    6


//eeprom===================================================
#define EEDR     (*(volatile uint8*)(0x3D))
#define EECR     (*(volatile uint8*)(0x3c))
#define EEAR     (*(volatile uint8*)(0x3E))





/* EEPROM Control Register */
#define EERIE   3
#define EEMWE   2
#define EEWE    1
#define EERE    0

#define PUD 2


#define  COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0



#endif /* ATMEGA_REGISTERIES_H_ */