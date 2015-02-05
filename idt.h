#ifndef _IDT_H
#define _IDT_H

#define NUM_IRQS	255

struct idt_entry
{
	unsigned short	offset_low;
	unsigned short	segment_selector;
	unsigned char	reserved;
	unsigned char	flags;
	unsigned short	offset_high;
} __attribute__((packed));

struct cpu_state
{
	unsigned	edi;
	unsigned	esi;
	unsigned	ebp;
	unsigned	edx;
	unsigned	ecx;
	unsigned	ebx;
	unsigned	eax;
	unsigned	esp;
} __attribute__((packed));

struct stack_state
{
	unsigned	eip;
	unsigned	cs;
	unsigned	eflags;
	unsigned	user_esp;
	unsigned	user_ss;
} __attribute__((packed));

#endif /* _IDT_H */
