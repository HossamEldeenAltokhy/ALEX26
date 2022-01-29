#define F_CPU 16000000UL

#include "avr/io.h"
#include <util/delay.h>
#include "mKIT.h"


#define Keypad_DIR       DDRD
#define Keypad_DATA_OUT  PORTD
#define Keypad_DATA_IN   PIND

#define column0       4
#define column1       5
#define column2       6
#define column3       7


void init_KeyPad();
int getKeypad();

int main(void) {

    DDRA = 0xFF;
    init_KeyPad();

    while (1) {

        PORTA = getKeypad();

    }

}

void init_KeyPad() {


    Keypad_DIR &= 0x0F;
    //    Keypad_DIR &= ~((1<<7)|(1<<6)|(1<<5)|(1<<4));

    Keypad_DIR |= 0x07; // 0b00000111

    Keypad_DATA_OUT |= 0x07;
}

int getKeypad() {
    Keypad_DATA_OUT |= 0x07;
    _delay_ms(10);
    if (Keypad_DATA_IN & (0xF0)) { // xxxxxxxx & 0b11110000
        // Keypad is pressed
        if (Keypad_DATA_IN & (1 << column0)) {
            // 1,2 or 3
            Keypad_DATA_OUT &= 0xF8;
            _delay_ms(10);
            Keypad_DATA_OUT |= (1 << 0);
            _delay_ms(10);
            if (Keypad_DATA_IN & (1 << column0)) {
                // 
                Keypad_DATA_OUT |= 0x07;
                _delay_ms(10);
                return 3;
            } else {
                Keypad_DATA_OUT &= 0xF8;
                _delay_ms(10);
                Keypad_DATA_OUT |= (1 << 1);
                _delay_ms(10);
                if (Keypad_DATA_IN & (1 << column0)) {
                    // 
                    Keypad_DATA_OUT |= 0x07;
                    _delay_ms(10);
                    return 2;
                }else{
                    Keypad_DATA_OUT |= 0x07;
                    _delay_ms(10);
                    return 1;
                }
            }
        } else if (Keypad_DATA_IN & (1 << column1)) {
            // 6,5,or 4
             Keypad_DATA_OUT &= 0xF8;
            _delay_ms(10);
            Keypad_DATA_OUT |= (1 << 0);
            _delay_ms(10);
            if (Keypad_DATA_IN & (1 << column1)) {
                // 
                Keypad_DATA_OUT |= 0x07;
                _delay_ms(10);
                return 6;
            } else {
                Keypad_DATA_OUT &= 0xF8;
                _delay_ms(10);
                Keypad_DATA_OUT |= (1 << 1);
                _delay_ms(10);
                if (Keypad_DATA_IN & (1 << column1)) {
                    // 
                    Keypad_DATA_OUT |= 0x07;
                    _delay_ms(10);
                    return 5;
                }else{
                    Keypad_DATA_OUT |= 0x07;
                    _delay_ms(10);
                    return 4;
                }
            }
        } else if (Keypad_DATA_IN & (1 << column2)) {
            // 7,8,or 9
             Keypad_DATA_OUT &= 0xF8;
            _delay_ms(10);
            Keypad_DATA_OUT |= (1 << 0);
            _delay_ms(10);
            if (Keypad_DATA_IN & (1 << column2)) {
                // 
                Keypad_DATA_OUT |= 0x07;
                _delay_ms(10);
                return 9;
            } else {
                Keypad_DATA_OUT &= 0xF8;
                _delay_ms(10);
                Keypad_DATA_OUT |= (1 << 1);
                _delay_ms(10);
                if (Keypad_DATA_IN & (1 << column2)) {
                    // 
                    Keypad_DATA_OUT |= 0x07;
                    _delay_ms(10);
                    return 8;
                }else{
                    Keypad_DATA_OUT |= 0x07;
                    _delay_ms(10);
                    return 7;
                }
            }
        } else if (Keypad_DATA_IN & (1 << column3)) {
            // *,0,or #    
        } else {

        }

        
        
    }
}