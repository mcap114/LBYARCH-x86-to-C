# LBYARCH MP 2

## DAXPY Kernel Implementation in C and x86-64 Assembly

MCO2 Group 3 (S17)
<h4>BRILLANTES, Althea Kaitlin<h4>
<h4>CARPAROS, Miguel Antonio<h4>
    
## Project Specifications

Write the kernel in: <br>
(1) C program<br>
(2) x86-64 assembly language<br> 
The kernel performs the following operation:<br>

Z[i] = A * X[i] + Y[I]

**Input:**
- Scalar vaiable n (integer); contains length of vector
- Scalar variable A (double-precision float)
- Vectors X, Y, Z (double-presion float)

Functional scalar SIMD registers and floating-point instructions are used.

**Output:** store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

Note: <br>
1.) Write a C main program to call the kernels of the C version and x86-64 assembly language.<br>
2.) Time the kernel portion only. Both for debug mode and release mode

## Debug Mode

### (i) Comparative Execution (Avg) and Analysis (C and x86-64)
| **Vector Size (n)** | **C (Avg Execution Time)** | **x86-64 (Avg Execution Time)** |
|:-------------------:|:--------------------------:|:-------------------------------:|
| 2<sup>20</sup>      | 1.433 ms                   | 0.533 ms                  |
| 2<sup>24</sup>      | 24.167 ms                  | 18.533 ms                 |
| 2<sup>27</sup>      | 212.667 ms                 | 150.833 ms                  |
| 2<sup>28</sup>      | 449.133 ms                 | 287.567 ms                  |
| 2<sup>29</sup>      | 890.167 ms                 | 3510.733 ms                  |
| 2<sup>30</sup>      | DID NOT EXECUTE             | ( )                  |

**Analysis:**

## Release Mode

| **Vector Size (n)** | **C (Avg Execution Time)** | **x86-64 (Avg Execution Time)** |
|:-------------------:|:--------------------------:|:-------------------------------:|
| 2<sup>20</sup>      | 1.433 ms                   | ( )                  |
| 2<sup>24</sup>      | 24.600 ms                  | ( )                  |
| 2<sup>27</sup>      | 209.100 ms                 | ( )                  |
| 2<sup>28</sup>      | 432.433 ms                 | ( )                  |
| 2<sup>29</sup>      | 977.233 ms                 | ( )                  |
| 2<sup>30</sup>      | DID NOT EXECUTE             | ( )                  |



## Program Output with Correctness Check (C and x86)
[Place Screenhot]


## Program Output with Correctness Check (x86-64)
[Place Screenhot]
