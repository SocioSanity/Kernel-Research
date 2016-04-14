#include "types.h"	// uint16_t ETC.
#include "mem.h"	// memcpy and memset
#include "basicio.h"// inbyte and outbyte

void cmain ( unsigned long magic, unsigned long addr)
{
	vga_init();
	puts ((uint8_t*)"Hello World!");
	for (;;); //start infinite loop
}
