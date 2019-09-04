/*
 * File:   mainApp.c
 * Author: root
 *
 * Created on September 8, 2018, 2:47 PM
 */

// PIC16F4550 Configuration Bit Settings


// CONFIG
#include "config_bits.h"
#include <xc.h>
#include "timer0lib.h"
#define _XTAL_FREQ      8000000

unsigned char cont_time=0x00;

void interrupt ISR_(){
    if(T0IF){
        T0IF=0;
        cont_time++;
        if(cont_time==61){
            LATD3 = ~LATD3;
            cont_time=0x00;
        }
        
    }
}

void main(void) {
    IRCF2=1;
    IRCF1=1;
    IRCF0=0;
    SCS1=1;
    TRISD3=0;
    LATD=0;
    configTimer0(PRESCALER128);
    enableTimer0ISR();
    resetTimer0();
    GIE=1;
    PEIE=1;
    while(1);
    return;
}
