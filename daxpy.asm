section .text
bits 64
default rel
global daxpy

daxpy:
    mulsd xmm0, xmm1

    addsd xmm0, xmm2

    ret
