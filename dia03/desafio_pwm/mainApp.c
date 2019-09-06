/*
 * File:   mainApp.c
 * Author: Fellipe Leandro
 *
 * Created on July 16, 2019, 4:48 PM
 */


#include <xc.h>
#define _XTAL_FREQ 8000000
#include"config_bits.h"
#include"adclib.h"
#include "configIO.h"
#include "sevenSeg.h"
#include "pwm.h"
#define TRESHOLD 75
void printDisplays(unsigned int valor);
void main(void) {
    unsigned int valor;
    //COnfigurando pino do adc como entrada
    setInputA(PIN_A0);
    //COnfigurando LEDS Como saida:
    //LEDS DE ALERTA:
    //setOutputC(PIN_C7);
    //output_highC(PIN_C7);
    //LED de leitura:
    setOutputD(PIN_D0|PIN_D1|PIN_D2|PIN_D3|PIN_D4|PIN_D5|PIN_D6|PIN_D7);
    //output_highD(PIN_D0|PIN_D1|PIN_D2|PIN_D3|PIN_D4|PIN_D5|PIN_D6|PIN_D7);
    //Displays de 7 segmentos:
    configSevenSeg();
    //COndifurando Periférico ADC
    adcConfig(ADC_CLOCK_8,ADC_TAD_6,ADC_CONFIG_0);
    //Configurando PWM:
    PWM_setup(500);	// Configura o PWM E Define a frequencia em Hz
    set_PWM1(50);      // Define o duty Cycl
    PWM1_start();   	// Inicia o PWM
    while(1){
        valor=adcRead(0,RIGHT_JUST);
        printDisplays(valor);
        set_PWM1(valor);
//        if(valor>TRESHOLD){
//          PWM2_stop();
//          set_PWM1(80);
//          PWM1_start();
//        }
//        
//        else if(valor<(TRESHOLD)-5){
//            PWM1_stop();
//            PWM2_start();
//            set_PWM2(30);
//        }
        __delay_ms(5);
        
            
            
        

        
    }
}
void printDisplays(unsigned int valor){
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
}
