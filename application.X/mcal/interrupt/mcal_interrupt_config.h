/* 
 * File:   mcal_interrupt_config.h
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 2:57 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

#include "pic18f46k20.h"
#include "../../std_types.h"
#include "../mcal_gpio/mcal_gpio.h"

#define INTERRUPT_ENABLE        1
#define INTERRUPT_DISABLE       0
#define INTERRUPT_OCCUR         1
#define INTERRUPT_NOT_OCCUR     0
#define PRIORITY_ENABLE         1
#define PRIORITY_DISABLE        0

#define RB_PIN_LOGIC_HIGH       1
#define RB_PIN_LOGIC_LOW        0

/* This macro will enable global interrupts */
#define ENABLE_GLOBAL_INTERRUPT()       (INTCONbits.GIE = 1)
/* This macro will disable global interrupts */
#define DISABLE_GLOBAL_INTERRUPT()      (INTCONbits.GIE = 0)
/* This macro will enable peripheral interrupts */
#define ENABLE_PERIPHERAL_INTERRUPT()   (INTCONbits.PEIE = 1)
/* This macro will disable peripheral interrupts */
#define DISABLE_PERIPHERAL_INTERRUPT()  (INTCONbits.PEIE = 0)

typedef enum{
    LOW_PRIORITY,
    HIGH_PRIORITY
}priority_config;

#endif	/* MCAL_INTERRUPT_CONFIG_H */

