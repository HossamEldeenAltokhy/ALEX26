#define F_CPU 16000000UL

#include "avr/io.h"
#include "EXTERNAL_INT.h"
#include "mADC.h"
#include "mLCD_4bits.h"
#include <avr/interrupt.h>
#include <util/delay.h>

//ISR(ADC_vect) {
//    int data = ADC_read()*0.1953125; // in 'C
//
//    LCD_CLEAR_4bits();
//    LCD_NUM_4bits(data);
//    _delay_ms(50);
//    
//    if(data > 3000){
//        PORTB = 0xFF;
//    }else{
//        PORTB = 0x00;
//    }
//    
//}

int main(void) {

    DDRB = 0xFF;
    DDRC &= ~(1 << 0);
    init_LCD_4bits();

    ADC_selectCH(CH0_CH1);
    ADC_selectRef(AVCC);
    ADC_selectPRE(_Pre_128);
    //ADC_INT_enable();
    ADC_enable();


    //Enable_Global_INT();
    ADC_SC();

    while (1) {


        if (PINC & (1 << 0)) {
            ADC_SC();
            ADC_wait();
            // reading Data
            int data = ADC_read()*0.1953125; // in 'C
            LCD_CLEAR_4bits();
            LCD_NUM_4bits(data);
            _delay_ms(500);
        }






    }

}
