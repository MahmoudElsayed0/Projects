#ifndef _LCD_H
#define _LCD_H
#include "types.h"
#include "Atmega128.h"
#include "macros.h"
#include "LCDCommand.h"
#define F_CPU 8000000UL
#include "util/delay.h"

// General function 
//#define SET(addr,bit)		(*(volatile char*)addr |=  (1<<bit))
#define CLEAR(addr,bit)		(*(volatile char*)addr &= ~(1<<bit))

// Control pins PORTD
#define LCD_CONTROL_DDIR	0X31
#define LCD_CONTROL_PORT  	0X32


// Data pins PORTE
#define LCD_DATA_DDIR		0X22
#define LCD_DATA_PORT  		0X23
#define PIN_A				0x21

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
void LCDWriteCommand(u8 Commd);
void DisplayChar(u8 data);
void DisplayCharinXY(u8 data, u8 x, u8 y);
void GOtoXY(u8 x, u8 y);
void CLEARALL();
void DisplayString(u8*str);
void DisplayStringinXY(u8*str, u8 x, u8 y);
void BusyFlag();
#endif