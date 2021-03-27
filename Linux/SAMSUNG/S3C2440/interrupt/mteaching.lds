SECTIONS {
    . = 0x00000000;
    .init : AT(0){ start.o init.o sdram.o nand.o}
    . = 0x30000000;
    .text : AT(4096) { *(.text) }
    .rodata ALIGN(4) : AT((LOADADDR(.text)+SIZEOF(.text)+3)&~(0x03)) {*(.rodata*)} 
    .data ALIGN(4)   : AT((LOADADDR(.rodata)+SIZEOF(.rodata)+3)&~(0x03)) { *(.data) }
    __bss_start = .;
    .bss ALIGN(4)  : { *(.bss)  *(COMMON) }
    __bss_end = .;
}
