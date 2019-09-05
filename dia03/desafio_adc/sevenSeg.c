/*
 * File:   sevenSeg.c
 * Author: Fellipe
 *
 * Created on July 15, 2019, 3:42 PM
 */


#include <xc.h>
#include "sevenSeg.h"
#include "configIO.h"

void printDigit1(unsigned char valor){
    output_highA(PIN_A5);
    output_lowA(PIN_A2);
    output_lowE(PIN_E0|PIN_E2);
    LATD=tabela[valor];
   
}
void printDigit2(unsigned char valor){
      output_lowA(PIN_A5);
      output_highA(PIN_A2);
      output_lowE(PIN_E0|PIN_E2);
      LATD=tabela[valor];
}
void printDigit3(unsigned char valor){
      output_lowA(PIN_A5|PIN_A2);
      output_highE(PIN_E0);
      output_lowE(PIN_E2);
      LATD=tabela[valor];
}
void printDigit4(unsigned char valor){
      output_lowA(PIN_A5|PIN_A2);
      output_lowE(PIN_E0);
      output_highE(PIN_E2);
      LATD=tabela[valor];
}
void configSevenSeg(void){
    setOutputA(PIN_A5|PIN_A2);
    setOutputE(PIN_E0|PIN_E2);
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
