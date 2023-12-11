/*
int add_num(int a, int b)
{
    return a + b;
}

int main(){
    int a = 5;
    int b = 6;
    int c = add(5, 6);
}
 */

.global _start
_start:
    mov r0, #5 // arg1 (always)
    mov r1, #6 // arg2 (always), r0-r3 are the arguments, further arguments are pushed to stack
    
    @ to preserve values 
    push {r0,r1}
    bl add_num

    mov r2, r0
    pop {r0, r1}

    b end

add_num:
    mov r0, r0, r1 // return is always r0
    bx lr

end:
    mov r7, #1
    swi 0