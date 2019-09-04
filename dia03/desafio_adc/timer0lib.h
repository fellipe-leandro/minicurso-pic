/* 
 * File:   timer0lib.h
 * Author: Fellipe
 *
 * Created on September 8, 2018, 1:13 PM
 */

#ifndef TIMER0LIB_H
#define	TIMER0LIB_H


#define PRESCALER2      0b00000000
#define PRESCALER4      0b00000001
#define PRESCALER8      0b00000010
#define PRESCALER16     0b00000011
#define PRESCALER32     0b00000100
#define PRESCALER64     0b00000101
#define PRESCALER128    0b00000110
#define PRESCALER256    0b00000111

void configTimer0(unsigned char prescalerValue);

void setTimer0Value(unsigned char value);

unsigned char getTimer0Value(void);

void resetTimer0(void);

void enableTimer0ISR(void);



#endif	/* TIMER0LIB_H */

