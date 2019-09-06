/*
 * File:   mainApp.c
 * Author: root
 *
 * Created on July 16, 2019, 4:11 PM
 */


#include <xc.h>
#include "pwm.h"
#include "config_bits.h"
void main(void){
    PWM_setup(500);	// Configura o PWM E Define a frequencia em Hz
    set_PWM2(70);      // Define o duty Cycle entre 0 a 1024 (Perfeito para o potenciomentro)
    set_PWM1(30);      // Define o duty Cycle entre 0 a 1024 (Perfeito para o potenciomentro)
    PWM2_start();   	// Inicia o PWM
    PWM1_start();   	// Inicia o PWM
    while(1){
        
    }
}