nasm -f win64 asm_kernel.asm
gcc -c main.c -o main.obj -m64
gcc -c c_kernel.c -o c_kernel.obj -m64
gcc main.obj c_kernel.obj asm_kernel.obj -o main.exe -m64
main.exe
pause