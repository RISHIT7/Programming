
.global _start
_start:
	li a7, 5
	ecall
	
	li t0, 0
	# store the arguments of the function in a0

sum:
	# creating space in the stack for this variable
	addi sp, sp, -8
	
	# if n == 0: return 0;	
	li a1, 0
	beqz a0, end_func
	
	# return n * sum(n-1)
	sw a0, 0(sp)
	addi a0, a0, -1
	addi t0, t0, 1
	j sum

end_func:
	# pop things off the stack
	addi sp, sp, 8
	lw a0, 0(sp)
	
	add a1, a1, a0
	addi t0, t0, -1
	bnez t0, end_func
	
print_int:
	mv a0, a1
	li a7, 1
	ecall
	
print_time:
	li a0, 10
	li a7, 11
	ecall
	
	rdcycle a0
	li a7, 1
	ecall

end:
	li a7, 93
	li a0, 42
	ecall
