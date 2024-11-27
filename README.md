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
| 2<sup>30</sup>      | DID NOT EXECUTE             | DID NOT EXECUTE                  |

This comparative execution table reveals the performance of the C and x86-64 (ASM) across the various vector sizes (2^20, 2^24, 2^27, 2^28, 2^29, 2^30).<br> 
**Analysis:**<br>
- 2<sup>20</sup> to 2<sup>24</sup> <br>
The x86-64 kernel significantly outperforms the C kernel for these vector sizes. This might be due to the x86-64 assembly's optimized use of SIMD instructions. The C kernel might be slower but executes efficiently as well.

- 2<sup>24</sup> to 2<sup>28</sup><br>
As the vector size increases, both kernels experience linear growth in their average execution time. However, the x86-64 kernel (2^24-2^28 = 18.533-287.567ms) still demonstrates to outperform the C kernel (2^24-2^28 = 24.167-449.133ms). Showing the efficiency of the ASM kernel accordingly.

- 2<sup>29</sup><br>
The ASM kernel's execution time surprisingly spikes dramatically for very large vector sizes like 2^29 with an average execution time of 3510.733 ms, becoming extremely slower than the C kernel with 890.167 ms. This might be due to the size exceeding the CPU's capacity making the SM kernel suffer from frequent memory access and register spilling. Furthermore, this substantial gap between their times underscores the ASM kernel's scalability and efficiency in handling large magnitude sizes.

- 2<sup>30</sup><br>
Both kernels failed to execute due to resource limitations. This could be attributed to memory allocation constraints or the system's inability to handle large vector sizes.


## Program Output with Correctness Check (C and x86)
**Vector Size 2<sup>20</sup>** <br>
<img width="700" src="https://github.com/mcap114/LBYARCH-x86-to-C/blob/main/images/20.png">

**Vector Size 2<sup>24</sup>** <br>
<img width="700" src="https://github.com/mcap114/LBYARCH-x86-to-C/blob/main/images/24.png">

**Vector Size 2<sup>27</sup>** <br>
<img width="700" src="https://github.com/mcap114/LBYARCH-x86-to-C/blob/main/images/27.png">

**Vector Size 2<sup>28</sup>** <br>
<img width="700" src="https://github.com/mcap114/LBYARCH-x86-to-C/blob/main/images/28.png">

**Vector Size 2<sup>29</sup>** <br>
<img width="700" src="https://github.com/mcap114/LBYARCH-x86-to-C/blob/main/images/29.png">


