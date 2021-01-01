/* 
 * File:   mcal_interrupt_manager.h
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 2:57 PM
 */

#ifndef MCAL_INTERRUPT_H
#define	MCAL_INTERRUPT_H

#include "mcal_interrupt_config.h"
#include "mcal_external_interrupt.h"
#include"mcal_timer_interrupt.h"
void interrupt_priority_enable(void);
void interrupt_priority_disable(void);

#endif	/* MCAL_INTERRUPT_H */

