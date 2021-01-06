/* 
 * @File:   mcal_timer3.h
 * @Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */

#ifndef MCAL_TIMER3_H
#define	MCAL_TIMER3_H

#include <pic18f46k20.h>
#include "../../std_types.h"
#include "../interrupt/mcal_timer_interrupt.h"


/*TMR3ON: Timer3 On bit*/
#define TIMER3_ENABLE()     (T3CONbits.TMR3ON=1)
#define TIMER3_DISENABLE()  (T3CONbits.TMR3ON=0)

/*RD16: 16-bit Read/Write Mode Enable bit*/
#define TIMER3_16_BIT_OPERATION_MODE 1
#define TIMER3_8_BIT_OPERATION_MODE 1
#define TIMER3_16_BIT_OPERATION()     (T3CONbits.RD16=1)
#define TIMER3_8_BIT_OPERATION()      (T3CONbits.RD16=0)

/*T3CCP<2:1>: Timer3 and Timer1 to CCPx Enable bits*/
#define TIMER3_CCP1_AND_CP2 2U
#define TIMER3_CCP2_AND_TIMER1_CCP1 1U
#define TIMER1_CCP1_AND_CP2 0U

/*T3CKPS<1:0>: Timer3 Input Clock Pre-scale Select bits*/
#define TIMER3_PRESCALER_DIV_BY_1      0U
#define TIMER3_PRESCALER_DIV_BY_2      1U
#define TIMER3_PRESCALER_DIV_BY_4      2U
#define TIMER3_PRESCALER_DIV_BY_8      3U

/*T3SYNC: Timer3 External Clock Input Synchronization Control bit
(Not usable if the device clock comes from Timer1/Timer3.)
 When TMR3CS = 1:
1 = Do not synchronize external clock input
0 = Synchronize external clock input
When TMR3CS = 0:
This bit is ignored. Timer3 uses the internal clock when TMR3CS = 0.*/
#define TIMER3_NOT_SYNCHRINIZE_EXTERNAL_CLK_MODE 1
#define TIMER3_SYNCHRINIZE_EXTERNAL_CLK_MODE     0
#define TIMER3_NOT_SYNCHRINIZE_EXTERNAL_CLK()(T3CONbits.T3SYNC=1)
#define TIMER3_SYNCHRINIZE_EXTERNAL_CLK()    (T3CONbits.T3SYNC=0)


/*TMR3CS: Timer3 Clock Source Select bit*/
#define TIMER3_EXTERNAL_CLOCK_SORCE_MODE 1
#define TIMER3_INTERNAL_CLOCK_SORCE_MODE 0
#define TIMER3_EXTERNAL_CLOCK_SORCE()    (T3CONbits.TMR3CS=1)
#define TIMER3_INTERNAL_CLOCK_SORCE()    (T3CONbits.TMR3CS=0)

#define TIMER3_REGISTER_CLEAR ((uint16_t)0U)
#define TIMER3_REGISTER_8BIT_CLEAR ((uint8_t)0U)

/* Timer3 Interrupt Control*/
#define TIMER3_INTERRUPT_ENABLE_MODE     1
#define TIMER3_INTERRUPT_DISABLE_MODE    0

#define TIMER3_REGISTER_CLEAR ((uint16_t)0U)
#define TIMER3_REGISTER_8BIT_CLEAR ((uint8_t)0U)


typedef struct {
    uint8_t preScaler_value          :2;
    uint8_t clock_sorce              :1;
    uint8_t timer_register_mode      :1;
    uint8_t timer_interrupt_mode     :1;
    uint8_t Synchronize_external_clk :1;
    uint8_t timer3_and_timer1_ccpx   :2;
    uint16_t timer_preload_value;
    void(* TMR3_InterruptHandler)(void);
} timer3_t;

ret_status timer3_initialize(const timer3_t *timer_obj);
ret_status timer3_read_timer(uint16_t *timer_value);
ret_status timer3_write_timer(uint16_t timer_value);

void TMR3_ISR(void);
void TMR3_CallBack(void);

#endif	/* MCAL_TIMER3_H */