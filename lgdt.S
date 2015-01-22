global load_gdt
; load_gdt - loads the GDT
; stack - [esp + 4] the GDT descriptor
;	[esp] the return address
load_gdt:
	mov eax, [esp + 4]
	lgdt [eax]
	ret

