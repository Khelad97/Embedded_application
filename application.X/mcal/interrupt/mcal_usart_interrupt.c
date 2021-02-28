/* 
 * File:   mcal_usart_interrupt.c
 * Author: Ahmed.Elghafar
 *
 * Created on February 5, 2021, 5:43 PM
 */

#include "mcal_usart_interrupt.h"

void usart_interrupt_enable(usart_int_t state){
    switch(state){
        case USART_INT_TX_ENABLE  : PIE1bits.TX1IE = INT_ENABLE;  break;
        case USART_INT_TX_DISABLE : PIE1bits.TX1IE = INT_DISABLE; break;
        case USART_INT_RX_ENABLE  : PIE1bits.RC1IE = INT_ENABLE;  break;
        case USART_INT_RX_DISABLE : PIE1bits.RC1IE = INT_DISABLE; break;
        default : ;
    }
}

void usart_clear_tx_interrupt_flag(void){
    PIR1bits.TX1IF = FLAG_CLEARED;
}

void usart_clear_rx_interrupt_flag(void){
    PIR1bits.RC1IF = FLAG_CLEARED;
}