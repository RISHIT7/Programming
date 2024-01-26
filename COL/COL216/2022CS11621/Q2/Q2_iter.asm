# 2022CS11621, Rishit Jakharia
.global _start
_start:
	li a7, 5
	ecall
sum:
	add a1, a1, a0 # a1 = a1 + a0
	addi a0, a0, -1 # a0 -= 1
	bnez a0, sum
	
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
