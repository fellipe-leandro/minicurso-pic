/* 
 * File:   i2c.h
 * Author: root
 *
 * Created on August 12, 2019, 12:31 AM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif
void I2C_Setup(unsigned int baud);
static void I2C_Fail(void);
void Send_I2C_Byte(unsigned char data);
void Wait_MSSP(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_SendNack(void);
void I2C_RMode(void);
#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

