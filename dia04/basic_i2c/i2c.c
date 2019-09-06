/*
 * File:   i2c.c
 * Author: root
 *
 * Created on August 12, 2019, 12:33 AM
 */


#include <xc.h>
#include "i2c.h"
void I2C_Setup(unsigned int baud){
    TRISB = 0b00000011;  //RB0 and RB1 as inputs
     //Configure MSSP module for Master Mode
    SSPCON1 = 0x28;       //Enables I2C(SPEN bit set) and enables I2C Master Mode (SSPMx bit)
    
    //Input Levels and slew rate as I2C Standard Levels
    SSPSTAT = 0x80;      //Slew rate control disabled for standard speed (100kHz)
                         //and input levels are I2C Standard
   
    //Configure Baud Rate
    SSPADD = (4000/(4*baud)) -1;
}
static void I2C_Fail(void)
{
    //Subroutine for I2C operation failed code sequence. If ir occurs, a STOP bit is sent
    //and the entire code is tried again
    //SSPCON2 Register:
    PEN=1;  //Sends Stop Condition
    //Inserir alguma rotina....
    
}
void Send_I2C_Byte(unsigned char data)
{   //This routine send a byte to SSPBUF, transmitting it. The SSPIF flag is checked
    //to ensure the byte has been sent.
    unsigned char trash=SSPBUF; //limpando SSPBUF
    SSPBUF = data;
    return;
    
}

void Wait_MSSP(void)
{
    //Waits for the last I2C operation to complete, checking the SSPIF in PIR1
    while(!SSPIF) //Wait while SSPIF is clear
    {
    }
    //PORTB=0x02;
    //Quits loop, thus SSPIF==1
    SSPIF = 0;
    if(ACKSTAT)
        I2C_Fail();
    
   return;
}
void I2C_Start(void)
{
    SEN=1;
}
void I2C_Stop(void)
{
    PEN=1;
}
void I2C_Restart(void)
{
    RSEN=1;     //Send Restart Condition
}
void I2C_SendNack(void)
{
    ACKDT = 1;  //ACK to send is 1 (which is a NACK)
    ACKEN = 1;  //Send NACK now
    
}
void I2C_RMode(void)
{
    //Enable Receive Mode
    
   //SSPCON2 Register:
    RCEN = 1;
}
