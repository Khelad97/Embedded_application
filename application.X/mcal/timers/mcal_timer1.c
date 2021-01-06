/* 
 * File:   mcal_timer.h
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */

#include "mcal_timer1.h"

static void (*TMR1_InterruptHandler)(void) = NULL;
static volatile uint16_t timer1_preload;

/**
 * 16-Bit Read/Write Mode
 * @param timer_obj
 */
static inline void timer1_select_mode(const timer1_t *timer_obj){
    if(timer_obj->timer_register_mode == TIMER1_ONE_16BIT_OPERATION){
        TIMER1_ONE_16BIT_OPERATION_ENABLE();
    }
    else{
        TIMER1_TWO_08BIT_OPERATION_ENABLE();
    }
}

static inline void timer1_select_clock_source(const timer1_t *timer_obj){
    if(timer_obj->timer_counter_mode == TIMER1_TIMER_MODE){
        TIMER1_INTERNAL_CLOCK_SOURCE();
    }
    else{
        TIMER1_EXTERNAL_CLOCK_SOURCE();
        gpio_pin_direction_intialize(PORTC_INDEX, PIN0, DIRECTION_INPUT);
    }
}

static inline void timer1_interrupt_config(const timer1_t *timer_obj){
    if(timer_obj->timer_interrupt_mode == TIMER1_INTERRUPT_ENABLE_MODE){
        TMR1_InterruptHandler = timer_obj->TMR1_InterruptHandler;
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PERIPHERAL_INTERRUPT();
        TIMER1_INTERRUPT_FLAG_CLEAR();
        TIMER1_INTERRUPT_ENABLE();
    }
    else{
        TIMER1_INTERRUPT_DISABLE();
        TMR1_InterruptHandler = NULL;
    }
}

static inline void timer1_prescaler_control(const timer1_t *timer_obj){
    T1CONbits.T1CKPS = timer_obj->timer_prescaler_value;
}

ret_status timer1_initialize(const timer1_t *timer_obj){
    ret_status ret = R_OK;
    TIMER1_STOP();  /* Timer1 On/Off Control */
    timer1_select_mode(timer_obj);
    timer1_select_clock_source(timer_obj);
    timer1_interrupt_config(timer_obj);
    timer1_prescaler_control(timer_obj);
    /* Update Timer Pre-load Value*/
    timer1_write_timer(timer_obj->timer_preload_value);
    timer1_preload = timer_obj->timer_preload_value;
    TIMER1_START(); /* Timer1 On/Off Control */
    return ret;
}

ret_status timer1_read_timer(uint16_t *timer_value){
    ret_status ret = R_OK;
    uint8_t read_tmr1l = TIMER1_REGISTER_8BIT_CLEAR, read_tmr1h = TIMER1_REGISTER_8BIT_CLEAR;
    read_tmr1l = TMR1L;
    read_tmr1h = TMR1H;
    *timer_value = ((uint16_t)(read_tmr1h<<8)) + read_tmr1l;
    return ret;
}

ret_status timer1_write_timer(uint16_t timer_value){
    ret_status ret = R_OK;
    /* Enables register read/write of Timer1 in two 8-bit operations */
    TMR1H = timer_value>>8;
    TMR1L = (uint8_t)timer_value;
    return ret;
}


void TMR1_ISR(void){
    TIMER1_INTERRUPT_FLAG_CLEAR();
    /* Enables register read/write of Timer1 in two 8-bit operations */
    TMR1H = timer1_preload >> 8;
    TMR1L = (uint8_t)timer1_preload;
    TMR1_CallBack();
}

void TMR1_CallBack(void){
    /* Add your custom callback code here */
    if(TMR1_InterruptHandler){  TMR1_InterruptHandler();    }
    else{}
}

