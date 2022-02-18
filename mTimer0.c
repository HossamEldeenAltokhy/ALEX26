#include <avr/io.h>
#include "mTimer0.h"



void Timer0_setComp(char val){
    OCR0 = val;
}

void Timer0_OFF(){
    TCCR0 &= 0xF8;
}
void Timer0_selectCLK(char _clock){
    Timer0_OFF();
    TCCR0 |= _clock;
}
void Timer0_selectMode(char Timer0_Mode){
    TCCR0 &= ~((1<<WGM00)|(1<<WGM01)); // TCCR0 &= 0xB7;   OR   //TCCR0 &= ~FPWM;// Clear
    TCCR0 |= Timer0_Mode;
}

// Interrupt Enable
void Timer0_enableINT(char Timer0_INT){
    TIMSK |= Timer0_INT;
}
void Timer0_disableINT(char Timer0_INT){
    TIMSK &= ~Timer0_INT;
}


void init_Timer0(char Timer0_Mode, char _clock,char Timer0_INT){
    Timer0_selectMode(Timer0_Mode);
    Timer0_enableINT(Timer0_INT);
    Timer0_selectCLK(_clock);
}