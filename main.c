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


#define _LED0   0
#define _LED1   1


char message1[] = "LED0 ON \r";
char message2[] = "LED0 OFF \r";
char message3[] = "LED1 ON \r";
char message4[] = "LED1 OFF \r";

void setupLEDs() {
    DDRA |= (1 << _LED0) | (1 << _LED1);
}

void _LED_ON(int ledNum){
    PORTA |= (1<<ledNum);
}

void _LED_OFF(int ledNum){
    PORTA &= ~(1<<ledNum);
}

ISR(USART_RXC_vect) {

    char receivedData = UDR;
    if (receivedData == 'A') {
        _LED_ON(_LED0);
        UART_send_str(message1);
    }
    if (receivedData == 'B') {
        _LED_OFF(_LED0);
        UART_send_str(message2);
    }
    if (receivedData == 'C') {
        _LED_ON(_LED1);
        UART_send_str(message3);
    }
    if (receivedData == 'D') {
        _LED_OFF(_LED1);
        UART_send_str(message4);
    }
}

int main(void) {
    /* Replace with your application code */

    setupLEDs();

    

    init_UART(9600);


    Enable_Global_INT();
    while (1) {



        _delay_ms(5000);
        _delay_ms(5000);
        _delay_ms(5000);
        _delay_ms(5000);



    }
}
