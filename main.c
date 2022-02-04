#define F_CPU 16000000UL

#include "avr/io.h"
#include <util/delay.h>
#include "mKIT.h"
#include "mLCD_4bits.h"

char str[] = "AHMED";

int main(void) {

    int x = 5344;

    init_LCD_4bits();
    

    while (1) {
        x++;
        LCD_CLEAR_4bits();
        LCD_NUM_4bits(x);
        _delay_ms(500);

    }

}
