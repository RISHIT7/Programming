.global _start
_start:
	mov r0, #0xff
	mov r1, #32
	and r2, r0, r1
	ands r2, r0, r1 @sets off flags, although not much used
	orr r2, r0, r1
	eor r2, r0, r1
	
	@one that is a little bit different
	@NEGATION
	@move negative = move + negation
	mvn r0, r0
	
	@might want to set the others to 0
	and r0, r0, #0x000000ff

	@exit code
	mov r7, #0x01
	swi 0