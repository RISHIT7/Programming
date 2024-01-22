.data
	name: .asciz "R"
    	  .asciz "i",
          .asciz "s",
          .asciz "h",
          .asciz "i",
          .asciz "t",
          .asciz " ",
          .asciz "J",
          .asciz "a",
          .asciz "k",
          .asciz "h",
          .asciz "a",
          .asciz "r",
          .asciz "i",
          .asciz "a"
       null_string: .asciz "\n"
# 2022CS11621 Rishit Jakharia
.text
.global _start
_start:
	li t1, 10
	li t2, 8
	li x1, 1
	mul t3, t1, t2
	sub sp, sp, t3
	
	li t0, 0
	mv s0, sp
	mv a0, sp

loop:
	li a7, 8 
	li a1, 2
	ecall
	
	addi t0, t0, 1
	addi a0, a0, 8
	bne t0, t1, loop

print:
	li t0, 0
	mv sp, s0
	mv s1, sp
	
	li a7, 4
	la a0, null_string
	ecall

print_loop:
	li a7, 4
	la a2, name
	
	slli t0, t0, 1
	add a0, a2, t0
	ecall
	srli t0, t0, 1
	
	mv a0, s1
	ecall
	
	addi t0, t0, 1
	addi s1, s1, 8
	bne t0, t1, print_loop

end:	
	li a7, 93
	li a0, 0
	ecall