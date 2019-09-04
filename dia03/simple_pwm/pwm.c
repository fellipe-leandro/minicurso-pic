/*
 * File:   pwm.c
 * Author: root
 *
 * Created on July 16, 2019, 3:54 PM
 */


#include <xc.h>
#include "pwm.h"

int PWM_max_duty(){
    return (_XTAL_FREQ/(frequency*TMR2PRESCALE));
}

void PWM_setup(float frequencyArg){
    PR2 = (char)(_XTAL_FREQ/(frequencyArg*4*TMR2PRESCALE)) - 1;
  frequency = (long)frequencyArg;
}
void set_PWM1(unsigned int duty){
    float aux;
    aux=((float)(duty))/100;
    duty=aux*1023;
    if(duty<1024)
    {
        duty = ((float)duty/1023)*PWM_max_duty();
        CCPR1L = duty>>2;
        DC1B1 = (duty & 0x0002)>>1;
        DC1B0 = duty & 0x0001 ;
        
    }
}

void set_PWM2(unsigned int duty){
    float aux;
    aux=((float)(duty))/100;
    duty=aux*1023;
    if(duty<1024)
    {
        duty = ((float)duty/1023)*PWM_max_duty();
        CCPR2L = duty>>2;
        DC2B1 = (duty & 0x0002)>>1;
        DC2B0 = duty & 0x0001 ;
        
    }
}
void PWM1_start(){
    CCP1M3 = 1;
    CCP1M2 = 1;
    #if TMR2PRESCALE == 1
        T2CKPS0 = 0;
        T2CKPS1 = 0;
    #elif TMR2PRESCALE == 4
        T2CKPS0 = 1;
        T2CKPS1 = 0;
    #elif TMR2PRESCALE == 16
        T2CKPS0 = 1;
        T2CKPS1 = 1;
    #endif
        TMR2ON = 1;
        TRISC2 = 0;
}

void PWM2_start(){
    CCP2M3 = 1;
    CCP2M2 = 1;
    #if TMR2PRESCALE == 1
        T2CKPS0 = 0;
        T2CKPS1 = 0;
    #elif TMR2PRESCALE == 4
        T2CKPS0 = 1;
        T2CKPS1 = 0;
    #elif TMR2PRESCALE == 16
        T2CKPS0 = 1;
        T2CKPS1 = 1;
    #endif
        TMR2ON = 1;
        TRISC1 = 0;
}
void PWM1_stop(){
    CCP2M3 = 0;
    CCP2M2 = 0;
}

void PWM2_stop(){
    CCP2M3 = 0;
    CCP2M2 = 0;
}
