.data
 L0: .asciz "2022CS11621.\n"
 L1: .asciz "Rishit Jakharia.\n"


.text
.global _start
_start:
    la a1, L0
    addi a2, x0, 14
    li a7, 64
    li a0, 1
    ecall

    la a1, L1
    addi a2, x0, 18
    li a7, 64
    li a0, 1
    ecall

    li a7, 93
    li a0, 0
    ecall
