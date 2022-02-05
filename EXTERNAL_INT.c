#include <avr/io.h>
#include <avr/interrupt.h>
#include "EXTERNAL_INT.h"

void INT0_selectMode(char INT_MODE) {
    MCUCR &= 0xFC; // 11111100
    MCUCR |= INT_MODE & 0x03; // 00000011
}


void INT0_Enable() {
    GICR |= (1 << INT0);
}

void INT0_Disable() {
    GICR &= ~(1 << INT0);
}

void Enable_Global_INT() {
    sei();
}
/**
 * 
 * @param INT_MODE select ( LOW,ANY, FALLING or RISING)
 */
void INT0_init(char INT_MODE) {
    INT0_selectMode(INT_MODE);
    INT0_Enable();
}

/***
     switch(INT_MODE){
        case INT_LOW_LEVEL:
            MCUCR &= ~((1<<ISC01)|(1<<ISC00));
            break;
        case INT_ANY_CHANGE:
            MCUCR &= ~((1<<ISC01));
            MCUCR |= ((1<<ISC00));
            break;
        case INT_FALLING:
            MCUCR &= ~((1<<ISC00));
            MCUCR |= ((1<<ISC01));
            break;
        case INT_RISING:
            MCUCR |= ((1<<ISC01)|(1<<ISC00));
            break;
    }*/