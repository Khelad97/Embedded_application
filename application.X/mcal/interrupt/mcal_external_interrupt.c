/* 
 * File:   mcal_external_interrupt.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 2:54 PM
 */

#include "mcal_external_interrupt.h"

static void (*INT0_InterruptHandler)(void);
static void (*INT1_InterruptHandler)(void);
static void (*INT2_InterruptHandler)(void);

/**
 * Enable the external interrupt with the desired configurations
 * @param int_config pointer to the configurations definition
 */
void interrupt_external_enable(const ext_int_config *int_config){
    if(int_config->int_source == EXTERNAL_INT0){
        /* Configure External Interrupt 0 */
        EXT_INT0_InterruptFlagClear(); /* The INT0 external interrupt did not occur */
        if(int_config->edge == INTERRUPT_RISING_EDGE){
            EXT_INT0_risingEdgeSet(); /* Interrupt on rising edge */
        }else{ INTCON2bits.INTEDG0 = INTERRUPT_FALLING_EDGE;} /* Interrupt on falling edge */
        INT0_InterruptHandler = int_config->EXT_InterruptHandler;  /* Set Default Interrupt Handler */
        gpio_pin_direction_intialize(int_config->port_name, int_config->pin, DIRECTION_INPUT);
        EXT_INT0_InterruptEnable();  /* Enables the INT0 external interrupt */
    }
    else if(int_config->int_source == EXTERNAL_INT1){
        /* Configure External Interrupt 1 */
        EXT_INT1_InterruptFlagClear(); /* The INT0 external interrupt did not occur */
        if(int_config->edge == INTERRUPT_RISING_EDGE){
            EXT_INT1_risingEdgeSet(); /* Interrupt on rising edge */
        }else{ INTCON2bits.INTEDG1 = INTERRUPT_FALLING_EDGE; } /* Interrupt on falling edge */
        if(int_config->priority == HIGH_PRIORITY){
            INTCON3bits.INT1IP = HIGH_PRIORITY; /* INT1 External Interrupt Priority :  High priority */
        }else{ INTCON3bits.INT1IP = LOW_PRIORITY; } /* INT1 External Interrupt Priority :  Low priority */
        INT1_InterruptHandler = int_config->EXT_InterruptHandler;  /* Set Default Interrupt Handler */
        gpio_pin_direction_intialize(int_config->port_name, int_config->pin, DIRECTION_INPUT);
        EXT_INT1_InterruptEnable(); /* Enables the INT1 external interrupt */
    }
    else if(int_config->int_source == EXTERNAL_INT2){
        /* Configure External Interrupt 2 */
        EXT_INT2_InterruptFlagClear(); /* The INT0 external interrupt did not occur */
        if(int_config->edge == INTERRUPT_RISING_EDGE){
            EXT_INT2_risingEdgeSet(); /* Interrupt on rising edge */
        }else{ INTCON2bits.INTEDG2 = INTERRUPT_FALLING_EDGE; } /* Interrupt on falling edge */
        if(int_config->priority == HIGH_PRIORITY){
            INTCON3bits.INT2IP = HIGH_PRIORITY; /* INT2 External Interrupt Priority :  High priority */
        } else{ INTCON3bits.INT2IP = LOW_PRIORITY; } /* INT2 External Interrupt Priority :  Low priority */
        INT2_InterruptHandler = int_config->EXT_InterruptHandler;  /* Set Default Interrupt Handler */
        gpio_pin_direction_intialize(int_config->port_name, int_config->pin, DIRECTION_INPUT);
        EXT_INT2_InterruptEnable(); /* Enables the INT2 external interrupt */
    }
    else{}
}

/**
 * Disable the external interrupt 
 * @param int_config pointer to the configurations definition
 */
void interrupt_external_disable(const ext_int_config *int_config){
    if(int_config->int_source == EXTERNAL_INT0){
        EXT_INT0_InterruptDisable(); /* Disables the INT0 external interrupt */
    }
    else if(int_config->int_source == EXTERNAL_INT1){
        EXT_INT1_InterruptDisable(); /* Disables the INT1 external interrupt */
    }
    else if(int_config->int_source == EXTERNAL_INT2){
        EXT_INT2_InterruptDisable(); /* Disables the INT2 external interrupt */
    }
    else{}
}

void INT0_ISR(void){
    EXT_INT0_InterruptFlagClear(); /* The INT0 external interrupt occurred (must be cleared in software) */
    INT0_CallBack(); /* Callback function gets called every time this ISR executes */
}

void INT0_CallBack(void){
    /* Add your custom callback code here */
    if(INT0_InterruptHandler){  INT0_InterruptHandler();    }
    else{}
}

void INT1_ISR(void){
    EXT_INT1_InterruptFlagClear(); /* The INT1 external interrupt occurred (must be cleared in software) */
    INT1_CallBack(); /* Callback function gets called every time this ISR executes */
}

void INT1_CallBack(void){
    /* Add your custom callback code here */
    if(INT1_InterruptHandler){  INT1_InterruptHandler();    }
    else{}
}

void INT2_ISR(void){
    EXT_INT2_InterruptFlagClear(); /* The INT2 external interrupt occurred (must be cleared in software) */
    INT2_CallBack(); /* Callback function gets called every time this ISR executes */
}

void INT2_CallBack(void){
    /* Add your custom callback code here */
    if(INT2_InterruptHandler){  INT2_InterruptHandler();    }
    else{}
}
