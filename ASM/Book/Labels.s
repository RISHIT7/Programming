.global _start
_start:
    lable1: mov r1, #3
    /*
     r1, r2 stores the memory address of the data,
     [r1] fetches the value stored at the memory address
     [r1+4] is similar to *(ptr+4)
     [r1]+4 is *ptr + 4
     */

    @ exit code
    mov r7, #1
    swi 0
