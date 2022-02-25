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
#include "mUART.h"


int x = 0;

char arr[] = "Hello";


ISR(TIMER0_OVF_vect){
    
    static int counter = 0;
    
    counter++;
    
    if(counter == 61){
        counter = 0;
        UART_send('\r');
        UART_send_num(x++);
    }
    
}


int main(void) {
    /* Replace with your application code */
    
   
    
    init_UART(9600);
    init_Timer0(Normal, _Timer0_Pre_1024, Timer0_OVI);
    
    
    // To set any bit in UCSRC
    //UCSRC |= (1<<URSEL)|(1<<USBS);
   
    // To reset any bit in UCSRC
    //UCSRC = (1<<URSEL)|(UCSRC & (~(1<<USBS)));
            
    Enable_Global_INT();
    while (1) {

          


    }
}
