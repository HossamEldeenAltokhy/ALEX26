#define F_CPU 16000000UL

#include "avr/io.h"
#include <util/delay.h>
#include "mKIT.h"
#include "mLCD_4bits.h"
#include "EXTERNAL_INT.h"
#include <avr/interrupt.h>


ISR(INT0_vect){
    
    PORTA ^= 0xFF;
    
}


int main(void) {

    DDRA = 0xFF; // set PORTA as OUT
    
    INT0_init(INT_RISING);

    Enable_Global_INT();
    while (1) {
        

    }

}
