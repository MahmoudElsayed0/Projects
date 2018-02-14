#ifndef SPI_H_
#define SPI_H_

#include "Atmega128.h"
#include "macros.h"
#include "types.h"


void SPIinit(SetMSTR_SS Master_Slave, MasterPrescaler SPIReg1, MasterPrescaler SPIReg2, SPIDoubleSpeed isDouble, DataOrder DOrder);
void MSPISendChar(u8 data);
void SSPISendChar(u8 data);
void MSPIRead();
void SSPIRead();


static volatile u8 TransComplete = 1;
static volatile u8 isBurstMode   = 0;
static volatile u8 isRead		 = 0;
volatile u8*databuffer;


#endif /* SPI_H_ */