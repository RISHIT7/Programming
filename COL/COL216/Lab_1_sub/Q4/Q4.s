.global _start
_start:
	mv s0, sp # address of num1
	mv s1, sp # address of num2 
	li t0, 24
	sub s1, s1, t0 # create room of 6 registers

storing:
	li t0, 1234
	sw t0, 0(s0)
	addi s0, s0, 4
	sw t0, 0(s0)
	addi s0, s0, 4
	sw t0, 0(s0)
	addi s0, s0, 4
	sw t0, 0(s0)

	li t0, 5678
	sw t0, 0(s1)
	addi s1, s1, 4
	sw t0, 0(s1)
	addi s1, s1, 4
	sw t0, 0(s1)
	addi s1, s1, 4
	sw t0, 0(s1)

end:
	li a7, 93
	li a0, 0
	ecall