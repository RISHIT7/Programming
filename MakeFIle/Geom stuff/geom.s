	.file	"geom.c"
	.text
	.section	.rodata
.LC0:
	.string	"%s"
.LC1:
	.string	"%lf"
.LC2:
	.string	"The input must atleast be %lf"
.LC3:
	.string	"The input must atmost be %lf"
	.text
	.globl	get_double
	.type	get_double, @function
get_double:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movsd	%xmm0, -32(%rbp)
	movsd	%xmm1, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
.L6:
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movsd	-16(%rbp), %xmm1
	movsd	-32(%rbp), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L2
	movq	-32(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
.L2:
	movsd	-16(%rbp), %xmm0
	comisd	-40(%rbp), %xmm0
	jbe	.L4
	movq	-40(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
.L4:
	movsd	-16(%rbp), %xmm1
	movsd	-32(%rbp), %xmm0
	comisd	%xmm1, %xmm0
	ja	.L6
	movsd	-16(%rbp), %xmm0
	comisd	-40(%rbp), %xmm0
	ja	.L6
	movsd	-16(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	get_double, .-get_double
	.section	.rodata
.LC6:
	.string	"Enter the x value: "
.LC7:
	.string	"Enter the y value: "
.LC9:
	.string	"Distance is %lf meters\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movsd	.LC4(%rip), %xmm0
	movq	.LC5(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	get_double
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	.LC4(%rip), %xmm0
	movq	.LC5(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	get_double
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	.LC8(%rip), %xmm0
	movq	-24(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movsd	%xmm0, -56(%rbp)
	movsd	.LC8(%rip), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movapd	%xmm0, %xmm2
	addsd	-56(%rbp), %xmm2
	movq	%xmm2, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC4:
	.long	0
	.long	1079574528
	.align 8
.LC5:
	.long	0
	.long	-1067909120
	.align 8
.LC8:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
