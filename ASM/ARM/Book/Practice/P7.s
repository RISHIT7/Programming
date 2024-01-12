/*
void addNumbers(int a[100])
{
    int idx;
    int sum = 0;
    for (idx = 0; idx < 100; idx++)
    {
        sum = sum + a[idx];
    }
}
 */

.global _start
_start:
    mov r0, #0xfffff
    bl add_numbers

add_numbers:
    mov r1, #0 @ idx
    mov r2, #0 @ sum
    bl loop

loop:
    ldr r3, [r0, r2, lsl #2]
    add r2, r2, r3 @ sum = sum + a[idx]
    add r1, r1, #1 @ idx++
    cmp r1, #100
    bne loop

    b exit

exit:
    mov r7, #1
    swi 0