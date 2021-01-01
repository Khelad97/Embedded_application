/* 
 * File:   mcal_interrupt_manager.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 2:57 PM
 */

#include "mcal_interrupt_manager.h"
#include "../timers/mcal_timer0.h"
#include "../timers/mcal_timer2.h"
void interrupt_priority_enable(void){
    RCONbits.IPEN = PRIORITY_ENABLE;
}

void interrupt_priority_disable(void){
    RCONbits.IPEN = PRIORITY_DISABLE;
}

void __interrupt() INTERRUPT_InterruptManagerHigh (void){
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR)){
        INT0_ISR();
    }
    else{}
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE) && (INTCONbits.TMR0IF == INTERRUPT_OCCUR)){
        TMR0_ISR();
    }
    else{}
    if((PIE1bits.TMR2IE == INTERRUPT_ENABLE) && (PIR1bits.TMR2IF == INTERRUPT_OCCUR)){
        TMR2_ISR();
    }
    else{}
    
}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow (void){
    if((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCUR)){
        INT1_ISR();
    }
    else{}
    
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCUR)){
        INT2_ISR();
    }
    else{}
}
