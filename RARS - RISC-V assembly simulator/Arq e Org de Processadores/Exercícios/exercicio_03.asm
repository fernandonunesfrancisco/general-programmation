	.text
main:
	addi s0, zero, 15
	addi s1, zero, 10
	addi s2, zero, 20
	addi s3, zero, 1
	addi s4, zero, 2
	
	beq s3, s4, L1
	add s0, s1, s2
	
	
L1:
	sub s0, s0, s3