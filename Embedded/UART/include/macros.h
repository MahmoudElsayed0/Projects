#define F_CPU 8000000UL

#define SREG	0x5F
#define I		7

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)
#  define __INTR_ATTRS used, externally_visible
#else /* GCC < 4.1 */
#  define __INTR_ATTRS used
#endif

#define ISR(vector)	void vector (void) __attribute__ ((signal, __INTR_ATTRS)); \
void vector (void)

#define _VECTOR(N) __vector_ ## N

#define USART_RXC_vect_num		13
#define USART_RXC_vect			_VECTOR(13)

#define REG16(addr)			(*(volatile unint16_t*)addr)
#define REGVALUE(addr)		(*(volatile char*)addr)
#define BITVALUE(addr, bit)	(*(volatile char*)addr & (1<<bit))

#define sei		__asm__  __volatile__ ("sei")
#define cli		__asm__  __volatile__ ("cli")
