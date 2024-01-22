# 2022CS11621 Rishit Jakharia

.global _start
_start:
	li a7, 5
	ecall
	
	li a1, 1
	li a2, 1
	beqz a0, print_zero
	beq a0, a1, print_one
	
	sub a0, a0, a1
	
	li t0, 0
	j fib

print_zero:
	li a7, 1
	mv a0, x0
	ecall
	
	j end
	
print_one:
	li a7, 1
	li a0, 1
	ecall
	
	j end

fib:
	add a3, a2, a1
	mv a1, a2
	mv a2, a3
	
	addi t0, t0, 1

	bne t0, a0, fib	

print:
	li a7, 1
	mv a0, a1
	ecall
	
end:
	li a7, 93
	li a0, 0
	ecall