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

	init();

	for (i = 0; i < FB_NUM_CELLS; ++i)
	{
		dev_write(2, (unsigned char *) " ", 1);
	}
}
