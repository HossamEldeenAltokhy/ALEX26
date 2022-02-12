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



char Hello[] = "Hello";
int result;
int main(void) {
    /* Replace with your application code */
    
    init_LCD_4bits();
    init_ADC(CH1, AVCC, _Pre_128, Booling);
    while (1) {
        
        ADC_SC();
        ADC_wait();
        result = ADC_read()*4.8828125;
        LCD_CLEAR_4bits();
        LCD_NUM_4bits(result);
        _delay_ms(200);
        
    }
}
