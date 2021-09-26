section .multiboot
_start:
	dd 0xE85250D6     ; magic number
	dd 0              ; protected mode code
	dd _start - _end  ; length
	dd 0x100000000 - (0xe85250d6 + 0 + (_start - _end))
	dw 0  ; type
	dw 0  ; flags
	dd 8  ; size
_end:
