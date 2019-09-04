/* 
 * File:   sevenSeg.h
 * Author: root
 *
 * Created on July 15, 2019, 3:40 PM
 */

#ifndef SEVENSEG_H
#define	SEVENSEG_H

#ifdef	__cplusplus
extern "C" {
#endif
const char tabela[] = {
						0x3F,	// n�mero 0
						0x06,	// n�mero 1
						0x5B,	// n�mero 2
						0x4F,	// n�mero 3
						0x66,	// n�mero 4
						0x6D,	// n�mero 5
						0x7C,	// n�mero 6
						0x07,	// n�mero 7
						0x7F,	// n�mero 8
						0x67	// n�mero 9
						};
void configSevenSeg(void);
void printDigit1(unsigned char valor);
void printDigit2(unsigned char valor);
void printDigit3(unsigned char valor);
void printDigit4(unsigned char valor);


#ifdef	__cplusplus
}
#endif

#endif	/* SEVENSEG_H */

