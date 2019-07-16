.name    "sebc Hello World"
.comment "sebc Hello World"


l3:	ldi	%:l2, r2, r4
	add	r2, r3, r2
	xor	r4, r4, r4
	zjmp	%:l3
l2:
