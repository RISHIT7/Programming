#2022CS11621, Rishit Jakharia
.global _start
_start:
	li a7, 5
	ecall
	
	li t0, 0
	# store the arguments of the function in a0

sum:
	# creating space in the stack for this variable
	addi sp, sp, -8
	
	# if n == 0: return a1;
	sw a1, 0(sp)
	beqz a0, print_int
	
	# return sum(n-1, acc + n)
	sw a0, 0(sp)
	add a1, a1, a0
	sw a1, 4(sp)
	addi a0, a0, -1
	addi t0, t0, 1
	j sum
	
print_int:
	lw a0, 0(sp)
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
