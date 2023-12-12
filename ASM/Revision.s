.global _start
_start:
    bl swap


swap:
    @ r0 has the address of v[0]
    @ r1 has the value of k

    ldr r2, [r0, r1, lsl #2] @ temp (r2) = v[k]
    add r3, r1, #1 @ r3 is k+1
    ldr r4, [r0, r3, lsl #2]
    str r4, [r0, r1, lsl #2] @ v[k] = v[k+1]
    str r2, [r0, r3, lsl #2]

    mov r7, #1
    swi 0
