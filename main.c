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

#define timeInSeconds  5
#define timeInHalfSeconds  0
#define timeInQuarterSeconds  0

ISR(TIMER0_COMP_vect) {
    static int x = 0;
    x++;
//    if(x == 61*timeInSeconds+30*timeInHalfSeconds+15*timeInQuarterSeconds){
    if(x == 61){
        ADC_SC();
        x=0;
    }
}

ISR(ADC_vect){
    int data = ADC_read()*4.8;
        LCD_CLEAR_4bits();
        LCD_NUM_4bits(data);
}

int main(void) {
    /* Replace with your application code */
    
    init_LCD_4bits();
    init_ADC(CH0, AVCC, _Pre_128, Non_Booling);
    Timer0_setComp(100);
    init_Timer0(CTC , _Timer0_Pre_1024, Timer0_OCI); // 61 times per second

    Enable_Global_INT();
    while (1) {



    }
}
