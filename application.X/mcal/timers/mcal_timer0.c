
/* 
 * @File:   mcal_timer.h
 * @Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */

#include "mcal_timer0.h"

static void (*TMR0_InterruptHandler)(void) = NULL;
volatile static uint16_t timer0_preload;

/**
 * 
 * @param timer
 * @return 
 */
ret_status timer0_initilize(const timer0_t *timer) {
    ret_status ret = R_OK;
    /*stop timer*/
    TIMER0_STOP();
    /** check on register_mode*/
    if (timer->timer_register_mode == TIMER0_8BIT_MODE) {
        TIMER0_8BIT();
    } else {
        TIMER0_16BIT();
    }
    /** check on source_mode*/
    if (timer->timer_mode == TIMER0_TIMER_MODE) {
        TIMER0_INTERNAL_CLOCK();
    } else {
        TIMER0_EXTERNAL_CLOCK();
        if (timer->timer_current_edge_mode == TIMER0_FALING_MODE) {
            TIMER0_EDGE_HIGH_TO_LOW();
        } else {
            TIMER0_EDGE_LOW_TO_HIGH();
        }

    }
    /** check on Prescaler_mode */
    if (timer->timer_prescaler_mode == TIMER0_PRESCALER_ON_MODE) {
        TIMER0_PRESCALER_ON();
        T0CONbits.T0PS = timer->timer_prescaler_value;
    } else {
        TIMER0_PRESCALER_OFF();
    }

    /** check on timer_interrupt_mode */
    if (timer->timer_interrupt_mode == TIMER0_INTERRUPT_EN) {
        TMR0_InterruptHandler = timer->TMR0_InterruptHandler;
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PERIPHERAL_INTERRUPT();
        TIMER0_INTERRUPT_FLAG_CLEAR();
        TIMER0_INTERRUPT_ENABLE();
    } else {
        TIMER0_INTERRUPT_DISABLE();
        TMR0_InterruptHandler = NULL;
    }
    /* uploaded timer preloaded value */
    timer0_write_timer(timer->timer_preload_value);
    timer0_preload = timer->timer_preload_value;
    /* start timer0*/
    TIMER0_START();
    return ret;
}

/**
 * 
 * @param timer_value
 * @return 
 */
ret_status timer0_read_timer(uint16_t *timer_value) {
    ret_status ret = R_OK;
    uint8_t read_tmr0l = TIMER_REGISTER_8BIT_CLEAR;
    uint8_t read_tmr0h = TIMER_REGISTER_8BIT_CLEAR;
    read_tmr0l = TMR0L;
    read_tmr0h = TMR0H;
    *timer_value = ((uint16_t) (read_tmr0h << 8)) + read_tmr0l;
    return ret;
}

/**
 * 
 * @param timer_value
 * @return 
 */
ret_status timer0_write_timer(uint16_t timer_val) {
    ret_status ret = R_OK;
    TMR0H = timer_val >> 8;
    TMR0L = (uint8_t) timer_val;
    return ret;
}

void TMR0_ISR(void) {
    TIMER0_INTERRUPT_FLAG_CLEAR();
    timer0_write_timer(timer0_preload);
    TMR0_callBack();
}

void TMR0_callBack(void) {
    if (TMR0_InterruptHandler) {
        TMR0_InterruptHandler();
    } else {
    }
}
