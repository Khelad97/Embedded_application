/*
 * File:   application.c
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:09 PM
 */

#include "application.h"

button_t button1= {.port_name = PORTC_INDEX, .pin = PIN0,.button_status=BUTTON_NOT_PRESSED};
button_t button2= {.port_name = PORTC_INDEX, .pin = PIN1,.button_status=BUTTON_NOT_PRESSED};

usart_t uart1 = {
    .baudrate = 9600,
    .eusart_config.EUSART_sync_async_mode = EUSART_ASYNCHRONOUS_MODE,
    .eusart_config.transmit_enable = EUSART_TX_ENABLE,
    .eusart_config.receiver_enable = EUSART_RX_ENABLE,
    .baudrate_gen_gonfig = BAUDRATE_ASYN_8BIT_lOW_SPEED,
    .EUSART_ErrorHandler = NULL,
    .EUSART_FramingErrorHandler = NULL,
    .EUSART_OverrunErrorHandler = NULL,
    .EUSART_RxDefaultInterruptHandler = EUSART_RxDefaultInterruptHandler,
    .EUSART_TxDefaultInterruptHandler = EUSART_TxDefaultInterruptHandler
};

uint8_t but_val,but_val_1,flag=0,flag1=0;

uint8_t task1='1';
uint8_t task2='2';
int main(void) {
    application_initilaze();
    
      while(TRUE){
      button_get_status(&button1,&but_val);
      if(but_val==1&&flag==0){
        EUSART_Write(task1);
        flag=1;
        __delay_ms(200);
      }else{
      flag=0;
       __delay_ms(100);
      }
    
    button_get_status(&button2,&but_val_1);
      if(but_val_1==1&&flag1==0){
        EUSART_Write(task2);
        flag1=1;
        __delay_ms(200);
      }else{
      flag1=0;
       __delay_ms(100);
      }
}
    return (EXIT_SUCCESS);
}

void application_initilaze(void){
   ENABLE_GLOBAL_INTERRUPT();
   ENABLE_PERIPHERAL_INTERRUPT();
   //interrupt_priority_enable();
   EUSART_Initialize(&uart1);
   button_initialize(&button1);
   button_initialize(&button2);
}

void EUSART_TxDefaultInterruptHandler(void){
   
    
}

void EUSART_RxDefaultInterruptHandler(void){
    
}