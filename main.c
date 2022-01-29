#define F_CPU 16000000UL

#include "avr/io.h"
#include <util/delay.h>
#include "mKIT.h"
#include "mLCD_8bits.h"

char str[] = "AHMED";

int main(void) {

    int x = 5344;

    init_LCD();
    

    while (1) {
        x++;
        LCD_CLEAR();
        LCD_NUM(x);
        _delay_ms(500);

    }

}
