/* 
 * File:   mUART.h
 * Author: hossa
 *
 * Created on February 19, 2022, 5:34 PM
 */

#ifndef MUART_H
#define	MUART_H

void init_UART(int BaudRate);
void UART_send(char data);
char UART_read(void);

#endif	/* MUART_H */

