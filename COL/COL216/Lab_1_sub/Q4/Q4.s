.data
	num1: .quad

.text
.global _start
_start:
	li s1, 8

	# Allocating the space in stack
	addi sp, sp, 36
	
	# store the 256 bit integer
	li a0, 0xffff000e
	sw a0, -28(sp)
	sw a0, -24(sp)
	sw a0, -20(sp)
	sw a0, -16(sp)
	sw a0, -12(sp)
	sw a0, -8(sp)
	sw a0, -4(sp)
	sw x0, -0(sp)
	
	# Allocating space for second int
	addi sp, sp, 36
	li a0, 0xffff000c
	sw a0, -28(sp)
	sw a0, -24(sp)
	sw a0, -20(sp)
	sw a0, -16(sp)
	sw a0, -12(sp)
	sw a0, -8(sp)
	sw a0, -4(sp)
	sw x0, -0(sp)
	
	mv s0, sp
	li t3, 0 # carry bit is set to 0 at the beginning
	j adder

adder: # 32 bit adder

	# deallocating the last bits of num1
	lw t1, 0(s0)
	
	# deallocating the last bits of num2
	addi s0, s0, -36
	lw t2, 0(s0)
	addi s0, s0, 36

	add t0, t1, t2
	add a1, t0, t3 # adding the carry bit
	jal a2, handle_inter_carry_helper
	mv t0, a1
	
	# result is stored in t0
	addi s0, s0, 36
	sw t0, 0(s0)
	addi s0, s0, -36
	
	li t3, 0 # refreshing the carry bit after addition
	jal a2, handle_carry_helper
	j end_addition

handle_inter_carry_helper:
	bgtu t0, a1, handle_inter_carry
	jr a2

handle_inter_carry:
	addi t3, t3, 1 # carry bit 
	jr a2

handle_carry_helper:
	bgtu t1, t0, handle_carry
	jr a2

handle_carry:
	addi t3, t3, 1 # carry bit
	jr a2

end_addition:
	addi s0, s0, -4
	addi s2, s2, 1
	bne s2, s1, adder
	
	bne t3, zero, final_carry
	j end

final_carry:
	sw t3, 36(s0)
	j end

end:
	li a7, 93
	li a0, 42
	ecall