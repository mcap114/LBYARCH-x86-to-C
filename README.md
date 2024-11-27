# LBYARCH MP 2

## DAXPY Kernel Implementation in C and x86-64 Assembly

MCO2 Group 3 (S17)
<h4>BRILLANTES, Althea Kaitlin<h4>
<h4>CARPAROS, Miguel Antonio<h4>
    
## Project Specifications

Write the kernel in:
(1) C program
(2) x86-64 assembly language 
The kernel performs the following operation:

Z[i] = A * X[i] + Y[I]

Input: 
- Scalar vaiable n (integer); contains length of vector
- Scalar variable A (double-precision float)
- Vectors X, Y, Z (double-presion float)

* Functional scalar SIMD registers and floating-point instructions are used.

Output: store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

Note: 
1.) Write a C main program to call the kernels of the C version and x86-64 assembly language.
2.) Time the kernel portion only. Both for debug mode and release mode

## Debug Mode

### (i) Comparative Execution(Avg) and Analysis (C and x86-64)
**vector size (n)**    **C**    **x86-64**    
2<sup>20</sup>
2<sup>24</sup>
2<sup>25</sup>
2<sup>26</sup>
2<sup>27</sup>
2<sup>28</sup>
2<sup>29</sup>
2<sup>30</sup>

**Analysis:**

## Release Mode

**vector size (n)**    **C**    **x86-64**    
2<sup>20</sup>
2<sup>24</sup>
2<sup>25</sup>
2<sup>26</sup>
2<sup>27</sup>
2<sup>28</sup>
2<sup>29</sup>
2<sup>30</sup>


## Program Output with Correctness Check (C)
[Place Screenhot]

## Program Output with Correctness Check (x86-64)
[Place Screenhot]
