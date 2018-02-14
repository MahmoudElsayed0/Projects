#ifndef _LCD_H
#define _LCD_H
#include "types.h"
#include "Atmega128.h"
#include "LCDCommand.h"
#include <util/delay.h>

// General function 
#define SET(addr,bit)		(*(volatile char*)addr |=  (1<<bit))
#define CLEAR(addr,bit)		(*(volatile char*)addr &= ~(1<<bit))

// Control pins PORTB
#define LCD_CONTROL_DDIR	0X37
#define LCD_CONTROL_PORT  	0X38


// Data pins PORTA
#define LCD_DATA_DDIR		0X3A
#define LCD_DATA_PORT  		0X3B
#define PIN_A				0x39

#define LCD_EN 	7
#define LCD_RW 	6
#define LCD_RS 	5

#define LCD_D7 	7
#define LCD_D6 	6
#define LCD_D5 	5
#define LCD_D4 	4

#define SETEN()	SET(LCD_CONTROL_PORT,LCD_EN)
#define CLREN()	CLEAR(LCD_CONTROL_PORT,LCD_EN)

#define SETRW()	SET(LCD_CONTROL_PORT,LCD_RW)
#define CLRRW()	CLEAR(LCD_CONTROL_PORT,LCD_RW)

#define SETRS()	SET(LCD_CONTROL_PORT,LCD_RS)
#define CLRRS()	CLEAR(LCD_CONTROL_PORT,LCD_RS)

#define SETD7()	SET(LCD_DATA_PORT,LCD_D7)
#define CLRD7()	CLEAR(LCD_DATA_PORT,LCD_D7)

#define SETD6()	SET(LCD_DATA_PORT,LCD_D6)
#define CLRD6()	CLEAR(LCD_DATA_PORT,LCD_D6)

#define SETD5()	SET(LCD_DATA_PORT,LCD_D5)
#define CLRD5()	CLEAR(LCD_DATA_PORT,LCD_D5)

#define SETD4()	SET(LCD_DATA_PORT,LCD_D4)
#define CLRD4()	CLEAR(LCD_DATA_PORT,LCD_D4)

#define LCD_CONTROL_MASK	((1<<LCD_EN)|(1<<LCD_RW)|(1<<LCD_RS))
#define LCD_DATA_MASK		((1<<LCD_D7)|(1<<LCD_D6)|(1<<LCD_D5)|(1<<LCD_D4))


void LCDInit(void);
void LCDWriteCommand(unint8_t Commd);
void DisplayChar(unint8_t data);
void DisplayCharinXY(unint8_t data, unint8_t x, unint8_t y);
void GOtoXY(unint8_t x, unint8_t y);
void CLEARALL();
void DisplayString(unint8_t*str);
void DisplayStringinXY(unint8_t*str, unint8_t x, unint8_t y);
void BusyFlag();
#endif