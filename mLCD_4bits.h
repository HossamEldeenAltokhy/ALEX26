/* 
 * File:   mLCD_4bits.h
 * Author: hossa
 *
 * Created on February 4, 2022, 2:00 PM
 */

#ifndef MLCD_4BITS_H
#define	MLCD_4BITS_H

// Configuration 

#define LCD_DATA        PORTA
#define LCD_DATA_DIR    DDRA
#define LCD_CONTROL     PORTB
#define LCD_CONTROL_DIR DDRB

#define EN  3
#define RW  2
#define RS  1

void init_LCD_4bits();
void LCD_write_4bits(char data);
void LCD_cmd_4bits(char cmd);
void LCD_EN_4bits();
void LCD_CLEAR_4bits();
void LCD_str_4bits(char *);
void LCD_NUM_4bits(int num);


#endif	/* MLCD_4BITS_H */

