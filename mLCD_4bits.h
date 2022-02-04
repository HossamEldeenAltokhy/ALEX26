/* 
 * File:   mLCD_4bits.h
 * Author: hossa
 *
 * Created on February 4, 2022, 2:00 PM
 */

#ifndef MLCD_4BITS_H
#define	MLCD_4BITS_H

// Configuration 

#define LCD_DATA        PORTD
#define LCD_DATA_DIR    DDRD
#define LCD_CONTROL     PORTD
#define LCD_CONTROL_DIR DDRD

#define EN  2
#define RW  1
#define RS  0

void init_LCD_4bits();
void LCD_write_4bits(char data);
void LCD_cmd_4bits(char cmd);
void LCD_EN_4bits();
void LCD_CLEAR_4bits();
void LCD_str_4bits(char *);
void LCD_NUM_4bits(int num);


#endif	/* MLCD_4BITS_H */

