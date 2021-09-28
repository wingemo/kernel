global start
extern kernel_start

section .bss
     resb 8192                        
     stack:

 section .text
 org  0
 bits 32s
    jmp 0x7c0:start
 start:
    cli ; Clear Interrupts
    mov ax, 0x7c00
    mov ds, ax
    mov es, ax
    mov ax, 0x00
    mov ss, ax
    mov sp, 0x7c00
    sti ; Enables Interrupts
    mov esp, stack  
    call kernel_start
    hlt                     
