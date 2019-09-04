/* 
 * File:   pwm.h
 * Author: root
 *
 * Created on July 16, 2019, 3:53 PM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif
#define TMR2PRESCALE 16

#include <xc.h>

unsigned long frequency;

void PWM_setup(float frequencyArg);

void set_PWM1(unsigned int duty);
void set_PWM2(unsigned int duty);

int PWM_max_duty();

void PWM1_start();
void PWM2_start();

void PWM1_stop();
void PWM2_stop();


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

