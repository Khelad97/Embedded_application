
/* 
 * File:   mcal_timer.h
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */

#ifndef MCAL_TIMER0_H
#define	MCAL_TIMER0_H

#include <pic18f46k20.h>
#include "../../std_types.h"
#include "../interrupt/mcal_timer_interrupt.h"


/*Timer0 On/Off Control bit*/
#define TIMER0_START()             (T0CONbits.TMR0ON=1)
#define TIMER0_STOP()              (T0CONbits.TMR0ON=0)


/*Timer0 8-bit/16-bit Control bit*/
#define TIMER0_8BIT_MODE  1
#define TIMER0_16BIT_MODE 0
#define TIMER0_8BIT()             (T0CONbits.T08BIT=1)
#define TIMER0_16BIT()            (T0CONbits.T08BIT=0)


/*Timer0 Clock Source Select bit*/
#define TIMER0_TIMER_MODE  1
#define TIMER0_COUNTER_MODE 0
#define TIMER0_EXTERNAL_CLOCK()   (T0CONbits.T0CS=1)
#define TIMER0_INTERNAL_CLOCK()   (T0CONbits.T0CS=0)


/*Timer0 Source Edge Select bit*/
#define TIMER0_FALING_MODE 1
#define TIMER0_RISING_MODE 0
#define TIMER0_EDGE_HIGH_TO_LOW() (T0CONbits.T0SE=1)
#define TIMER0_EDGE_LOW_TO_HIGH() (T0CONbits.T0SE=0)


/*Timer0 interrupt Assignment bit*/
#define TIMER0_INTERRUPT_EN  1
#define TIMER0_INTERRUPT_DIS 0


/*Timer0 Prescaler Assignment bit*/
#define TIMER0_PRESCALER_ON_MODE  1
#define TIMER0_PRESCALER_OFF_MODE 0
#define TIMER0_PRESCALER_ON()     (T0CONbits.PSA=0)
#define TIMER0_PRESCALER_OFF()    (T0CONbits.PSA=1)

/* Timer0 Prescaler Select bits*/
#define TIMER0_PRESCALER_DIV_BY_2      0U
#define TIMER0_PRESCALER_DIV_BY_4      1U
#define TIMER0_PRESCALER_DIV_BY_8      2U
#define TIMER0_PRESCALER_DIV_BY_16     3U
#define TIMER0_PRESCALER_DIV_BY_32     4U
#define TIMER0_PRESCALER_DIV_BY_64     5U
#define TIMER0_PRESCALER_DIV_BY_128    6U
#define TIMER0_PRESCALER_DIV_BY_256    7U

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
} timer0_t;


ret_status timer0_initilize(const timer0_t *timer0);
ret_status timer0_read_timer(uint16_t *timer_value);
ret_status timer0_write_timer(uint16_t timer_val);

void TMR0_ISR(void);
void TMR0_callBack(void);


#endif	/* MCAL_TIMER0_H */