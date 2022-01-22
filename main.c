#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED0   2
#define LED1   7
#define LED2   3


void init_LEDs(void);

void LED_ON(int LED);
void LED_OFF(int LED);

int main(void) {
    
    init_LEDs();
    
    while (1) {
        LED_ON(LED1);
        _delay_ms(500);
        LED_OFF(LED1);
        _delay_ms(500);
    }
}
void init_LEDs(void){
    DDRC |= (1<<LED0)|(1<<LED1);
    DDRD |= (1<<LED2);
}

void LED_ON(int LED){
    if(LED == LED2){
        PORTD |= (1<<LED);
    }else{
        PORTC |= (1<<LED);
    }
    
}

void LED_OFF(int LED){
    if(LED == LED2){
        PORTD &= ~(1<<LED);
    }else{
        PORTC &= ~(1<<LED);
    }
}
