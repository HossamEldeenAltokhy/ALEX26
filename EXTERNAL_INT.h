/* 
 * File:   EXTERNAL_INT.h
 * Author: hossa
 *
 * Created on February 4, 2022, 5:10 PM
 */

#ifndef EXTERNAL_INT_H
#define	EXTERNAL_INT_H



#define INT_LOW_LEVEL      0  // 00
#define INT_ANY_CHANGE     1  // 01
#define INT_FALLING        2  // 10
#define INT_RISING         3  // 11

void INT0_selectMode(char INT_MODE);

void INT0_Enable();
void INT0_Disable();

void Enable_Global_INT();

/**
 * 
 * @param INT_MODE select ( LOW,ANY, FALLING or RISING)
 */
void INT0_init(char INT_MODE);
#endif	/* EXTERNAL_INT_H */

