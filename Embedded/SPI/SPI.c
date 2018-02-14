#include "SPI.h"

/*
	SetMSTR_SS		take either Master   Or Slave
	MasterPrescaler take either MASTER0  Or MASTER1
	SPIDoubleSpeed	take either FALSE	 Or TRUE
	DataOrder		take either MSBFIRST Or LSBFIRST
*/
void SPIinit(SetMSTR_SS Master_Slave, MasterPrescaler SPIReg1, MasterPrescaler SPIReg2, SPIDoubleSpeed isDouble, DataOrder DOrder)
{

	if(Master_Slave)
	{		
		REGVALUE8(DDRB) |= ((1<<MOSI) | (1<<SCK) | (1<<SS));	// Output
		SET(SPCR,MSTR);											// Master	
	}
	else
	{
		SET(DDRB,MISO);											// Output
		CLR(SPCR,MSTR);											// Slave
	}
	
	SPIReg1		?	SET(SPCR, SPR0)	:	CLR(SPCR, SPR0);
	SPIReg2		?	SET(SPCR, SPR1)	:	CLR(SPCR, SPR1);
	DOrder		?	SET(SPCR,SPR1)	:	CLR(SPCR, DORD);
	isDouble	?	SET(SPSR,SPI2X)	:	CLR(SPSR,SPI2X);
	
	REGVALUE8(SPCR)  |= ((1<<SPE) | (1<<SPIE));
	REGVALUE8(PORTB) |= (1<<SS);
}

void MSPISendChar(u8 data)
{
	CLR(PORTB,SS);
	if(TransComplete)
	{
		REGVALUE8(SPDR) = data;
		CLI();
		TransComplete = 0;
		SEI();
	}
	else
		{/* do nothing*/}
}

void SSPISendChar(u8 data)
{
	if(TransComplete)
	{
		REGVALUE8(SPDR) = data;
		CLI();
		TransComplete = 0;
		SEI();
	}
	else
	{/* do nothing*/}
}


void MSPIRead()
{
	isRead = 1;
	MSPISendChar(0xFF);
}

void SSPIRead()
{
	while(!BITVALUE8(SPSR,SPIF));
	*databuffer = REGVALUE8(SPDR);
}

ISR(SPI_STC_vect)
{
	CLI();

	TransComplete = 1;
	
	isBurstMode ? CLR(PORTB,SS) : SET(PORTB,SS);
	
	if(isRead)
	{
		*databuffer = REGVALUE8(SPDR);
		isRead = 0;
	}

}