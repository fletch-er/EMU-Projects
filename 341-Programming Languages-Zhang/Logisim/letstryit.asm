	.ORIG x3000

	LD R1, INPUT
	
	AND R2, R2, #0		; R2 is the F(n-1), reset it to 0
	AND R3, R3, #0		; R3 is F(n-2), reset it to 0 for safety,
	ADD R3, R3, #1		; but start at 1 for the formula
	AND R4, R4, #0		; R4 is the running answer, start at 0
	AND R5, R5, #0
	ADD R5, R5, #1		; R5 = counter

	; Special case if n = 1 or n = 0
	ADD R7, R1, #-1
	BRz IN_1
	BRn END

LOOP_START

	NOT R6, R1		
	ADD R6, R6, #1		; R6 is two's complement of original input
	ADD R6, R6, R5		; if the counter + R6 is 0, we've found F(input)
	BRz ANS_FOUND		
				
	ADD R4, R2, R3 		; next fibonacci number = last two added together
	ADD R5, R5, #1		; counter++
	ADD R2, R3, #0		; move R2 to R3 
	ADD R3, R4, #0		; move R3 to R4
	BR LOOP_START

IN_1	STI R3, ANS
	BR END

ANS_FOUND
	STI R4, ANS

END	HALT

INPUT	.FILL 7 ; F(7) = 13
ANS 	.FILL x3018

.END