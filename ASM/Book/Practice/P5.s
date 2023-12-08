/*
int foo(){
    return 2;
}
void main()
{
    int x = 3;
    int y = x + foo();
}
 */

.global _start
_start:
    mov r0, #3
    bl foo
    add r2, r0, r1

    b exit

foo:
    mov r1, #2
    bx lr

exit:
    mov r7, #1
    swi 0