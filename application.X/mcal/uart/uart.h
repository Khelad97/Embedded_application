/* 
 * File:   uart.h
 * Author: Khelad Mohamed
 *
 * Created on February 12, 2021, 1:36 PM
 */

#ifndef UART_H
#define	UART_H

#include "../../std_types.h"
#include "../interrupt/mcal_usart_interrupt.h"
#include "../mcal_gpio/mcal_gpio.h"

#define EUSART_TX_BUFFER_SIZE 8
#define EUSART_RX_BUFFER_SIZE 8

/* Section: Macro Declarations */
#define EUSART_SYNCHRONOUS_MODE  1
#define EUSART_ASYNCHRONOUS_MODE 0

#define EUSART_ENABLE  1
#define EUSART_DISABLE 0
#define EUSART_TX_ENABLE  1
#define EUSART_TX_DISABLE 0
#define EUSART_RX_ENABLE  1
#define EUSART_RX_DISABLE 0

#define EUSART_ASYNCHRONOUS_HIGH_SPEED  1
#define EUSART_ASYNCHRONOUS_LOW_SPEED  0
#define EUSART_16BIT_BAUDRATE_GEN  1
#define EUSART_08BIT_BAUDRATE_GEN  0

#define EUSART_FRAME_ERROR_EXIST          1
#define EUSART_FRAME_ERROR_NOT_EXIST      0
#define EUSART_OVERRUN_ERROR_EXIST        1
#define EUSART_OVERRUN_ERROR_NOT_EXIST    0

/* Section: Data Type Definitions */
typedef union {
    struct {
        uint8_t ferr : 1;
        uint8_t oerr : 1;
        uint8_t reserved : 6;
    };
    uint8_t status;
}eusart_status_t;

typedef enum{
    BAUDRATE_ASYN_8BIT_lOW_SPEED,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_lOW_SPEED,   
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_SYN_8BIT,
    BAUDRATE_SYN_16BIT
}baudrate_gen_t;

typedef struct{
    uint8_t transmit_enable : 1;
    uint8_t receiver_enable : 1;
    uint8_t transmit_9bits_config : 1;
    uint8_t receive_9bits_config : 1;
    uint8_t EUSART_sync_async_mode : 1;
    uint8_t address_detection : 1;
    uint8_t reserved : 2;
}eusart_config_t;

typedef struct{
    uint32_t baudrate;
    baudrate_gen_t baudrate_gen_gonfig;
    eusart_status_t EUSART_RxLastError;
    eusart_config_t eusart_config;
    void (*EUSART_TxDefaultInterruptHandler)(void);
    void (*EUSART_RxDefaultInterruptHandler)(void);
    void (*EUSART_FramingErrorHandler)(void);
    void (*EUSART_OverrunErrorHandler)(void);
    void (*EUSART_ErrorHandler)(void);
}usart_t;

void EUSART_Initialize(const usart_t *usart_obj);
void EUSART_Write(uint8_t txData);
uint8_t EUSART_Read(void);



#endif	/* UART_H */

