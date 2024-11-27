
section .text
bits 64
default rel

global daxpy_asm

   
    daxpy_asm:
        push rbp ;stack to frame
        mov rbp, rsp
        add rbp, 16
        
        mov r15, [rbp+32] ;store Z
       
        xor rbx, rbx
       
    L1:
        cmp rbx, rcx
        jae end_loop
        
        ;Calculates A*X[i]
        xorpd xmm7, xmm7
        
        movsd xmm7, [r8+rbx*8]
        mulsd xmm7, xmm1
        
        ;Calculate Y[i] + product
        xorpd xmm8, xmm8
        movsd xmm8, [r9+rbx*8]
        addsd xmm7, xmm8
        
       ;store Z[i]
        movsd [r15+rbx*8], xmm7
        
        inc rbx ;increment cnt
        jmp L1
        
    end_loop:
        pop rbp
        ret
