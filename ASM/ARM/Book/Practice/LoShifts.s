.global _start
_start:
    mov r0, #7
    lsl r1, r0
    lsr r2, r0
    asr r1, r0
    ror r2, r0

    mov r7, #1
    swi 0