#include "fb.h"
#include "serial.h"
#include "device.h"
#include "gdt.h"

void
init(void)
{
	init_gdt();
	fb_init();
	serial_init();
}

void
clear(void)
{
	int i;
	unsigned char s[] = " ";
	for (i = 0; i < FB_NUM_CELLS; ++i)
		dev_write(0, s, 1);	
}

void
kmain(void)
{
	unsigned char s[] = "abcdefghijklmnopqrstuvxwyz";

	init();

	clear();
	dev_write(1, s, sizeof(s));
}
