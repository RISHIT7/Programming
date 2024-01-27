.global _start
_start:
	li a2, 45 # "-" sign

	mv s0, sp
	li t0, 26
	li t1, 1 # multiplier for conversion into decimal
	li t2, 10 # to store the value 10 for mul
	jal t3, atoi

atoi:
	li a7, 12
	ecall
	# now a0 has the character

	beq a0, a2, minus_sign
	j atoi_cont

minus_sign:
	li a2, 1
	li a7, 12
	ecall

atoi_cont:
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

manage_sign:
	li t1, 1
	beq a2,t1,negative
	j end

negative:
	li t1, -1
	mul a1, a1, t1

end:
	li a7, 93
	li a0, 42
	ecall