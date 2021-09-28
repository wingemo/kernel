global start
extern kernel_start

section .bss
     resb 8192                        
     stack:

 section .text
 bits 32s
 start:
    cli                     
    mov esp, stack  
    call kernel_start
    hlt                     
