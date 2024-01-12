.global main
.text
main:
    mov r1, #31
    mov r2, #29
    mul r3, r1, r2
    sub r4, r3, #50

    mov r7, #1
    swi 0