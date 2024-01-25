.global _start
_start:
	li a7, 5
	ecall
sum:
	add a1, a1, a0 # a1 = a1 + a0
	addi a0, a0, -1 # a0 -= 1
	bnez a0, sum
	
end:
	mv a0, a1
	li a7, 1
	ecall

	li a7, 93
	li a0, 42
	ecall