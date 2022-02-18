/*
 * File:   main.c
 * Author: hossa
 *
 * Created on February 11, 2022, 3:58 PM
 */

#define F_CPU 1000000UL
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
#define OC0  3

ISR(TIMER0_OVF_vect){
    
}

char speed = 0;
char unit[] = " %";
int main(void) {
    /* Replace with your application code */
    
    init_LCD_4bits();
    
    
    Timer0_setDutyCyle(10);
    Timer0_OC0_PWM(OC0_PWM_SetUpClearDown);
    init_Timer0(PWM , _Timer0_Pre_1024, Timer0_OVI); // 61 times per second

    
    Enable_Global_INT();
    
    while (1) {

        if(PINC & (1<<0)){
            speed += 10;
            Timer0_setDutyCyle(speed);
            LCD_CLEAR_4bits();
            LCD_NUM_4bits(speed);
            LCD_str_4bits(unit);
            _delay_ms(500);

        }

        if(PINC & (1<<1)){
            speed -= 10;
            Timer0_setDutyCyle(speed);
            LCD_CLEAR_4bits();
            LCD_NUM_4bits(speed);
            LCD_str_4bits(unit);
            _delay_ms(500);

        }


    }
}
