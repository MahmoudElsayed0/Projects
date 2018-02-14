/*#include "SPI.h"
#include "LCD.h"


// Slave code: receive some data and print it on LCD 
int main(void)
{
	
	SPIinit(SLAVE, MASTER0, MASTER0, NORMAL, MSBFIRST);
	LCDInit();
	while(1)
	{
		
		SSPIRead();
		if(*databuffer == 'M')
		{
			CLEARALL();
			DisplayCharinXY(*databuffer,0,1);
		}
		else
			DisplayChar(*databuffer);
		
	}
	return 0;
	
}*/