/*
 * File:   timer0lib.c
 * Author: root
 *
 * Created on September 8, 2018, 2:06 PM
 */


#include <xc.h>
#include "timer0lib.h"


void configTimer0(unsigned char prescalerValue){
    
    //Option_Reg register configuration
    T0CS=0;     //Clock Source = Internal instruction cycle
    PSA = 0;    //Prescaler assigned to the timer0 Module
    T0CON=T0CON&0b11111000; //Zerando configuracoes de prescaler
    T0CON=(T0CON|prescalerValue);
    TMR0ON=1;
    

}
void setTimer0Value(unsigned char value){
    TMR0=value;
    
}
unsigned char getTimer0Value(void){
    return (TMR0);
}
void resetTimer0(void){
    TMR0=0x00;
}
void enableTimer0ISR(void){
        //IntCON register configuration
    T0IE=1;
    TMR0IF=0;
}