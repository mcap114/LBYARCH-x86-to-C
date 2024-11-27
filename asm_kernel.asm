section .text
bits 64
default rel
global daxpy_asm

daxpy_asm:
    ; initialize index to 0
    xor rbx, rbx            

L1:
    ; compare index with n value in rcx
    cmp rbx, rcx            
    jae L2          

    ; load X[i] into xmm7 and Y[i] into xmm8
    movsd xmm7, [rdx + rbx*8]  
    movsd xmm8, [r8 + rbx*8]   

    ; multiply A (xmm0) by X[i] (xmm7) and store in xmm7
    mulsd xmm7, xmm0

    ; add Y[i] to the result (xmm8)
    addsd xmm7, xmm8

    ; store the result into Z[i]
    movsd [r9 + rbx*8], xmm7

    ; increment index i, repeat loop
    inc rbx                 
    jmp L1                 

L2:
    ret                     
