.global _start
_start:
	mov r2, #16
	lsr r1, r2, #2
	
	mov r7, #1
	swi 0
	