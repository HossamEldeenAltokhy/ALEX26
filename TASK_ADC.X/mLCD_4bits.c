#include <avr/io.h>
#define F_CPU 16000000UL
#include <stdlib.h>
#include <util/delay.h>
#include "mLCD_4bits.h"

void init_LCD_4bits(){
    
    // IO Configuration
    LCD_DATA_DIR |= 0xF0;
    LCD_CONTROL_DIR |= (1<<RS)|(1<<RW)|(1<<EN);
    
    LCD_CONTROL &= ~(1<<RW);
    _delay_ms(50);
    
    LCD_CLEAR_4bits();  // Clear
    LCD_cmd_4bits(0x02);// 8-bit Function 
    LCD_cmd_4bits(0x0C);// Display ON, Curser OFF
    LCD_cmd_4bits(0x06);// Entry mode
    
    _delay_ms(200);
}

void LCD_EN_4bits(){
    LCD_CONTROL |= (1<<EN);
    _delay_ms(5);
    LCD_CONTROL &= ~(1<<EN);
}
void LCD_write_4bits(char data){
    LCD_CONTROL |= (1<<RS);
    LCD_DATA = (LCD_DATA & 0x0F)|(data & 0xF0);
    LCD_EN_4bits();
    
    LCD_DATA = (LCD_DATA & 0x0F)|(data << 4);
    LCD_EN_4bits();
}

void LCD_cmd_4bits(char cmd){
    LCD_CONTROL &= ~(1<<RS); // choose command Register
    LCD_DATA = (LCD_DATA & 0x0F)|(cmd & 0xF0);
    LCD_EN_4bits();
    
    LCD_DATA = (LCD_DATA & 0x0F)|(cmd << 4);
    LCD_EN_4bits();
    
    
}

void LCD_CLEAR_4bits(){
    LCD_cmd_4bits(0x01);
}

void LCD_str_4bits(char *str){
    for(int i = 0 ; str[i]!='\0'; i++){
        LCD_write_4bits(str[i]);
    }
}

void LCD_NUM_4bits(int num){
    char buffer[11];
    itoa(num , buffer , 10);
    LCD_str_4bits(buffer);
}

