/*
 * File:   mainApp.c
 * Author: root
 *
 * Created on 10 de Setembro de 2018, 14:21
 */

#include <xc.h>
#include "config_bits.h"
#define _XTAL_FREQ 8000000
#include "adclib.h"

void main(void) {
    TRISD=0x00; //all bits as output
    TRISA0=1; //input for the ADC
    TRISA3=1; //input for the ADC
    TRISC7=0;
    LATD=0x00;
    adcConfig(ADC_CLOCK_8,ADC_TAD_6,ADC_CONFIG_0);
    unsigned int valor;
    while(1){
        valor=adcRead(0,RIGHT_JUST);
        //escalonamento para 8 bits:
        LATD=~valor; //ativo baixo  
        LATC7=~LATC7;
        __delay_ms(200);
    }
    return;
}
