#ifndef _UART_H
#define _UART_H

#include "types.h"
#include "Atmega128.h"
#include "stdlib.h"

#define  BAUDRATE(baudrate)	((F_CPU / (16UL * baudrate)) - 1)

void UARTInit(u16 baudrate);
void SendChar(u8 data);
void SendString(u8* data);
u8 GetChar(void);


#endif