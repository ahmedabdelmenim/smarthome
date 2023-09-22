


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_
#define NOT_PRESSED 0xff
#include "DIO.h"


void keypad_Init(void);


uint8 keypad_press(void);

#endif /* KEYPAD_DRIVER_H_ */