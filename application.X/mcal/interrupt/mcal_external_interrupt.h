/* 
 * File:   mcal_external_interrupt.h
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 2:54 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

#include "mcal_interrupt_config.h"

/* This routine clears the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptDisable()         (INTCONbits.INT0IE = 0)
/* This routine sets the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptEnable()          (INTCONbits.INT0IE = 1)
/* This routine clears the interrupt flag for the external interrupt, INT0 */
#define EXT_INT0_InterruptFlagClear()       (INTCONbits.INT0IF = 0)
/* This routine set the edge detect of the extern interrupt to negative edge */
#define EXT_INT0_risingEdgeSet()            (INTCON2bits.INTEDG0 = 1)
/* This routine set the edge detect of the extern interrupt to positive edge */
#define EXT_INT0_fallingEdgeSet()           (INTCON2bits.INTEDG0 = 0)

/* This routine clears the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptDisable()         (INTCON3bits.INT1IE = 0)
/* This routine sets the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptEnable()          (INTCON3bits.INT1IE = 1)
/* This routine clears the interrupt flag for the external interrupt, INT1 */
#define EXT_INT1_InterruptFlagClear()       (INTCON3bits.INT1IF = 0)
/* This routine set the edge detect of the extern interrupt to negative edge */
#define EXT_INT1_risingEdgeSet()            (INTCON2bits.INTEDG1 = 1)
/* This routine set the edge detect of the extern interrupt to positive edge */
#define EXT_INT1_fallingEdgeSet()           (INTCON2bits.INTEDG1 = 0)

/* This routine clears the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptDisable()         (INTCON3bits.INT2IE = 0)
/* This routine sets the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptEnable()          (INTCON3bits.INT2IE = 1)
/* This routine clears the interrupt flag for the external interrupt, INT2 */
#define EXT_INT2_InterruptFlagClear()       (INTCON3bits.INT2IF = 0)
/* This routine set the edge detect of the extern interrupt to negative edge */
#define EXT_INT2_risingEdgeSet()            (INTCON2bits.INTEDG2 = 1)
/* This routine set the edge detect of the extern interrupt to positive edge */
#define EXT_INT2_fallingEdgeSet()           (INTCON2bits.INTEDG2 = 0)


typedef enum{
    EXTERNAL_INT0,
    EXTERNAL_INT1,
    EXTERNAL_INT2        
}ext_int_source;

typedef enum{
    INTERRUPT_FALLING_EDGE,
    INTERRUPT_RISING_EDGE
}ext_int_edge;

typedef struct{
    void (* EXT_InterruptHandler)(void);
    uint8_t port_name : 4;
    uint8_t pin : 4; 
    ext_int_source int_source;
    ext_int_edge edge;
    priority_config priority;
}ext_int_config; 

void interrupt_external_enable(const ext_int_config *int_config);
void interrupt_external_disable(const ext_int_config *int_config);

/**
 @Summary Interrupt Service Routine for EXT_INT0 - INT0 pin
 @Description This ISR will execute whenever the signal on the INT0 pin will transition to the pre-configured state.
 */
void INT0_ISR(void);

/**
 @Summary Callback function for EXT_INT0 - INT0
 @Description Allows for a specific callback function to be called in the INT0 ISR.
              It also allows for a non-specific interrupt handler to be called at runtime.
 */
void INT0_CallBack(void);

/**
 @Summary Interrupt Service Routine for EXT_INT1 - INT1 pin
 @Description This ISR will execute whenever the signal on the INT1 pin will transition to the pre-configured state.
 */
void INT1_ISR(void);

/**
 @Summary Callback function for EXT_INT1 - INT1
 @Description Allows for a specific callback function to be called in the INT1 ISR.
              It also allows for a non-specific interrupt handler to be called at runtime.
 */
void INT1_CallBack(void);

/**
 @Summary Interrupt Service Routine for EXT_INT2 - INT2 pin
 @Description This ISR will execute whenever the signal on the INT1 pin will transition to the pre-configured state.
 */
void INT2_ISR(void);

/**
 @Summary Callback function for EXT_INT2 - INT2
 @Description Allows for a specific callback function to be called in the INT2 ISR.
              It also allows for a non-specific interrupt handler to be called at runtime.
 */
void INT2_CallBack(void);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */
