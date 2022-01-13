	.ORIG X3000
	
;	r0 = input
;	r1 = -10



	LD R0, INPUT
	AND R1, R1, #0
	ADD R1, R1, #10
	NOT R1, R1
	ADD R1, R1, #1 ; R1 = -10

LOOP	ADD R0, R0, R1 ; R2 = R0 - R1
	BRz DIVIS ; remainder was 0, number is divisible
	BRp LOOP; remainder is positive, subtract again
	ADD R7, R7, #-11	
	BR END

DIVIS	ADD R7, R7, #11

END 	HALT




INPUT	.FILL 11
	.END
