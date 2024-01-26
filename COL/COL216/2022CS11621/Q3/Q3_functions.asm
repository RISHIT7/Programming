# 2022CS11621, Rishit Jakharia
.global _start
_start:
	mv s0, sp
	li t1, 1 # multiplier for conversion into decimal
	li t2, 10 # to store the value 10 for mul
	j read_op

read_op:
	li a7, 12
	ecall
	sw a0, 0(gp) # stored the op at gp

handle_rest: # for the next three chars, that are "yz "
	li a7, 12
	ecall
	li a7, 12
	ecall
	li a7, 12
	ecall
	
	li t4, 32 # for managing " "
	jal t3, atoi

atoi:
	li a7, 12
	ecall
	# now a0 has the character
	
	# now to handle "\n" and " "
	beq t2, a0, construct_int_n
	beq t4, a0, construct_int_s
	
	addi a0, a0, -48
	sw a0, 0(s0)
	addi s0, s0, -4
	addi s10, s10, 1
	b atoi

construct_int_n:
	li s11, 1
	j construct_int

construct_int_s:
	li s11, 0
	j construct_int

construct_int: # result stored in a1
	addi s0, s0, 4
	addi s10, s10, -1
	lw a0, 0(s0)
	mul a0, t1, a0
	mul t1, t1, t2
	add a1, a1, a0

	bnez s10, construct_int
	beq s11, x0, handle_num2
	j end_parsing
	
handle_num2:
	addi s0, s0, -64
	addi s9, s0, -64
	sw a1, 0(s9)
	li a1, 0
	li t1, 1 # multiplier for conversion into decimal
	li t2, 10 # to store the value 10 for mul
	j atoi
	j end_parsing

end_parsing:
	# at this point, we have one int in a1, another stored at address s9, and opperation at gp
	lw a0, 0(s9)
	lw a2, 0(gp)
	
	# a 97
	li t0, 97
	beq a2, t0, add_op
	# s 115
	li t0, 115
	beq a2, t0, sub_op
	# m 109
	li t0, 109
	beq a2, t0, mul_op
	# d 100
	li t0, 100
	beq a2, t0, div_op

add_op:
	add a0, a0, a1
	j print_ans

sub_op:
	sub a0, a0, a1
	j print_ans

mul_op:
	mul a0, a0, a1
	j print_ans

div_op:
	div a0, a0, a1
	j print_ans

print_ans:
	li a7, 1
	ecall

	j end

end:
	li a7, 93
	li a0, 42
	ecall
