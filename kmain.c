#include "fb.h"

void
kmain(void)
{
	char s[] = "Hello World ";
	char s2[] = "cenas e coisas";
	int i;

	fb_init();
	for (i = 0; i < 600; ++i)
	{
		write(s, sizeof(s));
		write(s2, sizeof(s2));
	}

}
