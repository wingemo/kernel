global start
extern kernel_entry 

section .bss
   resb 8192                        
   stack:

section .text
bits 32s
start:
   cli                     
   mov esp, stack    
   call kernel_entry
   hlt                     

