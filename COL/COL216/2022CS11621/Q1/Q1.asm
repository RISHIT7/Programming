# 2022CS11621, Rishit Jakharia 
.global _start
_start:
	li a2, 1
	li a7, 5
	ecall
	
	mv a1, a0 # keep the input 1 in a1 and a4, and input 2 in a0 and a3
	mv a4, a0
	
	jal s0, fact
	mv s1, a2 # storing the fact(a1) in s1
	
	# resetting the registers
	li a2, 1

	li a7, 5
	ecall
	mv a3, a0
	
	# handle 0 and n == r cases
	beqz a0, handle_case_1
	beq a4, a0, handle_case_1
	bgtu a3, a4, handle_case_2
	
	jal s0, fact
	mv s2, a2 # storing the fact(a0) in s2
	
	# setting up a0 for the subtraction part assuming input1 > input2 as nCr
	sub a0, a4, a3
	
	# resetting the registers
	li a2, 1
	
	jal s0, fact
	mv s3, a2 # stroing the subtraction in s3
	
	# at this point n! -> s1, r! -> s2, (n-r)! -> s3
	mul s4, s2, s3
	div s5, s1, s4
	# thus s1, has the answer

	mv a0, s5
	li a7, 1
	ecall

	j end

fact:
	mul a2, a2, a0
	addi a0, a0, -1
	bne a0, x0, fact
	jr s0

handle_case_1:
	li a0, 1
	li a7, 1
	ecall
	
	j end

handle_case_2:
	li a0, 0
	li a7, 1
	ecall
	
	j end

end:
	li a7, 93
	li a0, 42
	ecall
