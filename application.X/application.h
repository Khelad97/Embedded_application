/* 
 * File:   application.h
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 7:57 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


#include <stdio.h>
#include <stdlib.h>

#include "std_types.h"
#include "device_config.h"
#include "ecu/ecu_led/ecu_led.h"
#include "ecu/ecu_button/ecu_button.h"
#include "ecu/ecu_relay/ecu_relay.h"
#include "ecu/ecu_motor/ecu_motor.h"
#include "ecu/ecu_lcd/ecu_lcd.h"
#include "ecu/ecu_keypad/ecu_keypad.h"
#include"mcal/timers/mcal_timer0.h"
#include"mcal/timers/mcal_timer1.h"
#include"mcal/timers/mcal_timer2.h"
#include"mcal/interrupt/mcal_external_interrupt.h"
#include"mcal/interrupt/mcal_interrupt_config.h"
#include"mcal/interrupt/mcal_interrupt_manager.h"
#include"mcal/interrupt/mcal_timer_interrupt.h"
#include "mcal/uart/uart.h"

#define LED_SEQ_NUMBER 8


void timer0_DefaultInterruptHandler(void);
void application_initilaze(void);
void INT2_DefaultInterruptHandler(void);

void RB4_DefaultInterruptHandler(void);
void RB5_DefaultInterruptHandler(void);
void RB6_DefaultInterruptHandler(void);
void RB7_DefaultInterruptHandler(void);

void Timer0_DefaultInterruptHandler(void);
void Timer1_DefaultInterruptHandler(void);
void Timer2_DefaultInterruptHandler(void);
void Timer3_DefaultInterruptHandler(void);

void EUSART_TxDefaultInterruptHandler(void);
void EUSART_RxDefaultInterruptHandler(void);
#endif	/* APPLICATION_H */

