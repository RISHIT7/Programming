/*
 int val = get_input();
 int idx;
 int prod = 1;
 for (idx = 1; idx <= val; idx++) {
    prod = prod*idx;
 }
 */

.global _start
_start:
    mov r0, #4
    mov r1, #1 @ prod
    mov r2, #1 @ idx

loop:
    mul r1, r1, r2
    cmp r0, r2
    add r2, #1
    bne loop

end:
    mov r7, #1
    swi 0