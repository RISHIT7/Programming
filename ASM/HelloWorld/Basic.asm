.global _start
.section .text

_start:
    mov r7, #0x1
    mov r0, #13

    swi 0

