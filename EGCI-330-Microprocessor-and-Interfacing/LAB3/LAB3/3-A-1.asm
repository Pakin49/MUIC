;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code
start:
   LDI R20, 0x20;
   LDI R21, 0x31;
   LDI R22, 0X42
   LDI R23, 0x53;
   LDI R24,	0x64;
   ;STACK POINTER
   LDI R16, HIGH(RAMEND);
   OUT SPH,R16;
   LDI R17, LOW(RAMEND);
   OUT SPL, R17;

   PUSH R20;
   PUSH R21;
   PUSH R22;
   PUSH R23;
   PUSH R24;
END: 
   JMP END;