/*
int i;
int b[500]; -> r2
int a[500]; -> r1
for(i=0; i < 500; i++) {
    b[i] = a[a[i]];
}
 */

.global _start
_start:
    mov r0, #0 @ idx
    @ now the r1, register has the address of a[0], we need a[a[0]]
    @ the value a[0] is [r1], and the address of a[a[0]] if r1 + [r1], lsl #2
    @ thus the value a[a[0]] is [r1 + [r1], lsl #2]

    @ this value needs to be stored in the location stored in r2, that is [r2] <- value

    mov r3, #500

    bl loop
    b exit

loop:

    @ calculation
    ldr r4, [r1, r0, lsl#2] @ loading the value a[r0] in r4
    ldr r4, [r1, r4, lsl#2] @ loading the value a[a[r0]] in r4

    str r4, [r2, r0, lsl#2] @ storing the value in b[r0]

    @ loop condition

    add r0, r0, #1
    cmp r0, r3
    blt loop

    bx lr

exit:
    mov r7, #1
    swi 0
