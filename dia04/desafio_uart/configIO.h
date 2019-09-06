/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CONFIGIO_H
#define	CONFIGIO_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>
#define PIN_A0 0b00000001
#define PIN_A1 0b00000010
#define PIN_A2 0b00000100
#define PIN_A3 0b00001000
#define PIN_A4 0b00010000
#define PIN_A5 0b00100000
#define PIN_A6 0b01000000
#define PIN_A7 0b10000000


#define PIN_B0 0b00000001
#define PIN_B1 0b00000010
#define PIN_B2 0b00000100
#define PIN_B3 0b00001000
#define PIN_B4 0b00010000
#define PIN_B5 0b00100000
#define PIN_B6 0b01000000
#define PIN_B7 0b10000000

#define PIN_C0 0b00000001
#define PIN_C1 0b00000010
#define PIN_C2 0b00000100
#define PIN_C3 0b00001000
#define PIN_C4 0b00010000
#define PIN_C5 0b00100000
#define PIN_C6 0b01000000
#define PIN_C7 0b10000000

#define PIN_D0 0b00000001
#define PIN_D1 0b00000010
#define PIN_D2 0b00000100
#define PIN_D3 0b00001000
#define PIN_D4 0b00010000
#define PIN_D5 0b00100000
#define PIN_D6 0b01000000
#define PIN_D7 0b10000000

#define PIN_E0 0b00000001
#define PIN_E1 0b00000010
#define PIN_E2 0b00000100
#define PIN_E3 0b00001000
#define PIN_E4 0b00010000
#define PIN_E5 0b00100000
#define PIN_E6 0b01000000
#define PIN_E7 0b10000000


// TODO Insert C++ class definitions if appropriate


// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation
void setOutputA(unsigned char outputs);
void setOutputB(unsigned char outputs);
void setOutputC(unsigned char outputs);
void setOutputD(unsigned char outputs);
void setOutputE(unsigned char outputs);

void setInputA(unsigned char inputs);
void setInputB(unsigned char inputs);
void setInputC(unsigned char inputs);
void setInputD(unsigned char inputs);
void setInputE(unsigned char inputs);

void output_lowA(unsigned char outputs);
void output_lowB(unsigned char outputs);
void output_lowC(unsigned char outputs);
void output_lowD(unsigned char outputs);
void output_lowE(unsigned char outputs);

void output_highA(unsigned char outputs);
void output_highB(unsigned char outputs);
void output_highC(unsigned char outputs);
void output_highD(unsigned char outputs);
void output_highE(unsigned char outputs);

void output_toggleB(unsigned char outputs);
void output_toggleC(unsigned char outputs);
void output_toggleD(unsigned char outputs);

int pinB(unsigned char inputs);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

