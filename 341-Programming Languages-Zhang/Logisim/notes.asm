.ORIG X3000
; Forms of LD: LDI, LDS
; If we put a number in x4000, and we start at x3000,
; we need to use a different form of LD. Problem:

	LD R1, A
	
	HALT

A	.FILL X0e74

	.END

; we put x0e74 in x4000, so what do?

	LDI R1, A

	HALT

A	FILL X4000
	.END

; This loads the cell x4000 using LDI, which we set to x0e74, into register 1.


;STI is similar. we don't really use it. honestly we dont use LDI either.

; we DO use LDR and STR
; we can use one variable to store multiple values with this
; In this example, we add 5 to each number

	LEA R1, A ; R1 has address of A as Base

	; LEA means Load Effective Address, so load where A is right now, and to change inputs we can access A + an offset
	
	LDR R0, R1, #0; Base (R1) + Offset (#0), value at A[0] is loaded to R0
	ADD R0, R0, #5;  ADD FIVE
	STR R0, R1, #0; A[0] = A[0]+5

	; Repeat exact same steps, three more times, except increase our offset by 1 each time, IE go to the next value of A
	; cant do this with LDI



A	.FILL 2
	.FILL 3
	.FILL 5
	.FILL 7

	.END


; Now to do this better, we use a loop
; Two types, for loop if we know the size of the array, or while loop if we dont.
; since were doing the same thing as before but we cant easily increment the offset,
; we have a fixed offset but an incremental base.
; Update base by 1, keep offset as 0.
; in this case, the first number (4) is the array size and the actual data starts on the next line (2, 3, 5, 7)

	LEA R1, A
	ADD R1, R1, #1 ; R1 HAS OUR COUNTER, GO TO NEXT DATA AND START WORKING WITH IT

	LD R2, A ; R2 IS OUR COUNTER, IN THIS CASE LOADS WITH 4

AAA	LDR R0, R1, #0
	ADD R0, R0, #5
	STR R0, R1, #0

	ADD R2, R2, #-1 ; DECREASE COUNTER, STOPS WHEN COUNTER = 0
	BRz BBB ;  IF COUNTER IS 0, BREAK, ELSE:

	ADD R1, R1, #1 ; INCREASE INDEX BY 1, IE GO TO NEXT NUMBER
	BR AAA ; IF WE GET HERE, GO BACK TO START OF LOOP

BBB 	HALT

A	.FILL 4
	.FILL 2
	.FILL 3
	.FILL 5
	.FILL 7
	
	.END

; CASE NUMBER 2: Instead of previous way, we use a flag (-1, or some special value) at the end of the data.
; More flexible and more popular
; Update base by 1, keep offset as 0
; similar to do/while loop
; This is an example of a while loop, we check if its -1 before we STR to update the data

	LEA R1, A ; LOAD A AS BASE

AAA 	LDR R0, R1, #0 ; LOAD R1 INTO R0, IE LOAD 2
	ADD R2, R0, #5 ; ADD FIVE

	ADD R0, R0, #1 ; ADD 1 TO R0 TO SEE IF ITS NEGATIVE, -1 + 1 = 0
	BRz BBB ; IF IT IS -1, BREAK AND STOP

	STR R2, R1, #0 ; NOW A[R1+0] = A[R1+0] + 5

	ADD R1, R1, #1 ;  R1++, OR INDEX INCREASE BY ONE, OR GO TO NEXT NUMBER
	BR AAA

BBB 	HALT

A	.FILL 2
	.FILL 3
	.FILL 5
	.FILL 7
	.FILL -1 ; FLAG TO STOP

	.END

	
	; COUNT HOW MANY NUMBERS IN AN ARRAY, STORE IN R7
	; IF SIZE IS KNOWN, EZ, OTHERWISE..

	AND R7, R7, #0 ; R7 RESET TO 0
	LEA R1, A ;  R1 HAS A
	
AAA	LDR R0, R1, #0 ; BASE + OFFSET, R0 = R1 + 0
	
	ADD R0, R0, #1 ; ADD 1 TO R0, TEST CASE TO SEE IF WE ARE AT FLAG
	BRz BBB  ; VALUE IS -1, STOP

	ADD R7, R7, #1 ;  INCREASE COUNTER

	ADD R1, R1, #1 ;  GO TO NEXT SPOT
	BR AAA

BBB 	HALT
	.END

A	.FILL 2
	.FILL 3
	.FILL 5
	.FILL 7
	.FILL -1

; SAME EXERCISE, EXCEPT WHAT IF THE DATA IS FAR AWAY?...

	AND R7, R7, #0 ; SAME AS BEFORE
	LD R1, A ; R1 HAS VALUE OF A INSTEAD OF ADDRESS WITH LEA, BUT WHEN WE FILL A WE USE ADDRESS ANYWAY

	; EVERYTHING ELSE IS THE EXACT SAME, EXCEPT WE USE LD ABOVE, AND AT THE END WE USE

BBB	HALT

A	.FILL x4000 ; A IS LOADED WITH THE ADDRESS OF x4000, IN PROGRAM MUST INSERT AND MANUALLY DEFINE DATA, OR DO IT PROGRAMMATICALLY....
	.END

; TO ADD NUMBERS PROGRAMATICALLY, MAKE A NEW FILE WHERE EACH LINE IS A 4 DIGIT HEX NUMBER EXCEPT THE FIRST, WHICH IS THE ADDRESS:

4000 ; START INDEX
0002
0003
0005
0007
FFFF ; -1, FLAG

; THEN, INSTEAD OF SAVING IT AS AN ASSEMBLY FILE, SAVE IT AS WHATEVER.HEX, THEN COMPILE IT AS HEX
; AFTER THAT, YOU CAN LOAD THE PROGRAM AND THEN LOAD THE HEX FILE, AND IT'LL LOAD IN CORRECTLY


; LAST, COUNT HOW MANY TIMES A NUMBER IS IN AN ARRAY

	AND R5, R5, #0 ; R5 IS 0, FOR ANSWER
	LD R4, VAL
	NOT R4, R4
	ADD R4, R4 #1 ; R4 <- -VAL
	LEA R1, DATA ; R1 <- BASE OF DATA

AAA	LDR R0, R1, #0 <- LOAD R0 WITH R0 + 0
	ADD R2, R0, #1 <- IF -1, THEN STOP
	BRz DDD

	ADD R1, R1, #1 ; NEXT INDEX

	ADD R2, R0, R4 
	BRz BBB
	BR CCC

BBB	ADD R5, R5, #1
CCC	BR AAA

DDD	ST R5, ANS
	HALT

VAL	.FILL 3
ANS	.FILL 0
DATA	.FILL 2
	.FILL 3
	.FILL 1
	.FILL 3
	.FILL 2
	.FILL 3
	.FILL 3
	.FILL -1

	.END