#ifndef _GDT_H
#define _GDT_H

struct gdt
{
	unsigned int	address;
	unsigned short	size;
} __attribute__((packed));

struct gdt_entry
{
	unsigned short	limit;
	unsigned short	base1;
	unsigned char	base2;
	unsigned char	dpl;
	unsigned char	limit2;
	unsigned char	base3;
} __attribute__((packed));

void
init_gdt(void);

extern void
load_gdt(struct gdt g);



#endif /* _GDT_H */
