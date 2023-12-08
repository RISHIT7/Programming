.data
message:
	.asciz "hello world!\n"
len = .-message

.text
.global _start
_start:
	@ standard output is #1
	@ standard in is #0
	@ standard error is #2
	MOV r0, #1
	LDR r1, =message
	LDR r2, =len

	MOV r7, #4
	SVC 0
	@ this is calling a write function of ARM and this checks for the input  to make the output


	@ exit code
	MOV r7, #1
	SWI 0