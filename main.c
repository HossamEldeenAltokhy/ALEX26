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


#define _LED0   2
#define MOTOR_pin   2
#define _LED1   7


char message1[] = "LED0 ON \n";
char message2[] = "LED0 OFF \n";
char message3[] = "LED1 ON \n";
char message4[] = "LED1 OFF \n";
char message5[] = "MOTOR ON \n";
char message6[] = "MOTOR OFF \n";

void setupLEDs() {
    DDRC |= (1 << _LED0) | (1 << _LED1);
}

void setupMOTOR() {
    DDRA |= (1 << MOTOR_pin);
}

void _LED_ON(int ledNum) {
    PORTC |= (1 << ledNum);
}

void _LED_OFF(int ledNum) {
    PORTC &= ~(1 << ledNum);
}

void motor_ON() {
    PORTA |= (1 << MOTOR_pin);
}
void motor_OFF() {
    PORTA &= ~(1 << MOTOR_pin);
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

ISR(TIMER0_OVF_vect) {

    static int counter = 0;

    counter++;


    if (counter == 61 * 5) {
        counter = 0;
        ADC_SC();
        ADC_wait();
        int data = ADC_read()* (5.0 / 1024.0)*1000;
        if (data >= 3000) {
            motor_ON();
            UART_send_str(message5);
        }
        else{
            motor_OFF();
            UART_send_str(message6);
        }
        UART_send_num(data);
        UART_send('\n');
    }

}

int main(void) {
    /* Replace with your application code */
    setupMOTOR();
    setupLEDs();

    init_Timer0(Normal, _Timer0_Pre_1024, Timer0_OVI);
    init_ADC(CH1, AVCC, _Pre_128, Booling);


    init_UART(9600);


    Enable_Global_INT();
    while (1) {




        _delay_ms(2000);



    }
}
