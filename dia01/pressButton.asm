#INCLUDE <P18F4550.INC>
		config FOSC = HS 
		config  WDT = OFF            ;WDT disabled (control is placed on the SWDTEN bit)
		config PBADEN = OFF         ;PORTB<4:0> pins are configured as digital I/O on Reset
		config MCLRE = OFF          ;RE3 input pin enabled; MCLR pin disabled
		
 		

		ORG 0X00
		;bra START
		goto START
		
		
		org 0x20
		START		;
		;SETUP
		MOVLW  	0x0F
		IORWF	ADCON1,f
		BCF 		TRISD,TRISD0 ;CONFIGURANDO COMO SAIDA
		CLRF	TRISD
		;BSF		PORTD,RD0
		;CLRF	PORTD
		BSF		PORTD,RD0 ;desligar todos os leds
		BSF		PORTD,RD1
		BSF		PORTD,RD2
		BSF		PORTD,RD3
		BSF		PORTD,RD4
		BSF		PORTD,RD5
		BSF		PORTD,RD6
		BSF		PORTD,RD7
		;movlw 0xff
		;iorwf    portd,f
		;BCF		PORTB,RB0
		BSF		TRISB,RB1 ;CONFIGURANDO COMO ENTRADA
		;BSF		TRISA,TRISA0
		;LOOP
TEST	BTFSS	PORTB,RB1 ; se botao esta em nível baixo, liga led
		GOTO	ON
		BSF		PORTD,RD3
		GOTO  	TEST
ON		BCF		PORTD,RD3
		GOTO	TEST
		END
;Incluir imagem com o instruction set do pic
