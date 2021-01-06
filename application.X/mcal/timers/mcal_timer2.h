
/* 
 * File:   mcal_timer2.h
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */

#ifndef MCAL_TIMER2_H
#define	MCAL_TIMER2_H

#include <pic18f46k20.h>
#include "../../std_types.h"
#include "../interrupt/mcal_timer_interrupt.h"


/*Timer0 On/Off Control bit*/
#define TIMER2_ON_MODE  1
#define TIMER2_OFF_MODE 0
#define TIMER2_START()  (T2CONbits.TMR2ON = 1)
#define TIMER2_STOP()   (T2CONbits.TMR2ON = 0)

/* Timer2 Output Post-scale Select bits*/
#define TIMER2_OUT_POSTSCALER_BIT0(val)  (T2CONbits.T2OUTPS0 = val)
#define TIMER2_OUT_POSTSCALER_BIT1(val)  (T2CONbits.T2OUTPS1 = val)
#define TIMER2_OUT_POSTSCALER_BIT2(val)  (T2CONbits.T2OUTPS2 = val)
#define TIMER2_OUT_POSTSCALER_BIT3(val)  (T2CONbits.T2OUTPS3 = val)

/* Timer2 Output Post-scale Values */
#define TIMER2_POSTSCALER_VALUE_DIV_BY1   0U
#define TIMER2_POSTSCALER_VALUE_DIV_BY2   1U
#define TIMER2_POSTSCALER_VALUE_DIV_BY3   2U
#define TIMER2_POSTSCALER_VALUE_DIV_BY4   3U
#define TIMER2_POSTSCALER_VALUE_DIV_BY5   4U
#define TIMER2_POSTSCALER_VALUE_DIV_BY6   5U
#define TIMER2_POSTSCALER_VALUE_DIV_BY7   6U
#define TIMER2_POSTSCALER_VALUE_DIV_BY8   7U
#define TIMER2_POSTSCALER_VALUE_DIV_BY9   8U
#define TIMER2_POSTSCALER_VALUE_DIV_BY10  9U
#define TIMER2_POSTSCALER_VALUE_DIV_BY11 10U
#define TIMER2_POSTSCALER_VALUE_DIV_BY12 11U
#define TIMER2_POSTSCALER_VALUE_DIV_BY13 12U
#define TIMER2_POSTSCALER_VALUE_DIV_BY14 13U
#define TIMER2_POSTSCALER_VALUE_DIV_BY15 14U
#define TIMER2_POSTSCALER_VALUE_DIV_BY16 15U

/*Timer2 Clock Pre-scale Select bits*/
#define TIMER2_CLK_PRESCALER_BIT0()  (T2CONbits.T2CKPS0 = 0)
#define TIMER2_CLK_PRESCALER_BIT1()  (T2CONbits.T2CKPS1 = 0)

/*Timer2 Clock Pre-scale values */
#define TIMER2_PRESCALER_VALUE_1  0U
#define TIMER2_PRESCALER_VALUE_4  1U
#define TIMER2_PRESCALER_VALUE_16 2U

/*Timer2 interrupt Assignment bit*/
#define TIMER2_INTERRUPT_EN  1
#define TIMER2_INTERRUPT_DIS 0


#define TIMER2_REGISTER_CLEAR  ((uint8_t )0U)

typedef struct {
    uint8_t timer_interrupt_mode   : 1;
    uint8_t timer_prescaler_value  : 2;
    uint8_t timer_postscaler_value : 4;
    uint8_t                        : 1;
    uint8_t timer_preload_value;
    void(* TMR2_InterruptHandler)(void);
} timer2_t;

ret_status timer2_initilize(const timer2_t *timer0);
ret_status timer2_read_timer(uint8_t *timer_value);
ret_status timer2_write_timer(uint8_t timer_val);

void TMR2_ISR(void);
void TMR2_callBack(void);


#endif	/* MCAL_TIMER2_H */
