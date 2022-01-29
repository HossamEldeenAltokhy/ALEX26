/* 
 * File:   mKIT.h
 * Author: hossa
 *
 * Created on January 29, 2022, 2:10 PM
 */

#ifndef MKIT_H
#define	MKIT_H

#define LED0   2
#define LED1   7
#define LED2   3

#define BTN0   0
#define BTN1   6
#define BTN2   2



void init_BTNs();

int isPressed(int PB_NUM);


void init_LEDs(void);
void LED_ON(int LED);
void LED_OFF(int LED);
void LED_TOGGLE(int LED);
int LED_CHECK(int LED);

#endif	/* MKIT_H */

