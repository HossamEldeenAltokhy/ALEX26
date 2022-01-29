/* 
 * File:   mLCD_8bits.h
 * Author: hossa
 *
 * Created on January 29, 2022, 4:53 PM
 */

#ifndef MLCD_8BITS_H
#define	MLCD_8BITS_H


// Configuration 

#define LCD_DATA        PORTD
#define LCD_DATA_DIR    DDRD
#define LCD_CONTROL     PORTC
#define LCD_CONTROL_DIR DDRC

#define EN  4
#define RW  6
#define RS  2

void init_LCD();
void LCD_write(char data);
void LCD_cmd(char cmd);
void LCD_EN();
void LCD_CLEAR();
void LCD_str(char *);
void LCD_NUM(int num);

#endif	/* MLCD_8BITS_H */

