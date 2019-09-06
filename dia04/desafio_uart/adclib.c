/*
 * File:   adclib.c
 * Author: root
 *
 * Created on September 9, 2018, 11:41 PM
 */


#include "adclib.h"

void adcConfig(unsigned char conversionRate, unsigned char acqTime,unsigned char portConfig){
    //Configuring Conversion Rate
    ADCON2&=0b11111000; //clear conversion bits
    ADCON2|=conversionRate;
    //Configuring Acq time:
    ADCON2&=0b11000111; //clear bits
    ADCON2|=acqTime;
    
    //Port Configuration 
    ADCON1&=0b11110000;
    ADCON1|=portConfig;
    VCFG1=0;
    VCFG0=0;
    //ADON=1; //Turn on ADC Module
    
}
unsigned int adcRead(unsigned char channel,unsigned char resultFormat){
    unsigned int returnValue=0;
    if(channel>7) // Tratamento para canais invalidos
    {
        return 0;
    }
    ADCON0&=0b11000011; // Limpando bits de selecao do canal
    ADCON0|=(channel<<2); // Setando bits de selecao do canal a partir da variavel
    ADCON2&=0b01111111;
    ADCON2|=(resultFormat); //Right or Left Justified
    ADON=1;
    _delay(80);
    //_delay(40);
    GO_nDONE=1; // Initializes ADC conversion
    while(GO_nDONE) // Wait for A/D conversion to complete
    {};
    if(resultFormat==RIGHT_JUST)
        returnValue= (ADRESH<<8)|ADRESL;
    else if(resultFormat==LEFT_JUST)
        returnValue=(ADRESH<<2)|(ADRESL>>6);
    return returnValue;
        
}
