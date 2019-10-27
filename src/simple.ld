/* 
   Trivally simple linker script, causes pretty much everything to go
   into the on chip FLASH. In later chapters it gets more sophisticated.
*/
MEMORY {
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 112K
}

SECTIONS {
    .text :
    {
        KEEP(*(.reset_vectors))
        *(.text .text.*)
        *(.rodata .rodata.*)
        *(.glue_7)
        *(.glue_7t)
        *(.vfp11_veneer)
        . = ALIGN(4);
    } > FLASH
}
