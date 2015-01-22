#include "fb.h"
#include "serial.h"
#include "device.h"

void
init(void)
{
	fb_init();
	serial_init();
}

void
kmain(void)
{
	int i;
	unsigned char s[] = " ";

	init();

	for (i = 0; i < FB_NUM_CELLS; ++i)
	{
		dev_write(1, s, 1);
	}
}
