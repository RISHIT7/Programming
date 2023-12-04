.global _start
_start:
	@ shifts may be used as multiplication and division by 2
	@ 00001010 LSL = 00010100; 00001010 LSR = 00000101
	mov r0, #10
	mov r1, #1
	lsl r0, r1 // similar to r0 << r1
	lsr r0, r1 // similar to r0 >> r1
	
	@ using move and a shift at the same time
	mov r2, r0, lsl r1
	
	@ Rotations 00000101 -> 10000010
	@ ROR exists, ROL dosen't
	ror r2, r1