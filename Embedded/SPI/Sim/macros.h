#ifndef MACROS_H_
#define MACROS_H_

#define CLI()	__asm__ __volatile__ ("cli");
#define SEI()	__asm__ __volatile__ ("sei");

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)
#  define __INTR_ATTRS used, externally_visible
#else /* GCC < 4.1 */
#  define __INTR_ATTRS used
#endif

#define ISR(vector)	void vector (void) __attribute__ ((signal, __INTR_ATTRS)); \
void vector (void)


#define REGVALUE8(addr)			(*(volatile u8*) addr)
#define REGVALUE16(addr)		(*(volatile u16*) addr)

#define BITVALUE8(addr,bit)		(REGVALUE8(addr) & (1<<bit))
#define BITVALUE16(addr,bit)	(REGVALUE16(addr) & (1<<bit))

#define SET(addr,bit)			(REGVALUE8(addr) |=  (1<<bit))
#define CLR(addr,bit)			(REGVALUE8(addr) &= ~(1<<bit))



#endif /* MACROS_H_ */