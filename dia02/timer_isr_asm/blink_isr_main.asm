; BLINK EXAMPLE: LED ON PIN RD3 CHANGE IT STATES AFTER SOME DELAY TIME
; GENERATED BY ISR
; FELLIPE LEANDRO - 08/07/2019
    
; TODO INSERT CONFIG CODE HERE USING CONFIG BITS GENERATOR
#include <p18f4550.inc>
#include "config_bits.inc"
    
UDATA
N_OV	    EQU	    0x3d
COUNT_OV    RES	    1 
RES_VECT    CODE    0x0000            ; processor reset vector
    GOTO    START                   ; go to beginning of program

; TODO ADD INTERRUPTS HERE IF USED
    
ISR_VECT    ORG	    0x08
GOTO	    ISR_ROUTINE

MAIN_PROG CODE                      ; let linker place main program

START
 banksel COUNT_OV 
 MOVLW	N_OV
 MOVWF	COUNT_OV
 ;Configure LED PINS
 BANKSEL    TRISD
 CLRF	    TRISD
 BCF	    TRISD,RD3 ; PINO COMO SAIDA
 BANKSEL    PORTD
 MOVLW	    0XFF
 MOvwf	    PORTD
 BSF	    PORTD,RD3 ; LED � ATIVO BAIXO
 ;CONFIGURAR TEMPORIZADOR
 BANKSEL    T0CON
 BCF	    T0CON,TMR0ON    ;STOP TIMER0
 BCF	    T0CON,T0CS	    ; CLOCK SOURCE: INTERNAL CYCLE
 BCF	    T0CON,PSA	    ; USE PRESCALER
 BSF	    T0CON,T0PS2	    ;PRESCALER: 1/32
 BSF	    T0CON,T0PS1
 BCF	    T0CON,T0PS0
 ;CONFIGURAR INTERRUPCOES
 BANKSEL    INTCON
 BSF	    INTCON,GIE
 BSF	    INTCON,TMR0IE
 BCF	    INTCON,TMR0IF   ;CLEAR OVERFLOW FLAG
 BSF	    T0CON,TMR0ON    ;TURN ON TIMER0
 LOOP
;while(true)
GOTO LOOP
 
ISR_ROUTINE
	BCF	INTCON,TMR0IF	;CLEAR FLAG
	BANKSEL COUNT_OV
	DECFSZ  COUNT_OV
	GOTO	RETURN_ISR
	banksel	LATD
	MOVLW	0X08    ; only bit 3 as '1'
	XORWF	LATD,f	    ;XOR REGISTER WITH W AND STORE IN REGISTER
	BANKSEL COUNT_OV
	MOVLW   N_OV
	MOVWF   COUNT_OV    ;FOR NEXT CYCLE
	RETURN_ISR
	    RETFIE
 
 END