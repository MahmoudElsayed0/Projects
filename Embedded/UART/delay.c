#include "Atmega128.h"

void delay_ms(unint16_t ms)
{
	unint8_t  oldTCCR = REGVALUE(TCCR1B);
	unint16_t oldOC   = REGVALUE(OCR1A);

	REGVALUE(TCCR1B)	|= ((1<<CS10)|(1<<CS12)|(1<<WGM12));	// Prescaler 1024, CTC mode
	
	#if F_CPU == 16000000UL
		if(ms <= 4194)
		{
			REG16(OCR1A) = ((F_CPU/1024)*(ms/1000));
			REG16(TCNT1) = 0;
			while(!BITVALUE(TIFR1,OCFA));
		}
		else
		{
			REG16(OCR1A) = ((F_CPU/1024)*(ms/1000));
			REG16(TCNT1) = 0;
			while(ms >= 0)
			{
				while(!BITVALUE(TIFR1,OCFA));
				ms -= 4194;
				if(ms < 4194)
				{
					REG16(OCR1A) = ((F_CPU/1024)*(ms/1000));
					REG16(TCNT1) = 0;
					while(!BITVALUE(TIFR1,OCFA));
					break;
				}
			}
		}
	#elif F_CPU == 8000000UL
		if(ms <= 8388)
		{
			
			REG16(OCR1A) = ((F_CPU/1024)*(ms/1000));
			REG16(TCNT1) = 0;
			while(!BITVALUE(TIFR1,OCFA));
		}
		else
		{
			REG16(OCR1A) = ((F_CPU/1024)*(ms/1000));
			REG16(TCNT1) = 0;
			while(ms >= 0)
			{
				while(!BITVALUE(TIFR1,OCFA));
				ms -= 8388;
				if(ms < 8388)
				{
					REG16(OCR1A) = ((F_CPU/1024)*(ms/1000));				
					while(!BITVALUE(TIFR1,OCFA));
					break;
				}
			}
		}
	#endif
	REGVALUE(TCCR1B) = oldTCCR;
	REGVALUE(OCR1A) = oldOC;
	REGVALUE(TIFR1)  |= (1<<OCFA);
}
