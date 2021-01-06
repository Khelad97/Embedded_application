/* 
 * File:   mcal_timer_interrupt.h
 * Author: Khelad Mohamed
 *
 * Created on December 25, 2020, 4:34 PM
 */

#ifndef MCAL_TIMER_INTERRUPT_H
#define	MCAL_TIMER_INTERRUPT_H

#include"mcal_interrupt_config.h"

#define TIMER0_INTERRUPT_ENABLE()       (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_DISABLE()      (INTCONbits.TMR0IE = 0)
#define TIMER0_INTERRUPT_FLAG_CLEAR()   (INTCONbits.TMR0IF = 0)

#define TIMER1_INTERRUPT_ENABLE()            (PIE1bits.TMR1IE = 1)
#define TIMER1_INTERRUPT_DISABLE()           (PIE1bits.TMR1IE = 0)
#define TIMER1_INTERRUPT_FLAG_CLEAR()        (PIR1bits.TMR1IF = 0)

#define TIMER2_INTERRUPT_ENABLE()           (PIE1bits.TMR2IE = 1)
#define TIMER2_INTERRUPT_DISABLE()          (PIE1bits.TMR2IE = 0)
#define TIMER2_INTERRUPT_FLAG_CLEAR()       (PIR1bits.TMR2IF = 0)

#define TIMER3_INTERRUPT_ENABLE()           (PIE2bits.TMR3IE = 1)
#define TIMER3_INTERRUPT_DISABLE()          (PIE2bits.TMR3IE = 0)
#define TIMER3_INTERRUPT_FLAG_CLEAR()       (PIR2bits.TMR3IF = 0)


void TMR0_ISR(void);
void TMR1_ISR(void);
void TMR2_ISR(void);
void TMR3_ISR(void);
#endif	/* MCAL_TIMER_INTERRUPT_H */

