/* 
 * File:   mcal_timer.h
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */


#ifndef MCAL_TIMER1_H
#define	MCAL_TIMER1_H

#include <pic18f46k20.h>
#include "../../std_types.h"
#include "../interrupt/mcal_timer_interrupt.h"

/* Timer1 On/Off Control */
#define TIMER1_START()           (T1CONbits.TMR1ON = 1)
#define TIMER1_STOP()            (T1CONbits.TMR1ON = 0)

/*  Timer1 Clock Source Select */
#define TIMER1_TIMER_MODE   1
#define TIMER1_COUNTER_MODE 0
#define TIMER1_EXTERNAL_CLOCK_SOURCE()      (T1CONbits.TMR1CS = 1)
#define TIMER1_INTERNAL_CLOCK_SOURCE()      (T1CONbits.TMR1CS = 0)

/* Timer1 Oscillator Enable */
#define TIMER1_OSCILLATOR_MODE  1
#define TIMER1_OSCILLATOR_ENABLE()       (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSCILLATOR_DISABLE()      (T1CONbits.T1OSCEN = 0)

/* Timer1 Pre-scaler Select  */
#define TIMER1_PRESCALER_DIV_BY_1     0U
#define TIMER1_PRESCALER_DIV_BY_2     1U
#define TIMER1_PRESCALER_DIV_BY_4     2U
#define TIMER1_PRESCALER_DIV_BY_8     3U

/* Timer1 Interrupt Control*/
#define TIMER1_INTERRUPT_ENABLE_MODE     1
#define TIMER1_INTERRUPT_DISABLE_MODE    0

/* 16-Bit Read/Write Mode */
#define TIMER1_ONE_16BIT_OPERATION 1
#define TIMER1_TWO_08BIT_OPERATION 0
#define TIMER1_ONE_16BIT_OPERATION_ENABLE() (T1CONbits.RD16 = 1)
#define TIMER1_TWO_08BIT_OPERATION_ENABLE() (T1CONbits.RD16 = 0)

#define TIMER1_REGISTER_CLEAR ((uint16_t)0U)
#define TIMER1_REGISTER_8BIT_CLEAR ((uint8_t)0U)

typedef struct {
    uint8_t timer_register_mode : 1;
    uint8_t timer_counter_mode : 1;
    uint8_t timer_interrupt_mode : 1;
    uint8_t timer_prescaler_value : 2;
    uint8_t reserved : 3;
    uint16_t timer_preload_value;
    void (* TMR1_InterruptHandler)(void);
} timer1_t;

ret_status timer1_initialize(const timer1_t *timer_obj);
ret_status timer1_read_timer(uint16_t *timer_value);
ret_status timer1_write_timer(uint16_t timer_value);

void TMR1_ISR(void);
void TMR1_CallBack(void);

#endif	/* MCAL_TIMER1_H */

