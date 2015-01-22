#include "gdt.h"

void
init_gdt(void)
{
	struct gdt g =	{ 0x0, (short) -1U };
	load_gdt(g);
}
