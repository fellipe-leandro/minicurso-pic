/*
 * File:   uart.c
 * Author: root
 *
 * Created on August 10, 2019, 10:21 AM
 */


#include <xc.h>
#include "uart.h"
unsigned char UART_Init(const unsigned long int baudrate)
{
    unsigned int x;
    x=(_XTAL_FREQ-(baudrate<<6))/(baudrate<<6); // SPBRG for Low Baud Rate
    if(x>255) // If High Baud Rage Required
    {
        x=(_XTAL_FREQ-(baudrate<<4))/(baudrate<<4); // SPBRG for High Baud Rate
        BRGH=1; // Setting High Baud Rate
    }
    if(x<256)
    {
        SPBRG=x; // Writing SPBRG Register
        SYNC=0; // Setting Asynchronous Mode, ie UART
        SPEN=1; // Enables Serial Port
        TRISC7=1; // As Prescribed in Datasheet
        TRISC6=1; // As Prescribed in Datasheet
        RCIE=1; // Enables Rx interruption
        CREN=1; // Enables Continuous Reception
        TXEN=1; // Enables Transmission
        RCIF=0;
        return 1; // Returns 1 to indicate Successful Completion
    }
    return 0; // Returns 0 to indicate UART initialization failed
}
void UART_Write(unsigned char data) // Ou char?
{
    while(!TRMT)
    {}
    TXREG=data;
}
void UART_Write_Text(unsigned char *text)
{
    unsigned char i;
    for(i=0;text[i]!='\0';i++)
    {
        UART_Write(text[i]);
    }
}
unsigned char UART_Read(void) // Reads a character
{
    while(!RCIF)
    {}
    if(OERR) // Overrun Error Bit is set?
    {
        RD5=1;
    }
    else
    {
        RD5=0;
    }
    return RCREG;
}
void UART_Read_Text(unsigned char *output,unsigned char length)
{
    unsigned char i;
    for(i=0;i<length;i++)
    {
        output[i]=UART_Read();
    }
}
