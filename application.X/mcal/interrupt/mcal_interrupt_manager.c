/* 
 * File:   mcal_interrupt_manager.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 2:57 PM
 */

#include "mcal_interrupt_manager.h"

static volatile uint8_t rb4_flag = 0,  rb5_flag = 0, rb6_flag = 0, rb7_flag = 0;

void interrupt_priority_enable(void){
    RCONbits.IPEN = PRIORITY_ENABLE;
}

void interrupt_priority_disable(void){
    RCONbits.IPEN = PRIORITY_DISABLE;
}

void __interrupt() INTERRUPT_InterruptManagerHigh (void){
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR)){
        INT0_ISR();
    }
    else{}
    
    /* Timer0 */
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE) && (INTCONbits.TMR0IF == INTERRUPT_OCCUR)){
        TMR0_ISR();
    }
    else{}
    
    /* Timer1 */
    if((PIE1bits.TMR1IE == INTERRUPT_ENABLE) && (PIR1bits.TMR1IF == INTERRUPT_OCCUR)){
        TMR1_ISR();
    }
    else{}
    
    /* Timer2 */
    if((PIE1bits.TMR2IE == INTERRUPT_ENABLE) && (PIR1bits.TMR2IF == INTERRUPT_OCCUR)){
        TMR2_ISR();
    }
    else{}
    
    /* Timer3 */
    if((PIE2bits.TMR3IE == INTERRUPT_ENABLE) && (PIR2bits.TMR3IF == INTERRUPT_OCCUR)){
        TMR3_ISR();
    }
    else{}
    
    // EUSART Interrupt Handling
    if(PIE1bits.TX1IE == 1 && PIR1bits.TX1IF == 1){
        EUSART_Transmit_ISR();
    }else{/* Un-handled Interrupt */ }
    
    if(PIE1bits.RC1IE == 1 && PIR1bits.RC1IF == 1){
        EUSART_Receive_ISR();
    }else{/* Un-handled Interrupt */ }
}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow (void){
    if((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCUR)){
        INT1_ISR();
    }
    else{}
    
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCUR)){
        INT2_ISR();
    }
    else{}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB4 == RB_PIN_LOGIC_HIGH)){
        rb4_flag = 1;
        RB4_ISR();
    }
    else if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB4 == RB_PIN_LOGIC_LOW) && (rb4_flag == 1)){
        rb4_flag = 0;
        RB4_ISR();
    }
    else{}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB5 == RB_PIN_LOGIC_HIGH)){
        rb5_flag = 1;
        RB5_ISR();
    }
    else if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB5 == RB_PIN_LOGIC_LOW) && (rb5_flag == 1)){
        rb5_flag = 0;
        RB5_ISR();
    }
    else{}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB6 == RB_PIN_LOGIC_HIGH)){
        rb6_flag = 1;
        RB6_ISR();
    }
    else if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB6 == RB_PIN_LOGIC_LOW) && (rb6_flag == 1)){
        rb6_flag = 0;
        RB6_ISR();
    }
    else{}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB7 == RB_PIN_LOGIC_HIGH)){
        rb7_flag = 1;
        RB7_ISR();
    }
    else if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB7 == RB_PIN_LOGIC_LOW) && (rb7_flag == 1)){
        rb7_flag = 1;
        RB7_ISR();
    }
    else{}
    
}
