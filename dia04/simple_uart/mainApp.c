/*
 * File:   mainApp.c
 * Author: Fellipe Leandro
 * CÛdigo de comunicaÁ„o UART para minicurso 2019
 *
 * Created on August 10, 2019, 10:34 AM
 */


#include <xc.h>
#include <string.h>
#define _XTAL_FREQ 8000000
#include "uart.h"
volatile unsigned char uart_rx=0;
volatile unsigned char uart_flag=0;
void interrupt interrompa(void){

    if(RCIF) // Algum dado no rx?
    {
         RCIF=0;
        uart_rx=UART_Read();
        uart_flag=1;
       
    }
}
void main(void) {
    
    unsigned char uart_error=UART_Init(9600);
    if(!uart_error)
    {
        //do something
    }
    
    strcpy(Uart_Text,"PIC18F4520 - UART Communication\r\n");
    UART_Write_Text(Uart_Text);
    GIE=1;          //Desabilitando interrup√ß√£o global
    PEIE=1;         // Habilitando interrup√ß√£o dos perif√©ricos
    while(1){
        if(uart_flag){
            strcpy(Uart_Text,"\r\nVoce digitou ");
            UART_Write_Text(Uart_Text);
            UART_Write(uart_rx);
            uart_flag=0;
        }
        
    }
}
