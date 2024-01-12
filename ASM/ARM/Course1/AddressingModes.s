.data
list:
	.word 4, 5, -9, 1, 0, 2, -3

.text
.global _start
_start:
	mov r0, #30 @immediate addressing
	mov r1, r0 @register direct addressing
	ldr r0, =list @the pointer to the first value, direct addressing
	ldr r1, [r0] @register indirect addressing
	ldr r2, [r0, #4] @register offset indirect addressing
	@pre increment and post increment
	ldr r2, [r0, #4]!
	ldr r2, [r0], #4
	mov r7, #0x1
	swi 0

