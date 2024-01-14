.global _start
_start:
	li t1, 10
	li t2, 8
	li x1, 1
	mul t3, t1, t2
	sub sp, sp, t3
	
	li t0, 0
	mv a0, sp

loop:
	li a7, 7
	ecall
	
	fsd fa0, 0(a0)
	
	addi t0, t0, 1
	addi a0, a0, 8
	bne t0, t1, loop

add:
	sub a0, a0, t2
	sub t0, t0, x1
	
	fld f1, 0(a0)
	fadd.d f2, f2, f1
	
	bne t0, x0, add

end:
	li a7, 3
	fsd f2, 0(sp)
	fld fa0, 0(sp)
	ecall
	
	li a7, 93
	li a0, 0
	ecall