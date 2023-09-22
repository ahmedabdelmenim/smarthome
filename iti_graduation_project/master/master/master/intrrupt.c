#include "intrrupt.h"
#include "atmega_registers.h"
void int_int(void){
SREG |=(1<<7);
GICR |=(1<<7);
MCUCR |=(0<<2);
MCUCR &=(1<<3);
}
