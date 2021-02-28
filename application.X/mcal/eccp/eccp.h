/* 
 * File:   eccp.h
 * Author: Khelad Mohamed
 *
 * Created on January 22, 2021, 4:50 AM
 */

#ifndef ECCP_H
#define	ECCP_H
#include "pic18f46k20.h"
#include "../../std_types.h"
#include"../mcal_gpio/mcal_gpio.h"
#include"../timers/mcal_timer0.h"
#include"../timers/mcal_timer1.h"
#include"../timers/mcal_timer2.h"
#include"../timers/mcal_timer3.h"

#define PWM_MODE_EN 0
#define CAP_MODE_EN 1
#define COM_MODE_EN 2
#define SELECT_MODE COMPARE_MODE_EN

/*Enhanced PWM Output Configuration bits*/


#define ECCP_PWM_SINGLE_OUT()               (CCP1CONbits.P1M=0)
#define ECCP_PWM_FULL_BRIDGE_OUT_FORWARD()  (CCP1CONbits.P1M=1)
#define ECCP_PWM_HALF_BRIDGE_OUT()          (CCP1CONbits.P1M=2)
#define ECCP_PWM_FULL_BRIDGE_OUT_REVERSE()  (CCP1CONbits.P1M=3)
#define CCP_OFF                             0U
#define COMPARE_MODE_TOOGLE_OUTPUT          2U
#define CAPTURE_MODE                        3U
#define CAPTURE_MODE_FALLING_EDGE           4U
#define CAPTURE_MODE_RISING_EDGE            5U
#define CAPTURE_MODE_RISING_EDGE_4TH        6U
#define CAPTURE_MODE_RISING_EDGE_16TH       7U
#define COMPARE_MODE_PIN_LOW_SET_OUTPUT     8U
#define COMPARE_MODE_PIN_HIGH_CLR_OUTPUT    9U
#define COMPARE_MODE_GENERATE_INTERRUPT    10U
#define COMPARE_MODE_TRIGGER_EVENT         11U
#define PWM_MODE_P1A_PIC_HIGH_P1B_P1D_HIGH 12U
#define PWM_MODE_P1A_PIC_HIGH_P1B_P1D_LOW  13U
#define PWM_MODE_P1A_PIC_LOW_P1B_P1D_HIGH  14U
#define PWM_MODE_P1A_PIC_LOW_P1B_P1D_LOW   15U

typedef struct{
#if SELECT_MODE == PWM_MODE_EN
    
#elif SELECT_MODE ==CAP_MODE_EN
    
#elif SELECT_MODE ==COM_MODE_EN 
    
#else
#error "un_selected_mode!!"
#endif

}eccp_t;

#endif	/* ECCP_H */

