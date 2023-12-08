@ checking for a perfect square

.global _start
_start:
	mov r0, #4
	
	mov r1, #0
	mov r2, #1
	
	bl loop
	
loop:
	mul r3, r2, r2
	cmp r3, r0
	beq square
	add r2, r2, #1
	cmp r2, r0
	bne loop
	
	b exit

square:
	mov r1, #1

exit:
	mov r7, #1
	swi #0