/* 
 * @File:   mcal_timer3.h
 * @Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */

#include "mcal_timer3.h"

static void (*TMR3_InterruptHandler)(void) = NULL;
volatile static uint16_t timer3_preload;

static inline void timer3_select_mode(const timer3_t *timer) {
    if (timer->timer_register_mode == TIMER3_16_BIT_OPERATION_MODE) {
        TIMER3_16_BIT_OPERATION();
    } else {
        TIMER3_8_BIT_OPERATION();
    }
}

static inline void timer3_clock_sorce(const timer3_t *timer) {
    if (timer->clock_sorce == TIMER3_16_BIT_OPERATION_MODE) {
        TIMER3_EXTERNAL_CLOCK_SORCE();
        gpio_pin_direction_intialize(PORTC_INDEX, PIN0, DIRECTION_INPUT);
        if (timer->Synchronize_external_clk == TIMER3_NOT_SYNCHRINIZE_EXTERNAL_CLK_MODE) {
            TIMER3_NOT_SYNCHRINIZE_EXTERNAL_CLK();
        } else {
            TIMER3_SYNCHRINIZE_EXTERNAL_CLK();
        }
    } else {
        TIMER3_INTERNAL_CLOCK_SORCE();
    }
}

/*T3CCP<2:1>: Timer3 and Timer1 to CCPx Enable bits*/
static inline void timer3_CCPx_mode(const timer3_t *timer) {
    switch (timer->timer3_and_timer1_ccpx) {
        case (TIMER1_CCP1_AND_CP2):
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 0;
            break;
        case (TIMER3_CCP2_AND_TIMER1_CCP1):
            T3CONbits.T3CCP1 = 1;
            T3CONbits.T3CCP2 = 0;
            break;
        case (TIMER3_CCP1_AND_CP2):
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 1;
            break;
        default:;
    }
}

static inline void timer3_Interrupt(const timer3_t *timer) {
    if (timer->timer_interrupt_mode == TIMER3_INTERRUPT_ENABLE_MODE) {
        TMR3_InterruptHandler = timer->timer_interrupt_mode;
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PERIPHERAL_INTERRUPT();
        TIMER3_INTERRUPT_FLAG_CLEAR();
        TIMER3_INTERRUPT_ENABLE();
    } else {
        TIMER3_INTERRUPT_DISABLE();
        TMR3_InterruptHandler = NULL;
    }
}

ret_status timer3_initialize(const timer3_t *timer) {
    TIMER3_DISENABLE();
    timer3_select_mode(timer);
    timer3_clock_sorce(timer);
    timer3_CCPx_mode(timer);
    timer3_Interrupt(timer);
    /* Update Timer Pre-load Value*/
    timer3_write_timer(timer->timer_preload_value);
    timer3_preload = timer->timer_preload_value;
    TIMER3_ENABLE();
}

ret_status timer3_read_timer(uint16_t *timer_value) {
    ret_status ret = R_OK;
    uint8_t read_tmr3l = TIMER3_REGISTER_8BIT_CLEAR, read_tmr3h = TIMER3_REGISTER_8BIT_CLEAR;
    read_tmr3l = TMR3L;
    read_tmr3h = TMR3H;
    *timer_value = ((uint16_t) (read_tmr3h << 8)) + read_tmr3l;
    return ret;
}

ret_status timer3_write_timer(uint16_t timer_value) {

    ret_status ret = R_OK;
    TMR3H = timer_value >> 8;
    TMR3L = (uint8_t) timer_value;
    return ret;
}

void TMR3_ISR(void) {
    TIMER3_INTERRUPT_FLAG_CLEAR();
    TMR3H = timer3_preload >> 8;
    TMR3L = (uint8_t)timer3_preload;
    TMR3_CallBack();
}

void TMR3_CallBack(void) {
    if (TMR3_InterruptHandler) {
        TMR3_InterruptHandler();
    } else {
    }
}


