.global _start
_start:
	mv s0, sp
	li t0, 26
	li t1, 1 # multiplier for conversion into decimal
	li t2, 10 # to store the value 10 for mul
	jal t3, atoi
	
	j end

atoi:
	li a7, 12
	ecall
	# now a0 has the character
	
	# now to handle "\n"
	beq t2, a0, construct_int
	
	addi a0, a0, -48
	sw a0, 0(s0)
	addi s0, s0, -4
	addi t0, t0, -1
	bnez t0, atoi
	
	li t0, 26

construct_int: # result stored in a1
	addi s0, s0, 4
	addi t0, t0, -1
	lw a0, 0(s0)
	mul a0, t1, a0
	mul t1, t1, t2
	add a1, a1, a0

	bnez t0, construct_int
	jr t3

end:
	li a7, 93
	li a0, 42
	ecall