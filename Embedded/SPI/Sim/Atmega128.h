#ifndef ATMEGA128_H_
#define ATMEGA128_H_


#define _VECTOR(N) __vector_ ## N
#define SPI_STC_vect			_VECTOR(17)

// PORTB
#define PORTB	0x38
#define DDRB	0x37
#define PINB	0x36
#define SS		0
#define SCK		1
#define MOSI	2
#define MISO	3

// SPI 
#define SPDR	0x2F

#define SPSR	0x2E
#define SPIF	7
#define WCOL	6
#define SPI2X	0

#define SPCR	0x2D
#define	SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

#endif /* ATMEGA128_H_ */
