/*
 * File:   main.c
 * Author: Fellipe Leandro
 * I2C teste para interfaceamento com meória EEproM
 * Created on August 12, 2019, 12:34 AM
 */

//Libraries
#include <xc.h>
#include "i2c.h"
//maybe: config_bits.h

//Defines:
#define LC01CTRLIN  0xA0         //I2C value for CONTROL BYTE IN to the EEPROM device
#define LC01CTRLOUT 0xA1         //I2C value for CONTROL BYTE OUT to the EEPROM device
#define LC01ADDR    0x12         //Address BYTE
#define LC01DATA    0x34         //DATA to be write in EEPROM 
 unsigned char i2c_val @ 0x70;
#define _XTAL_FREQ 8000000

void main(void) {
    i2c_val=0x00;
    I2C_Setup(100);
    //Write Sequence:
    I2C_Start();
    Wait_MSSP();
    //Send CONTROL BYTE and wait to complete
    Send_I2C_Byte((unsigned char)LC01CTRLIN);
    Wait_MSSP();
    //Send Memory Adress
    Send_I2C_Byte((unsigned char)LC01ADDR);
    Wait_MSSP(); //trocar sequencia com o de baixo
    Send_I2C_Byte((unsigned char)LC01DATA);
    //Send DATA BYTE, wait to complete
    Wait_MSSP();
    //Send STOP condition, wait to complete
    I2C_Stop();
    Wait_MSSP();
    __delay_ms(300);
    //---------------------//-----------------------
    //Read Value
    I2C_Start();
    Wait_MSSP();
    Send_I2C_Byte((unsigned char)LC01CTRLIN);
    Wait_MSSP();
    Send_I2C_Byte((unsigned char)LC01ADDR);
    Wait_MSSP();
    I2C_Restart();
    Wait_MSSP();
    //Send CONTROL BYTE OUT
    Send_I2C_Byte((unsigned char)LC01CTRLOUT);
    Wait_MSSP();
   //Enable Receive Mode
    I2C_RMode();
    //Get DATA BYTE and wait to complete. Data is in SSPBUF when done
    Wait_MSSP();
    //Send NACK bit to EEPROM
    I2C_SendNack();
    Wait_MSSP();
    //Send STOP Condition
    I2C_Stop();
     Wait_MSSP();
    __delay_ms(10);
    i2c_val=SSPBUF;
    //Sequence Finished, send value to LEDS ond PORTB
    while(1);
    return;
}
