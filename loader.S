global loader

ALI			equ	1 << 0
MEMINFO			equ	1 << 1
FLAGS			equ	ALI | MEMINFO
MAGIC			equ	0x1BADB002
CHECKSUM		equ	-(MAGIC + FLAGS)
KERNEL_STACK_SIZE	equ	4096

extern kmain

section .text:
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

loader:
	mov eax, 0xCAFEBABE
	call kmain
.loop:
	jmp .loop

section .bss:
align 4
kernel_stack:
	resb KERNEL_STACK_SIZE
	mov esp, kernel_stack + KERNEL_STACK_SIZE
