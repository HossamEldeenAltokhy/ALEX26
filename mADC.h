/* 
 * File:   mADC.h
 * Author: hossa
 *
 * Created on February 5, 2022, 2:51 PM
 */

#ifndef MADC_H
#define	MADC_H

#define AREF        0
#define AVCC        1
#define INTERNAL    3  // 2.56V

#define CH0    0
#define CH1    1
#define CH2    2
#define CH3    3
#define CH4    4
#define CH5    5
#define CH6    6
#define CH7    7
#define CH0_CH1 16

#define _Pre_2       1
#define _Pre_4       2
#define _Pre_8       3
#define _Pre_16      4
#define _Pre_32      5
#define _Pre_64      6
#define _Pre_128     7

// ADMUX
void ADC_selectRef(char Voltage_REF);
void ADC_selectCH(char CH_Num);

//ADCSA
void ADC_selectPRE(char PRE);
void ADC_enable();
void ADC_SC(); // Start Conversion
void ADC_INT_enable();  // Enable ADC Interrupt
void ADC_wait();
int ADC_read();
#endif	/* MADC_H */

