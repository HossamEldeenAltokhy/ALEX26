/* 
 * File:   mTimer0.h
 * Author: hossa
 *
 * Created on February 12, 2022, 2:54 PM
 */

#ifndef MTIMER0_H
#define	MTIMER0_H


#define _TimerOFF         0x00
#define _NoPrescalar      0x01
#define _Timer0_Pre_8            0x02
#define _Timer0_Pre_64           0x03
#define _Timer0_Pre_256          0x04
#define _Timer0_Pre_1024         0x05
#define _External_Falling 0x06
#define _External_Rising  0x07


#define Normal      0x00    
#define PWM         0x40
#define CTC         0x08
#define FPWM        0x48

#define Timer0_OVI  0x01
#define Timer0_OCI  0x02


void Timer0_OFF();
void Timer0_selectCLK(char _clock);
void Timer0_selectMode(char Timer0_Mode);

// Interrupt Enable
void Timer0_enableINT(char Timer0_INT);
void Timer0_disableINT(char Timer0_INT);



void init_Timer0(char Timer0_Mode, char _clock,char Timer0_INT);
#endif	/* MTIMER0_H */

