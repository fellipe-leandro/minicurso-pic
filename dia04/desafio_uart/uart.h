/* 
 * File:   uart.h
 * Author: root
 *
 * Created on August 10, 2019, 10:19 AM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif
unsigned char Uart_Text[80]; //string padrao para uso
unsigned char UART_Init(const unsigned long int baudrate);
void UART_Write(unsigned char data);
void UART_Write_Text(unsigned char *text);
unsigned char UART_Read(void) ;
void UART_Read_Text(unsigned char *output,unsigned char length);
#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

