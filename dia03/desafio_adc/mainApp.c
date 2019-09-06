/*
 * File:   mainApp.c
 * Author: root
 *
 * Created on July 11, 2019, 4:10 PM
 */


#include <xc.h>
#include"config_bits.h"
#include"timer0lib.h"
#include"adclib.h"
#include "configIO.h"
#include "sevenSeg.h"

#define THRESHOLD (unsigned int)127
#define _XTAL_FREQ 8000000
volatile unsigned char flag_alarm=0;
unsigned char timer_cont=0;
void interrupt _ISR(){
    if(T0IF){
        T0IF=0;
        if(flag_alarm==1){
            timer_cont++;
            flag_alarm=0;
            if(timer_cont==61){
                output_toggleC(PIN_C7);
                timer_cont=0;
            }
            
        }
    }
    
}

void main(void) {
    unsigned int valor;
    //COnfigurando pino do adc como entrada
    setInputA(PIN_A0);
    //COnfigurando LEDS Como saida:
    //LEDS DE ALERTA:
    setOutputC(PIN_C7);
    output_highC(PIN_C7);
    //LED de leitura:
    setOutputD(PIN_D0|PIN_D1|PIN_D2|PIN_D3|PIN_D4|PIN_D5|PIN_D6|PIN_D7);
    //output_highD(PIN_D0|PIN_D1|PIN_D2|PIN_D3|PIN_D4|PIN_D5|PIN_D6|PIN_D7);
    //Displays de 7 segmentos:
    configSevenSeg();
    //COndifurando Periférico ADC
    adcConfig(ADC_CLOCK_8,ADC_TAD_6,ADC_CONFIG_0);
    //Configurando TImer0
    configTimer0(PRESCALER64);
    enableTimer0ISR();
    resetTimer0();
    GIE=1;
    //PEIE=1;
   
    while(1){
        valor=adcRead(0,RIGHT_JUST);
        //valor=1023;
        //Exibir valor nos displays de 7 segmentos:
        if(valor<10){
            printDigit1((unsigned char)valor);
        }
        else if(valor>=10 && valor<100){
            printDigit1((unsigned char)(valor%10));
            __delay_ms(5);
            printDigit2((unsigned char)(valor/10));
        }
        else if(valor>=100 && valor <1000){
            printDigit1((unsigned char)((valor%100)%10));
            __delay_ms(5);
            printDigit2((unsigned char)((valor%100)/10));
            __delay_ms(5);
            printDigit3((unsigned char)((valor/100)));
        }
        else if(valor>=1000){
            printDigit1((unsigned char)(((valor%1000)%100)%10));
            __delay_ms(5);
            printDigit2((unsigned char)(((valor%1000)%100)/10));
            __delay_ms(5);
            printDigit3((unsigned char)(((valor%1000)/100)));
            __delay_ms(5);
            printDigit4((unsigned char)(valor/1000));
            
        }
        //LATD=~valor;
        //output_lowD(valor);
        if(valor>THRESHOLD){
            flag_alarm=1;
            
        }
        else{
            output_highC(PIN_C7);
            timer_cont=0;
        }
        
        //PORTB=valor&0xff;//oito primeiros bits
        //RC0=valor>>8; //nono bit para rc0
        //RC1=valor>>9; //décimo bit para rc1
        
    }
    return;
}