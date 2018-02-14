#include "UART.h"

void UARTInit(u16 baudrate)
{
	// Set BaudRate
	REGVALUE(UBRR0L) = BAUDRATE(baudrate);
	REGVALUE(UBRR0H) = BAUDRATE(baudrate) >> 8;

	// Frame Format: 8 bit, no parity, 1 stop bit
	REGVALUE(UCSR0C) |= ((1<<UCSZ00) | (1<<UCSZ01));
	
	// Enable TX and RX
	REGVALUE(UCSR0B) |= ((1<<RXEN0) | (1<<TXEN0));

}
void SendChar(u8 data)
{
	while(! ( BITVALUE( UCSR0A, UDRE0 ) ) );
	REGVALUE(UDR0) = data;
}
u8 GetChar( void )
{
	while (! ( BITVALUE( UCSR0A , RXC0 ) ) );
	return UDR0;
}
void SendString(u8* data)
{
	u16 i;
	for(i = 0; data[i] != '\0'; i++)
		SendChar(data[i]);
}