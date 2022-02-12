

#include <avr/io.h>
#include "mADC.h"






void ADC_selectRef(char Voltage_REF){
    switch(Voltage_REF){
        case AREF:
            ADMUX &= ~((1<<REFS1)|(1<<REFS0));
            break;
            
        case AVCC:
            ADMUX &= ~(1<<REFS1);
            ADMUX |= (1<<REFS0);
            break;
            
        case INTERNAL:
            ADMUX |= ((1<<REFS1)|(1<<REFS0));
            break;
            
    }
}

void ADC_selectCH(char CH_Num){
    ADMUX &= 0xE0;   //11100000
    ADMUX |= CH_Num;
}

void ADC_selectPRE(char PRE){
    ADCSRA &= 0xF8; // 11111000
    ADCSRA |= PRE & 0x07; // 00000111
}
void ADC_enable(){
    ADCSRA |= (1<<ADEN);
}

// Start Conversion
void ADC_SC(){
    ADCSRA |= (1<<ADSC);
}


void ADC_INT_enable(){
    ADCSRA |= (1<<ADIE);
}

void ADC_INT_disable(){
    ADCSRA &= ~(1<<ADIE);
}
void ADC_wait(){
//    Booling on ADIF
    while(!(ADCSRA & (1<<ADIF)));
}

int ADC_read(){
    return ADCW;
}


void init_ADC(char CH_Num,char Voltage_REF, char PRE, char chooseBooling ){
    ADC_selectCH(CH_Num);
    ADC_selectRef(Voltage_REF);
    ADC_selectPRE(PRE);
    
//    Booling Or INTERRUPT
    chooseBooling? ADC_INT_disable():ADC_INT_enable();
    ADC_enable();
}