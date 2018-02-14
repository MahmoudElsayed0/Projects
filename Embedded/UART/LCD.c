#include "LCD.h"

void LCDInit(void)
{
	
	REGVALUE(LCD_CONTROL_DDIR) |= LCD_CONTROL_MASK;
	REGVALUE(LCD_CONTROL_PORT) &= ~(LCD_CONTROL_MASK);
	
	REGVALUE(LCD_DATA_DDIR) |= LCD_DATA_MASK;
	REGVALUE(LCD_DATA_PORT) &= ~(LCD_DATA_MASK);
	
	_delay_ms(20);
	LCDWriteCommand(0x32);
	LCDWriteCommand(_4BIT_TWOLINE_5X8);
	LCDWriteCommand(DISON_CURSOFF);
	LCDWriteCommand(INC_CURSOR);
	LCDWriteCommand(CLEAR_DISP);
	_delay_ms(5);
}
void LCDWriteCommand(unint8_t commd)
{
	// Write in IR
	CLRRS();
	CLRRW();
	
	commd & 0x80 ? SETD7() : CLRD7();
	commd & 0x40 ? SETD6() : CLRD6();
	commd & 0x20 ? SETD5() : CLRD5();
	commd & 0x10 ? SETD4() : CLRD4();

	SETEN();
	CLREN();
	
	commd & 0x08 ? SETD7() : CLRD7();
	commd & 0x04 ? SETD6() : CLRD6();
	commd & 0x02 ? SETD5() : CLRD5();
	commd & 0x01 ? SETD4() : CLRD4();
	
	SETEN();
	CLREN();
	
	BusyFlag();
}
void DisplayChar(unint8_t data)
{
	
	// Write in DR
	SETRS();
	CLRRW();

	data & 0x80 ? SETD7() : CLRD7();
	data & 0x40 ? SETD6() : CLRD6();
	data & 0x20 ? SETD5() : CLRD5();
	data & 0x10 ? SETD4() : CLRD4();
	
	SETEN();
	CLREN();

	data & 0x08 ? SETD7() : CLRD7();
	data & 0x04 ? SETD6() : CLRD6();
	data & 0x02 ? SETD5() : CLRD5();
	data & 0x01 ? SETD4() : CLRD4();
	
	SETEN();
	CLREN();

	BusyFlag();

}
void GOtoXY(unint8_t x, unint8_t y)
{
	if(y == 1)
		LCDWriteCommand(FIRST_LINE_ADDR  + x);
	else if(y == 2)
		LCDWriteCommand(SECOND_LINE_ADDR + x);	
}
/* 
	Pos,  Line  
	Line: 1 -> End (2,4,...) 
	Pos:  0 -> End (15,23,...)
*/
void DisplayCharinXY(unint8_t data, unint8_t x, unint8_t y)
{
	GOtoXY(x,y);
	DisplayChar(data);
}
void CLEARALL()
{
	LCDWriteCommand(CLEAR_DISP);
	_delay_ms(40);
}
void DisplayString(unint8_t*str)
{
	unint8_t i;
	for(i=0; str[i] != '\0';i++)
		DisplayChar(str[i]);
}
void DisplayStringinXY(unint8_t*str, unint8_t x, unint8_t y)
{
	GOtoXY(x,y);
	DisplayString(str);
}
void BusyFlag()
{
	/*REGVALUE(LCD_DATA_DDIR) &= ~(1<<LCD_D7);
	REGVALUE(LCD_DATA_PORT) |=  (1<<LCD_D7);
	SETEN();
	while(!BITVALUE(PIN_A, LCD_D7))
	{
		CLREN();
		//__asm__("nop");
		SETEN();
	}
	CLREN();
	REGVALUE(LCD_DATA_DDIR) |=  (1<<LCD_D7);*/
	_delay_us(40);
}






