.global _start
_start:
	mov r0, #2
	mov r1, #4
	cmp r0, r1
	
	@ add less than
	addlt r2, r2, #1
	
	@ move gerater than or equal to
	movge r2, #5 // read more on the documentation

    @ exit code
    mov r7, #0x01
    swi 0