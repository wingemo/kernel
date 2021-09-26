ENTRY(start)

SECTIONS
{
	. = 1M;

	.boot : { KEEP(*(.boot)) }

	.text : { *(.text) }

	.bss  : { *(.bss)  }

}
