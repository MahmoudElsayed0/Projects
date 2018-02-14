#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char u8;
typedef char		  s8;

typedef unsigned short int u16;
typedef short int  		   s16;
typedef enum{ NORMAL, DOUBLE}SPIDoubleSpeed;
typedef enum{ MASTER0, MASTER1}MasterPrescaler;
typedef enum{ MSBFIRST,LSBFIRST}DataOrder;
typedef enum{ SLAVE, MASTER}SetMSTR_SS;

#endif /* TYPES_H_ */