// we use inbyte for reading data from the i/o ports
// to get data from * devices such as keyboard.
// to do so, we need the 'inb' instruction,
// which is only accessable from assembly. so
// the C function is simply a wrapper around a
// single assembly instruction
uint8_t inbyte (uint_16_t port)
{
	uint8_t ret;
	__asm__ __volitile__ ( "inb %1, %0" : "=a" (ret) : "d" (port));
	return ret;
}
// we use outbyte to write to i/o ports, ie to send bytes to devices.
// again we use inline assembly for the stuff that cannot be done in C

void outbyte (uint16_t port, uint8_t data)
{
	__asm__ __volitile__ ("out %1, %0" : : "d" (port), "a" (data))
}