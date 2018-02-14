#include "SPI.h"
#define F_CPU 8000000UL
#include "util/delay.h"

// Master Code: send some data to slave with time latency of 1 second
int main(void)
{
	
	char *name = "Mahmoud";
	SEI();
	SPIinit(MASTER, MASTER0, MASTER0, NORMAL, MSBFIRST);
	while(1)
	{
		for(u8 i=0; name[i] != '\0'; i++)
		{
			MSPISendChar(name[i]);
			//_delay_ms(41); the minmum time needed between packets 
			_delay_ms(1000);
		}
		
	}
	return 0;
}