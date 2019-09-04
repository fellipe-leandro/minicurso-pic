/*
 * File:   configIO.c
 * Author: Alisson
 *
 * Created on 8 de Setembro de 2018, 14:59
 */


#include <xc.h>

#include "configIO.h"
//-----------------------------------------------------------------------------
//---------------------------SET OUTPUTS---------------------------------------
//-----------------------------------------------------------------------------
void setOutputA(unsigned char outputs){
    TRISA &= ~outputs;
}
void setOutputB(unsigned char outputs){
    TRISB &= ~outputs;
}
void setOutputC(unsigned char outputs){
    TRISC &= ~outputs;
}
void setOutputD(unsigned char outputs){
    TRISD &= ~outputs;
}
void setOutputE(unsigned char outputs){
    TRISE &= ~outputs;
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//--------------------------SET INPUTS------------------------------------------
//------------------------------------------------------------------------------
void setInputA(unsigned char inputs){
    TRISA|=inputs;
}
void setInputB(unsigned char inputs){
    TRISB |= inputs;
}
void setInputC(unsigned char inputs){
    TRISC|=inputs;
}
void setInputD(unsigned char inputs){
    TRISD|=inputs;
}
void setInputE(unsigned char inputs){
    TRISE|=inputs;
}
//------------------------------------------------------------------------------
void output_lowA(unsigned char outputs){
    LATA &= ~outputs;
}
void output_lowB(unsigned char outputs){
    LATB &= ~outputs;
}
void output_lowC(unsigned char outputs){
    LATC&=~outputs;
}
void output_lowD(unsigned char outputs){
	LATD&=~outputs;
}
void output_lowE(unsigned char outputs){
	LATE&=~outputs;
}
//------------------------------------------------------------------------------
void output_highA(unsigned char outputs){
    LATA |= outputs;
}
void output_highB(unsigned char outputs){
    LATB |= outputs;
}
void output_highC(unsigned char outputs){
    LATC |= outputs;
}
void output_highD(unsigned char outputs){
    LATD |= outputs;
}
void output_highE(unsigned char outputs){
    LATE |= outputs;
}
//------------------------------------------------------------------------------

void output_toggleB(unsigned char outputs){
    LATB ^= outputs;
}
void output_toggleC(unsigned char outputs){
    LATC ^= outputs;
}

void output_toggleD(unsigned char outputs){
    LATD ^= outputs;
}

int pinB(unsigned char inputs){
    if(PORTB && inputs){
        return 1;
    }
    else{
        return 0;
    }
}