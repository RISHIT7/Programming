.data
	num1: .quad
# 2022CS11621 Rishit Jakharia
.text
.global _start
_start:
	li s1, 8

	# Allocating the space in stack
	addi sp, sp, 36

top_level:
	#num1
	li a0, 0xffff000e
	li a1, 0xffff000e
	li a2, 0xffff000e
	li a3, 0xffff000e
	li a4, 0xffff000e
	li a5, 0xffff000e
	li a6, 0xffff000e
	li a7, 0xffff000e

	#num2
	li t0, 0xffff000e
	li t1, 0xffff000e
	li t2, 0xffff000e
	li t3, 0xffff000e
	li t4, 0xffff000e
	li t5, 0xffff000e
	li t6, 0xffff000e
	li s3, 0xffff000e
	
store:
	# store the 256 bit integer
	or a0, x0, a0
	sw a0, -28(sp)
	or a1, x0, a1
	sw a1, -24(sp)
	or a2, x0, a2
	sw a2, -20(sp)
	or a3, x0, a3
	sw a3, -16(sp)
	or a4, x0, a4
	sw a4, -12(sp)
	or a5, x0, a5
	sw a5, -8(sp)
	or a6, x0, a6
	sw a6, -4(sp)
	or a7, x0, a7
	sw a7, -0(sp)
	
	# Allocating space for second int
	addi sp, sp, 36
	or t0, x0, t0
	sw t0, -28(sp)
	or t1, x0, t1
	sw t1, -24(sp)
	or t2, x0, t2
	sw t2, -20(sp)
	or t3, x0, t3
	sw t3, -16(sp)
	or t4, x0, t4
	sw t4, -12(sp)
	or t5, x0, t5
	sw t5, -8(sp)
	or t6, x0, t6
	sw t6, -4(sp)
	or s3, x0, s3
	sw s3, -0(sp)
	
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
