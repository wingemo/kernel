global start
extern kernel_start

section .bss
     resb 8192                        
     stack:

 section .text
 org  0x7c00 
 bits 32s
 start:
    cli
    mov  esp, stack  
    call kernel_start
    hlt                     
