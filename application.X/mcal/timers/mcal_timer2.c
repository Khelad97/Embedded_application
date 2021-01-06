

#include "mcal_timer2.h"

static void (*TMR2_InterruptHandler)(void) = NULL;
volatile static uint8_t timer2_preload;

static inline void timer_prescaler_value(const timer2_t *timer2) {
    switch (timer2->timer_prescaler_value) {
        case TIMER2_PRESCALER_VALUE_1:
            T2CONbits.T2CKPS0 = 0;
            T2CONbits.T2CKPS0 = 0;
            break;
        case TIMER2_PRESCALER_VALUE_4:
            T2CONbits.T2CKPS0 = 1;
            T2CONbits.T2CKPS0 = 0;
            break;
        case TIMER2_PRESCALER_VALUE_16:
            T2CONbits.T2CKPS0 = 0;
            T2CONbits.T2CKPS0 = 1;
            break;
        default:;
    }
}

static inline void timer_postscaler_value(const timer2_t *timer2) {
    timer2_preload = timer2->timer_postscaler_value;
    uint8_t val;
    /*TIMER2_OUT_POSTSCALER_BIT0*/
    val = timer2_preload % 2;
    TIMER2_OUT_POSTSCALER_BIT0(val);
    timer2_preload = timer2_preload / 2;

    /*TIMER2_OUT_POSTSCALER_BIT1*/
    val = timer2_preload % 2;
    TIMER2_OUT_POSTSCALER_BIT1(val);
    timer2_preload = timer2_preload / 2;

    /*TIMER2_OUT_POSTSCALER_BIT2*/
    val = timer2_preload % 2;
    TIMER2_OUT_POSTSCALER_BIT2(val);
    timer2_preload = timer2_preload / 2;

    /*TIMER2_OUT_POSTSCALER_BIT3*/
    val = timer2_preload % 2;
    TIMER2_OUT_POSTSCALER_BIT3(val);
    timer2_preload = timer2_preload / 2;
}

/** check on timer_interrupt_mode */
static inline void timer_interrupt_mode(const timer2_t *timer2) {
    if (timer2->timer_interrupt_mode == TIMER2_INTERRUPT_EN) {
        TMR2_InterruptHandler = timer2->TMR2_InterruptHandler;
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PERIPHERAL_INTERRUPT();
        TIMER2_INTERRUPT_FLAG_CLEAR();
        TIMER2_INTERRUPT_ENABLE();
    } else {
        TIMER2_INTERRUPT_DISABLE();
        TMR2_InterruptHandler = NULL;
    }
}

/**
 * 
 * @param timer0
 * @return 
 */
ret_status timer2_initilize(const timer2_t *timer2) {
    ret_status ret = R_NOK;
    if (timer2 == NULL) {
        return ret;
    } else {
        timer_prescaler_value(timer2);
        timer_postscaler_value(timer2);
        timer_interrupt_mode(timer2);
        timer2_preload = timer2->timer_preload_value;
        ret = R_OK;
    }
    return ret;
}

/**
 * 
 * @param timer_value
 * @return 
 */
ret_status timer2_read_timer(uint8_t *timer_value) {

    ret_status ret = R_OK;
    *timer_value = PR2;
    return ret;
}

/**
 * 
 * @param timer_val
 * @return 
 */
ret_status timer2_write_timer(uint8_t timer_val) {
    ret_status ret = R_OK;
    PR2 = timer_val;
    return ret;
}

/**
 * 
 */
void TMR2_ISR(void) {
    TIMER2_INTERRUPT_FLAG_CLEAR();
    timer2_write_timer(timer2_preload);
    TMR2_callBack();
}

/**
 * 
 */
void TMR2_callBack(void) {
    if (TMR2_InterruptHandler) {
        TMR2_InterruptHandler();
    } else {
    }
}

