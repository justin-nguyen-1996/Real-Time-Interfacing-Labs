; Print.s
; Student names: change this to your names or look very silly
; Last modification date: change this to the last modification date or look very silly
; Runs on LM4F120 or TM4C123
; EE319K lab 7 device driver for any LCD
;
; As part of Lab 7, students need to implement these LCD_OutDec and LCD_OutFix
; This driver assumes two low-level LCD functions
; ST7735_OutChar   outputs a single 8-bit ASCII character
; ST7735_OutString outputs a null-terminated string 

    IMPORT   ST7735_OutChar
    IMPORT   ST7735_OutString
    EXPORT   LCD_OutDec
    EXPORT   LCD_OutFix

    AREA    |.text|, CODE, READONLY, ALIGN=2
    THUMB

  

;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number
; Output: none
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutDec
;---binding
V0		EQU		0
V1		EQU		4
V2		EQU		8
V3		EQU		12
V4		EQU		16
V5		EQU		20
V6		EQU		24
V7		EQU		28
V8		EQU		32
V9		EQU		36
;---ALLOCATION
	PUSH {R4-R12,LR}
	SUB SP, #40
;---ACCESS	
	MOV R2, #0xA  ;Modulo
	MOV R3, #0 ;place value
	MOV R4, #0 ;Accumulation
	MOV R5, #0x1  ;Previous Modulo
	MOV R10, #0xA ;Constant place value mover
Modulo
	UDIV	R1, R0, R2        ;Divide, result in R1
	MLS 	R1, R1, R2, R0	  ;Find remainder, result in R1
	SUB 	R1, R4			  ;Subtract out Accumulation
	ADD 	R4, R1 			  ;Add to Accumulation
	UDIV 	R1, R1, R5		  ;Correct place value
	ADD 	R1, #0x30		  ;Make it ASCII
	STR		R1, [SP, R3]	  ;Store in SP + Placevalue (V[placevalue])
	ADD 	R3, #0x4		  ;Increment Placevalue
	MOV 	R5, R2			  ;Set previous Modulo
	MUL 	R2, R2, R10		  ;Multiply Modulo by 10
	CMP 	R3, #40		  ;Repeat
	BNE		Modulo

			MOV R5, #0   ;Sig fig
			MOV R3, #0xA	 ;place value comparator
OnlySig
		MOV     R1, #4
		MUL 	R1, R1, R5		  ;COUNTER
		CMP   R5, #9
		BEQ   Output
		CMP	  R0, R3
		BLO   Output
		
		ADD  R5, #1
		MUL	 R3, R3, R10
		B    OnlySig		

	
Output 

	
	LDR 	R0, [SP, R1]
	PUSH 	{R1, LR}
	BL 		ST7735_OutChar
	POP     {R1, LR}
	SUB 	R1, #4
	CMP		R1, #0x0
	BGE		Output
		
;---Deallocation
	ADD	 SP, #40
	POP {R4-R12,LR}	
      BX  LR
;* * * * * * * * End of LCD_OutDec * * * * * * * *

; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.001, range 0.000 to 9.999
; Inputs:  R0 is an unsigned 32-bit number
; Outputs: none
; E.g., R0=0,    then output "0.000 "
;       R0=3,    then output "0.003 "
;       R0=89,   then output "0.089 "
;       R0=123,  then output "0.123 "
;       R0=9999, then output "9.999 "
;       R0>9999, then output "*.*** "
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutFix
;---Binding done above
;---ALLOCATION
	PUSH {R4-R12,LR}
	SUB SP, #16	
;---ACCESS	
	MOV R2, #0xA  ;Modulo
	MOV R3, #0 ;place value
	MOV R4, #0 ;Accumulation
	MOV R5, #0x1  ;Previous Modulo
	MOV R10, #0xA ;Constant place value mover
	
	LDR R6, =0x270F
	CMP R0, R6
	BHI Error
Modulo2
	UDIV	R1, R0, R2        ;Divide, result in R1
	MLS 	R1, R1, R2, R0	  ;Find remainder, result in R1
	SUB 	R1, R4			  ;Subtract out Accumulation
	ADD 	R4, R1 			  ;Add to Accumulation
	UDIV 	R1, R1, R5		  ;Correct place value
	ADD 	R1, #0x30		  ;Make it ASCII
	STR		R1, [SP, R3]	  ;Store in SP + Placevalue (V[placevalue])
	ADD 	R3, #0x4		  ;Increment Placevalue
	MOV 	R5, R2			  ;Set previous Modulo
	MUL 	R2, R2, R10		  ;Multiply Modulo by 10
	CMP 	R3, #0x10		  ;Repeat
	BNE		Modulo2
	
Write	LDR R0, [SP, #V3]
		BL ST7735_OutChar
		MOV  R0, #0x2E
		BL ST7735_OutChar
		LDR  R0, [SP, #V2]
		BL ST7735_OutChar
		LDR R0, [SP, #V1]
		BL ST7735_OutChar
		LDR R0, [SP, #V0]
		BL ST7735_OutChar
		B Deallocate
		
Error   
		MOV R1, #0x2A
		STR R1, [SP, #V0]
		STR R1, [SP, #V1]
		STR R1, [SP, #V2]
		STR R1, [SP, #V3]
		B 	Write

;---Deallocation
Deallocate	ADD	 SP, #16
			POP {R4-R12,LR}	
		
      BX  LR
 
     ALIGN
;* * * * * * * * End of LCD_OutFix * * * * * * * *

     ALIGN                           ; make sure the end of this section is aligned
     END                             ; end of file
