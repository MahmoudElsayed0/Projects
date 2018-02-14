#include "LCD.h"

int main(void)
{
	LCDInit();
	
	
	while(1)
	{
		DisplayStringinXY("Mahmoud",0,1);
		DisplayStringinXY("ELsayed",4,2);
		delay_ms(4000);
		CLEARALL();
		DisplayStringinXY("My",0,2);
		DisplayStringinXY("Hi",12,2);
		delay_ms(4000);
		CLEARALL();
		
		
	}
	return 0;
}

