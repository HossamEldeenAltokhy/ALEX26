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

#define MOSI    5
#define SS      4
#define SCK     7

void SPI_send(char data);


int main(void) {
    /* Replace with your application code */

    DDRB |= (1<<MOSI)|(1<<SS)|(1<<SCK); // Alternative Function ON
    SPCR |= (1 << SPR1) | (1 << SPR0); // F(OSC) / 128
    SPCR |= (1 << MSTR); // Set SPI as master mode
    SPCR |= (1 << SPE); //  Finally , Enable SPI.

    

    while (1) {

        SPI_send('A');
        _delay_ms(2);
    }
}



void SPI_send(char data) {
    // Send Data first then Booling.
//    PORTB &= ~(1<<SS);
//    _delay_us(5);
    SPDR = data;
    
    // Booling till flag is set
    while (!(SPSR & (1 << SPIF)));
//    PORTB |= (1<<SS);
//    _delay_ms(5);
}