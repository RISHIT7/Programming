/*
110101 -> 1+4+16+32 = 53
1 -> 110100 cmp -> less
10 -> 110111 cmp -> more
100 -> 110001 cmp -> less
1000 -> 111111 cmp -> more
10000 -> 101110 cmp -> less
less
 */


.global _start
_start:
    mov r1, #53
    mov r2, #1
    bl loop

loop:
    eor r3, r1, r2
    cmp r3, r1
    addlt r4, r4, #1
    lsl r2, #1
    cmp r2, r3
    blt loop

exit:
    mov r7, #1
    swi 0