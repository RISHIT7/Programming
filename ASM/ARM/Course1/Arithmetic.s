.global _start
_start:
	mov r0, #5
	mov r1, #12
	add r2, r0, r2 @r2 = r0+r1
	sub r1, r2, r0 @r1 = r2-r0
	mul r0, r1, r2
	subs r1, r2, r0 @use when you don't know positiv or negative, less efficient, but now stores whether negative or positive
	@adding two numbers such that the number is too big for one register
	mov r0, #0xffffffff
	mov r1, #0x5
	adds r2, r0, r1
	@using the carry operation
	adc r2, r0, r1 // r2 = r0+r1+carry, same can be used with mul and sub