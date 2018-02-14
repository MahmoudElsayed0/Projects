#ifndef _ATMEGA32_REG_H
#define _ATMEGA32_REG_H
#include "types.h"
#include "macros.h"

// USART0
#define UBRR0L	0x29

#define UCSR0B	0x2A
#define	RXCIE0	7
#define TXEN0	3
#define RXEN0	4

#define UCSR0A	0x2B
#define U2X		1
#define PE		2
#define DOR		3
#define FE		4
#define UDRE0	5
#define RXC0	7
#define TXC0	6

#define UDR0	0x2C

#define UBRR0H	0x40

#define UCSR0C	0x40
#define UCPOL	0
#define UCSZ00	1
#define UCSZ01	2
#define USBS0	3
#define UPM01	5
#define UMSEL	6
#define URSEL	7


#endif