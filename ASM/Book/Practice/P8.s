/*
int pow(int x, int n){
    int i = 0;
    int ans = 1;
    while (i < n)
    {
        ans *= x;
        i++;
    }
    return ans;
}

int main() {
    int x = 5;
    int n = 3;
    int c = pow(5, 3);

    return 0;
}
 */

.global _start
_start:
    mov r0, #5 @ x
    mov r1, #3 @ n

    push {r0, r1}
    bl pow
	pop {r0, r1}

    mov r2, r0
    b end

pow:
    mov r2, #0 @ idx
    mov r3, #1 @ ans
	push {lr}
	bl loop
	pop {lr}
	bx lr
    

loop:
    mul r3, r3, r0 @ ans *= x
    add r2, r2, #1 @ idx++
    cmp r2, r1
	blt loop

    bx lr

end:
    mov r7, #1
    swi 0