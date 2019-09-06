/*
 * File:   mainApp.c
 * Author: Fellipe
 * Desafio: UART + ADC + CCP (PWM e Capture)
 * Created on August 10, 2019, 11:14 AM
 */


#include"config_bits.h"
#include <xc.h>
#include <stdio.h>
#include <string.h>
#define _XTAL_FREQ 8000000
#include"configIO.h"
#include "adclib.h"
#include "sevenSeg.h"

//#define PWM_PERCENT
#include "pwm.h"
#include "uart.h"
volatile unsigned char timerCount=0;
volatile unsigned int t1,t2,contIntCcp;
volatile char ccp_flag=0;
volatile unsigned char uart_rx=0;
volatile unsigned char uart_flag=0;

void printDisplays(unsigned int valor);
void Capture_Setup(){ 
    PIR1bits.TMR1IF=0; 
    INTCON=0b11000000;  //habilita Interrupção global e de perifericos
    PIE1=0b00000101;    //habilita interrupção de ccp1 e timer1
    T1CON=0b00110000;   //prescaler tmr1/8
    CCP1CON = 0b00000101;   //capture mode, every rising edge
    TRISCbits.TRISC2 = 1;   //pino como entrada
    TMR1 = 0;               //limpa registrador
    T1CONbits.TMR1ON=1;     // iniciar contador
    PIR1bits.CCP1IF = 0;    //limpa flag de interrupção do modulo CCP1    
    
}

void interrupt ISR(){
    if(PIR1bits.TMR1IF){
        if(contIntCcp>=1){
            timerCount++;
        }
        TMR1IF=0; 
    }
    if(PIR1bits.CCP1IF){
        contIntCcp++;
        t2 = t1;
        t1 =CCPR1H;
        t1=(t1<<8)|CCPR1L;
        CCP1IF = 0;
        if(contIntCcp==2)
            ccp_flag=1;
        
    }
    if(PIR1bits.RCIF){
        RCIF=0;
        uart_rx=UART_Read();
        uart_flag=1;
    }
}


void main(void) {
     float aux;
    unsigned int leituraADC;
    unsigned int frequencia;
    unsigned long periodo = 0;
    t2 = 0;
    t1 = 0;
    contIntCcp = 0;
    setInputA(PIN_A0);
    adcConfig(ADC_CLOCK_8,ADC_TAD_6,ADC_CONFIG_0);
    PWM_setup(1000);   // Configura o PWM E Define a frequencia em Hz
    set_PWM2(700);      // Define o duty Cycle entre 0 a 1024 (Perfeito para o potenciomentro)
    PWM2_start();       // Inicia o PWM
    Capture_Setup(); //habilita sistema de interrupção
    configSevenSeg();
    setOutputD(PIN_D0|PIN_D1|PIN_D2|PIN_D3|PIN_D4|PIN_D5|PIN_D6|PIN_D7);
    unsigned char uart_error=UART_Init(9600);
    if(!uart_error)
    {
        //do something
    }
    
    strcpy(Uart_Text,"PIC18F4520 - UART Communication\r\n");
    UART_Write_Text(Uart_Text);
    while(1){
        leituraADC = adcRead(0,RIGHT_JUST);   // Read Analog Channel 0
        set_PWM2(leituraADC);   // Define o duty Cycle entre 0 a 1024 (Perfeito para o potenciomentro)
        if(ccp_flag){
            periodo = timerCount*0xFFFF+t1-t2;
            timerCount = 0;
            periodo*=8;
            frequencia = (1/((float)periodo*0.0000005));
            contIntCcp=0;
            ccp_flag=0;
            printDisplays(frequencia);
        }
        if(uart_flag){
            switch(uart_rx){
                case 'd':
                    aux=((float)leituraADC)/1023;
                    aux=aux*100;
                    sprintf(Uart_Text,"Duty Cycle atual:%.2f%%\r\n",aux);
                    UART_Write_Text(Uart_Text);
                    break;
                case 'f':
                    sprintf(Uart_Text,"Freq de rotacao:%d Hz\r\n",frequencia);
                    UART_Write_Text(Uart_Text);
                    break;
                default:
                    break;
                    
                    
            }
            uart_flag=0;
        }
        //__delay_ms(40);
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