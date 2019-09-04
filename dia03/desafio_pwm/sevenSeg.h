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
						0x3F,	// número 0
						0x06,	// número 1
						0x5B,	// número 2
						0x4F,	// número 3
						0x66,	// número 4
						0x6D,	// número 5
						0x7C,	// número 6
						0x07,	// número 7
						0x7F,	// número 8
						0x67	// número 9
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

