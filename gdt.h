#ifndef _GDT_H
#define _GDT_H

struct gdt
{
	unsigned int	address;
	unsigned short	size;
} __attribute__((packed));

void
init_gdt(void);

extern void
load_gdt(struct gdt g);

#endif /* _GDT_H */
