void cmain ( unsigned long magic, unsigned long addr)
{
	vga_init();
	puts ((uint8_t*)"Hello World!");
	for (;;); //start infinite loop
}
