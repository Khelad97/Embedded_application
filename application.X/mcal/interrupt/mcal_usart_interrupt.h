/* 
 * File:   mcal_usart_interrupt.h
 * Author: Ahmed.Elghafar
 *
 * Created on February 5, 2021, 5:43 PM
 */

#ifndef MCAL_USART_INTERRUPT_H
#define	MCAL_USART_INTERRUPT_H

#include "mcal_interrupt_config.h"

#define INT_ENABLE  1
#define INT_DISABLE 0
#define FLAG_CLEARED   0

typedef enum{
    USART_INT_TX_ENABLE = 0,
    USART_INT_TX_DISABLE,
    USART_INT_RX_ENABLE,
    USART_INT_RX_DISABLE
}usart_int_t;

void usart_interrupt_enable(usart_int_t state);
void usart_clear_tx_interrupt_flag(void);
void usart_clear_rx_interrupt_flag(void);

void EUSART_Transmit_ISR(void);
void EUSART_Receive_ISR(void);

#endif	/* MCAL_USART_INTERRUPT_H */

