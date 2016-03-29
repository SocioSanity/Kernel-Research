#include "types.h"	// uint16_t ETC.
#include "mem.h"	// memcpy and memset
#include "basicio.h"// inbyte and outbyte

#define COLOURS 0xF0
#define COLS 80
#define ROWS 25
#define VGA_START 0xB8000
#define PRINTABLE(c) (c>=' ') // is this a printable character?

uint16_t *Scrn; //screen area
int Curx, Cury = 0; //current cursor cordinates
uint16_t EmptySpace = COLOURS << 8 | 0x20; // 0x20 is the ascii value of space

// scroll the screen 
void scroll(void)
{
	int dist = Cury - ROWS + 1;
	
	if (dist > 0) {
		uint8_t *newstart = ((uint8_t*) Scrn) + dist * COLS *2;
		int bytesToCopy = (ROWS-dist)*COLS*2;
		uint16_t *newblankstart = Scrn + (ROWS-dist) * COLS;
		int bytesToCopy = dist*COLS*2
		memcpy ((uint8_t*)Scrn, newstart, bytesToCopy)
		memset ((uint8_t*) newblankstart, EmptySpace, bytesToCopy)
	}
}

// print a character to the screen

viod putchar (uint8_t c)
{
	uint16_t *addr;
	
	// first lets handle some special characters
	// tab -> handle move cursor in steps of 4
	if (c == '\t') Curx = ((Curx + 4)/4)* 4;
	//carriage return -> reset x pos
	else if (c == '\r') Curx = 0;
	//newline: reset x pos and go to newline
	else if(c == '\n')
	{
		Curx = 0;
		Cury++;
	}
	// backspace -> cursor moves left
	else if(c == 0x08 && Curx != 0) Curx--;
	//finally, if a normal character, print it
	else if(PRINTABLE(c))
	{
		addr = Scrn + (Cury * COLS + Curx);
		*addr = (COLOURS<<8) | c;
		Curx++;
	}
	// if we have reached the end of the line, move to the next
	if (Curx >= Cols)
	{
		Curx = 0;
		Cury++
	}
	// also scroll if needed
	scroll();
}
