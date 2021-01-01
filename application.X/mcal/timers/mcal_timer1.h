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


/*Timer0 On/Off Control bit*/

/*Timer0 8-bit/16-bit Control bit*/
#define TIMER0_8BIT_MODE  1
#define TIMER0_16BIT_MODE 0

/*Timer0 Clock Source Select bit*/
#define TIMER0_TIMER_MODE  1
#define TIMER0_COUNTER_MODE 0

/*Timer0 Source Edge Select bit*/
#define TIMER0_FALING_MODE 1
#define TIMER0_RISING_MODE 0

/*Timer0 interrupt Assignment bit*/
#define TIMER0_INTERRUPT_EN  1
#define TIMER0_INTERRUPT_DIS 0

/*Timer0 oscillator enable*/
#define TIMER0_PRESCALER_ON_MODE  1


/* Timer0 Prescaler Select bits*/
#define TIMER1_PRESCALER_DIV_BY_1      0U
#define TIMER1_PRESCALER_DIV_BY_2      1U
#define TIMER1_PRESCALER_DIV_BY_4      2U
#define TIMER1_PRESCALER_DIV_BY_8      3U

/* 16-bit Read/Write Mode Enable bit*/
#define TIMER1_ONE_16BIT_OPERATION_MODE  1
#define TIMER1_ONE_8BIT_OPERATION_MODE   0
#define TIMER1_ONE_16BIT_OPERATION_EN()   (T1CONbits.RD16=1)
#define TIMER1_TWO_08BIT_OPERATION_EN()    (T1CONbits.RD16=0)

/* Timer1 System Clock Status bit */
/*Timer1 oscillator*/
#define TIMER1_CLOCK_OSCILLATOR()   (T1CONbits.T1RUN=1)
#define TIMER1_CLOCK_OSCILLATOR()   (T1CONbits.T1RUN=1)

#define TIMER_REGISTER_CLEAR       ((uint16_t)0U)
#define TIMER_REGISTER_8BIT_CLEAR  ((uint8_t )0U)

typedef struct {
    uint8_t timer_register_mode : 1;
    uint8_t timer_mode : 1;
    uint8_t timer_prescaler_mode : 1;
    uint8_t timer_interrupt_mode : 1;
    uint8_t timer_current_edge_mode : 1;
    uint8_t timer_prescaler_value : 3;
    uint16_t timer_preload_value;
    void(* TMR0_InterruptHandler)(void);
} timer1_t;


ret_status timer1_initilize(const timer1_t *timer1);
ret_status timer1_read_timer(uint16_t *timer_value);
ret_status timer1_write_timer(uint16_t timer_val);

void TMR1_ISR(void);
void TMR1_callBack(void);


#endif	/* MCAL_TIMER1_H */