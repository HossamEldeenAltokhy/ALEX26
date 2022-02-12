#include <avr/io.h>
#define F_CPU 16000000UL
#include <stdlib.h>
#include <util/delay.h>
#include "mLCD_8bits.h"

void init_LCD(){
    
    // IO Configuration
    LCD_DATA_DIR = 0xFF;
    LCD_CONTROL_DIR |= (1<<RS)|(1<<RW)|(1<<EN);
    
    LCD_CONTROL &= ~(1<<RW);
    _delay_ms(50);
    
    LCD_CLEAR();  // Clear
    LCD_cmd(0x38);// Function 
    LCD_cmd(0x0C);// Display ON, Curser OFF
    LCD_cmd(0x06);// Entry mode
    
    _delay_ms(100);
}

void LCD_EN(){
    LCD_CONTROL |= (1<<EN);
    _delay_ms(5);
    LCD_CONTROL &= ~(1<<EN);
}
void LCD_write(char data){
    LCD_CONTROL |= (1<<RS);
    LCD_DATA = data;
    LCD_EN();
}

void LCD_cmd(char cmd){
    LCD_CONTROL &= ~(1<<RS);
    LCD_DATA = cmd;
    LCD_EN();
}

void LCD_CLEAR(){
    LCD_cmd(0x01);
}

void LCD_str(char *str){
    for(int i = 0 ; str[i]!='\0'; i++){
        LCD_write(str[i]);
    }
}

void LCD_NUM(int num){
    char buffer[11];
    itoa(num , buffer , 10);
    LCD_str(buffer);
}
