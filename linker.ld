ENTRY(_start)

SECTIONS {
    . = 1M; /* Mulai kernel di alamat 1MB */
    .multiboot_header : {
        *(.multiboot_header)
    }
    .text : {
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
}
