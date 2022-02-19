#define F_CPU 16000000UL
#include <avr/io.h>
#include "mUART.h"

#define BR_9600   9600
#define BR_2400   2400
#define BR_9600   9600
#define BR_9600   9600


void init_UART(int BaudRate){
    
    
    //ACCESS UCSRB 
    // Enable RX , TX
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    // Setting BaudRate
    short UBRR = (F_CPU/16.0/BaudRate)-1;
    UBRRL = (char) UBRR;
    UBRRH = (char) (UBRR>>8);
    
    
    //UBRRL = 103; for 9600bps at 16Mhz
    
}
void UART_send(char data){
    // Booling
    // Waiting for UDR to be Empty
    while(!(UCSRA & (1<<UDRE)));
    // Now UDR is Empty and ready to be written.
    UDR = data;
    
}
char UART_read(void){
    // Booling 
    // Waiting till Receiving is completed
    while(!(UCSRA & (1<<RXC)));
    char data  = UDR;
    return data;
}
