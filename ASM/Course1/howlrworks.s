/*
only an intro, not a completely correct file
 */

.global _start
_start:
	
	mov r0, #1
	mov r3, #3
	
	@ bal add2
	
	@ but what if we want to do something here, we need a way to come back to this line
	@ we can add in a return address
	@ so we use BL ->. branch link
	bl add2
	mov r3, #4
	
	mov r7, #0x01
	swi 0
	
add2:
	add r2, r0, r1
	
	@ bx -> branch back to link register lr
	bx lr