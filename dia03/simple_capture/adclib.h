/* 
 * File:   adclib.h
 * Author: Fellipe Leandro
 *
 * Created on September 9, 2018, 11:25 PM
 */

#ifndef ADCLIB_H
#define	ADCLIB_H
#include <xc.h>
#define ADC_CLOCK_2     0b00000000
#define ADC_CLOCK_8     0b00000001
#define ADC_CLOCK_32    0b00000010
#define ADC_CLOCK_RC    0b00000011
#define ADC_CLOCK_4     0b00000100
#define ADC_CLOCK_16    0b00000101
#define ADC_CLOCK_64    0b00000110

#define ADC_TAD_0       0b00000000
#define ADC_TAD_2       0b00001000
#define ADC_TAD_4       0b00010000
#define ADC_TAD_6       0b00011000
#define ADC_TAD_8       0b00100000
#define ADC_TAD_12      0b00101000
#define ADC_TAD_16      0b00110000
#define ADC_TAD_20      0b00111000

#define ADC_CONFIG_0     0b00000000
#define ADC_CONFIG_1     0b00000001  
#define ADC_CONFIG_2     0b00000010 
#define ADC_CONFIG_3     0b00000011 
#define ADC_CONFIG_4     0b00000100
#define ADC_CONFIG_5     0b00000101
#define ADC_CONFIG_6     0b00000110
#define ADC_CONFIG_7     0b00000111
#define ADC_CONFIG_8     0b00001000
#define ADC_CONFIG_9     0b00001001
#define ADC_CONFIG_10    0b00001010
#define ADC_CONFIG_11    0b00001011
#define ADC_CONFIG_12    0b00001100
#define ADC_CONFIG_13    0b00001101
#define ADC_CONFIG_14    0b00001110
#define ADC_CONFIG_15    0b00001111

#define RIGHT_JUST      0b10000000
#define LEFT_JUST       0b00000000

void adcConfig(unsigned char conversionRate,unsigned char acqTime,unsigned char portConfig);
unsigned int adcRead(unsigned char channel,unsigned char resultFormat);



#endif	/* ADCLIB_H */

