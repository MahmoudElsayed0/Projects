#ifndef _LCDCommand_H
#define _LCDCommand_H

#define CLEAR_DISP			0x01
#define RET_HOME			0x02
#define	DEC_CURSOR			0x04
#define INC_CURSOR			0x06
#define SH_DIS_RIGHT		0x05
#define SH_DIS_sLEFT		0x07
#define DISOFF_CURSOFF		0x08
#define DISOFF_CURSON		0x0A
#define DISON_CURSOFF		0x0C
#define DISON_CURSBLINK		0x0E
#define	SH_CUR_LEFT			0x10
#define	SH_CUR_RIGHT		0x14
#define SH_ENTIR_LEFT		0x18
#define SH_ENTIR_RIGHT		0x1C

// Function set
#define _4BIT_ONELINE_5X8	0x20
#define _4BIT_ONELINE_5X10	0x24
#define _4BIT_TWOLINE_5X8	0x28
#define _4BIT_TWOINE_5X10	0x2A
#define _8BIT_ONELINE_5X8	0x30
#define _8BIT_ONELINE_5X10	0x34
#define _8BIT_TWOLINE_5X8	0x38
#define _8BIT_TWOINE_5X10	0x3A


#define FIRST_LINE_ADDR		0x80
#define SECOND_LINE_ADDR	0xC0

#endif