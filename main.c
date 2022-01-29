#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED0   2
#define LED1   7
#define LED2   3

#define BTN0   0
#define BTN1   6
#define BTN2   2



void init_BTNs();

int isPressed(int PB_NUM);


void init_LEDs(void);
void LED_ON(int LED);
void LED_OFF(int LED);
void LED_TOGGLE(int LED);
int LED_CHECK(int LED);

int flag = 0;

int main(void) {

    init_LEDs();
    init_BTNs();
    while (1) {

        while (isPressed(BTN0)) {
            _delay_ms(50);
            if (!isPressed(BTN0)) {
                if (flag) {
                    flag = 0;
                    break;
                } else {
                    flag = 1;
                    break;
                }
            }
        }


        if (flag) {
            LED_ON(LED0);
        } else {
            LED_OFF(LED0);
        }

    }

    return 0;
}

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