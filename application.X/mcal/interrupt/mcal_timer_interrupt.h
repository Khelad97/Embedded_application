/* 
 * File:   mcal_timer_interrupt.h
 * Author: Khelad Mohamed
 *
 * Created on December 25, 2020, 4:34 PM
 */

#ifndef MCAL_TIMER_INTERRUPT_H
#define	MCAL_TIMER_INTERRUPT_H

#include"mcal_interrupt_config.h"

#define TIMER0_INTERRUPT_ENABLE()     (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_DISABLE()    (INTCONbits.TMR0IE = 0)
#define TIMER0_INTERRUPT_FLAG_CLEAR() (INTCONbits.TMR0IF = 0)
/**
 * @PERIPHERAL_INTERRUPT_REQUEST
 TMR2IF: TMR2 to PR2 Match Interrupt Flag bit
             1 = TMR2 to PR2 match occurred (must be cleared by software)
             0 = No TMR2 to PR2 match occurred
 */
#define TIMER2_PERIPHERAL_FLAG_SET()       (PIR1bits.TMR2IF = 1)
#define TIMER2_PERIPHERAL_FLAG_CLEAR()     (PIR1bits.TMR2IF = 0)
/*
 * @PERIPHERAL_INTERRUPT_ENABLE
 * TMR2IE: TMR2 to PR2 Match Interrupt Enable bit
             1 = Enables the TMR2 to PR2 match interrupt
             0 = Disables the TMR2 to PR2 match interrupt
 */
#define TIMER2_PERIPHERAL_ENABLE()           (PIE1bits.TMR2IE = 1)
#define TIMER2_PERIPHERAL_DISABLE()          (PIE1bits.TMR2IE = 0)

/**
 * @PERIPHERAL _INTERRUPT_PRIORITY_REGISTER
 TMR2IP: TMR2 to PR2 Match Interrupt Priority bit
             1 = High priority
             0 = Low priority
 */
#define TIMER2_INTERRUPT_HIGH()              (IPR1bits.TMR2IP = 1)
#define TIMER2_INTERRUPT_LOW()               (IPR1bits.TMR2IP = 0)



#endif	/* MCAL_TIMER_INTERRUPT_H */

