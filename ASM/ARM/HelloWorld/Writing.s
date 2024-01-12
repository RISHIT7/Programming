.data
message:
    .asciz "hello world\n"
len = .-message 

.text            
.global _start
_start:
    mov r0, #1
    ldr r1, =message
    ldr r2, =len
    mov r7, #4
    svc 0  @ sys_write

    mov r7, #1
    swi 0  @ sys_exit