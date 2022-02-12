/*
 * File:   main.c
 * Author: hossa
 *
 * Created on February 11, 2022, 3:58 PM
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "mLCD_4bits.h"
#include "mKIT.h"
#include "mADC.h"
#include "mTimer0.h"
#include "EXTERNAL_INT.h"
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect) {

   
        PORTA ^= 0xFF;
       

}

int main(void) {
    /* Replace with your application code */
    DDRA = 0xFF;
    init_Timer0(Normal , _Timer0_Pre_1024, Timer0_OVI);


    Enable_Global_INT();
    while (1) {



    }
}
