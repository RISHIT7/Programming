.text
.global _start
_start:
	# 's0', s1, s2, s3. s4  's6' s7, s8, s9, s10
	li s1, 1237
	li s2, 1235
	li s3, 12357
	li s4, 126
	
    li s7, 1235
	li s8, 125
	li s9, 12
	li s10, 1523

int_manipulation:
    li t0, 4
    