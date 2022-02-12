#include "mKIT.h"
#include <avr/io.h>


void init_LEDs(void) {
    DDRC |= (1 << LED0) | (1 << LED1);
    DDRD |= (1 << LED2);
}

int LED_CHECK(int LED) {
    if (LED == LED2) {
        if (PORTD & (1 << LED)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (PORTC & (1 << LED)) {
            return 1;
        } else {
            return 0;
        }
    }
}

void init_BTNs() {
    DDRB &= ~(1 << BTN0);
    DDRD &= ~((1 << BTN1) | (1 << BTN2));
}

void LED_ON(int LED) {
    if (LED == LED2) {
        PORTD |= (1 << LED);
    } else {
        PORTC |= (1 << LED);
    }
}

void LED_OFF(int LED) {
    if (LED == LED2) {
        PORTD &= ~(1 << LED);
    } else {
        PORTC &= ~(1 << LED);
    }
}

void LED_TOGGLE(int LED) {
    if (LED == LED2) {
        PORTD ^= (1 << LED);
    } else {
        PORTC ^= (1 << LED);
    }
}

int isPressed(int PB_NUM) {
    if (PB_NUM == BTN0) {
        if (PINB & (1 << BTN0)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (PIND & (1 << PB_NUM)) {
            return 1;
        } else {
            return 0;
        }
    }

    return 0;
}
