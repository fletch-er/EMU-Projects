	.ORIG X3000
	
	LD R0, INPUT
	AND R1, R1, #0
	ADD R1, R1, #10
	NOT R1, R1
	ADD R1, R1, #1 ; R1 = -10

LOOP	ADD R2, R0, R1 ; R2 = R0 - R1
	BRp LOOP
	BRn NOND
	LD R7, 11	
	BR END

NOND	LD R7, -11

END 	HALT




INPUT	.FILL 10
	.END
