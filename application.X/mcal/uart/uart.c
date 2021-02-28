/* 
 * File:   uart.h
 * Author: Khelad Mohamed
 *
 * Created on February 12, 2021, 1:36 PM
 */

#include "uart.h"

static void (*EUSART_TxInterruptHandler)(void) = NULL;
static void (*EUSART_RxInterruptHandler)(void) = NULL;
static void (*EUSART_FramingErrorInterruptHandler)(void) = NULL;
static void (*EUSART_OverrunErrorInterruptHandler)(void) = NULL;
static void (*EUSART_ErrorInterruptHandler)(void) = NULL;

volatile eusart_status_t eusartRxLastError;

volatile uint8_t eusartTxHead = ZERO_INIT;
volatile uint8_t eusartTxTail = ZERO_INIT;
volatile uint8_t eusartTxBuffer[EUSART_TX_BUFFER_SIZE];
volatile uint8_t eusartTxBufferRemaining;

volatile uint8_t eusartRxHead = ZERO_INIT;
volatile uint8_t eusartRxTail = ZERO_INIT;
volatile uint8_t eusartRxBuffer[EUSART_RX_BUFFER_SIZE];
volatile uint8_t eusartRxCount;

volatile eusart_status_t eusartRxStatusBuffer[EUSART_RX_BUFFER_SIZE];

static void EUSART_Mode_Select(const usart_t *usart_obj);
static void EUSART_Receiver_Enable(const usart_t *usart_obj);
static void EUSART_Transmit_Enable(const usart_t *usart_obj);
static void EUSART_Baud_Rate_Calculation(const usart_t *usart_obj);
static void EUSART_RxDataHandler(void);

void EUSART_Initialize(const usart_t *usart_obj){
    usart_interrupt_enable(USART_INT_RX_DISABLE); // Disable the RX Interrupt
    usart_interrupt_enable(USART_INT_TX_DISABLE); // Disable the TX Interrupt
    
    usart_clear_tx_interrupt_flag();
    usart_clear_rx_interrupt_flag();
    EUSART_Mode_Select(usart_obj); // EUSART Mode Select
    EUSART_Receiver_Enable(usart_obj); // Enable Rx
    EUSART_Transmit_Enable(usart_obj); // Enable Tx
    EUSART_Baud_Rate_Calculation(usart_obj); // Baud Rate Calculation
    EUSART_TxInterruptHandler = usart_obj->EUSART_TxDefaultInterruptHandler;
    EUSART_RxInterruptHandler = usart_obj->EUSART_RxDefaultInterruptHandler;
    EUSART_FramingErrorInterruptHandler = usart_obj->EUSART_FramingErrorHandler;
    EUSART_OverrunErrorInterruptHandler = usart_obj->EUSART_OverrunErrorHandler;
    EUSART_ErrorInterruptHandler = usart_obj->EUSART_ErrorHandler;
    eusartRxLastError.status = ZERO_INIT; // Clear the status if the EUSART at initialization
    
    eusartTxHead = ZERO_INIT;
    eusartTxTail = ZERO_INIT;
    eusartTxBufferRemaining = sizeof(eusartTxBuffer);
    eusartRxHead = ZERO_INIT;
    eusartRxTail = ZERO_INIT;
    
    usart_interrupt_enable(USART_INT_RX_ENABLE); // Enable the RX Interrupt
    //usart_interrupt_enable(USART_INT_TX_ENABLE); // Enable the TX Interrupt
    PIE1bits.TX1IE = INT_ENABLE;
    PIE1bits.RC1IE = INT_ENABLE;
}

void EUSART_Write(uint8_t txData){
    usart_clear_tx_interrupt_flag();
    PIE1bits.TX1IE = INT_ENABLE;
    if(ZERO_INIT == PIE1bits.TX1IE){
        TXREG = txData;
    }
    else{
        while(ZERO_INIT == eusartTxBufferRemaining){}
        eusartTxBuffer[eusartTxHead++] = txData;
        if(sizeof(eusartTxBuffer) <= eusartTxHead){ 
            eusartTxHead = ZERO_INIT; // Reset the Head buffer pointer to the start of the buffer
        }
        eusartTxBufferRemaining--; // If eusartTxBufferRemaining==0 -> No space at the TX buffer to add new data 
        PIE1bits.TX1IE = INT_ENABLE;
    }
}

void EUSART_Transmit_ISR(void){
    usart_clear_tx_interrupt_flag();
    if(sizeof(eusartTxBuffer) > eusartTxBufferRemaining){
        TXREG = eusartTxBuffer[eusartTxTail++];
        if(sizeof(eusartTxBuffer) <= eusartTxTail){
            eusartTxTail = 0; // Reset the buffer pointer tail
        }
        else{/* Nothing */}
        eusartTxBufferRemaining++;
    }
    else{
        PIE1bits.TX1IE = INT_DISABLE; // If the There is no data at the Tx buffer, Disable the Tx interrupt
    }
    EUSART_TxInterruptHandler();
}

uint8_t EUSART_Read(void){
    uint8_t readValue  = ZERO_INIT;
    eusartRxLastError = eusartRxStatusBuffer[eusartRxTail];
    readValue = eusartRxBuffer[eusartRxTail++];
    if(sizeof(eusartRxBuffer) <= eusartRxTail){
        eusartRxTail = 0;
    }{/* Nothing */}
    usart_interrupt_enable(USART_INT_RX_DISABLE);
    eusartRxCount--;
    usart_interrupt_enable(USART_INT_RX_ENABLE);
    return readValue;
}

void EUSART_Receive_ISR(void){
    PIR1bits.RC1IF = FLAG_CLEARED;
    eusartRxStatusBuffer[eusartRxHead].status = 0;
    // Update the Framing Error status
    if(RCSTAbits.FERR){
        eusartRxStatusBuffer[eusartRxHead].ferr = EUSART_FRAME_ERROR_EXIST;
        EUSART_FramingErrorInterruptHandler();
    }else{/* Nothing */}
    if(RCSTAbits.OERR){
        eusartRxStatusBuffer[eusartRxHead].oerr = EUSART_OVERRUN_ERROR_EXIST;
        EUSART_OverrunErrorInterruptHandler();
    }else{/* Nothing */}
    if(eusartRxStatusBuffer[eusartRxHead].status){
        EUSART_ErrorInterruptHandler();
    }else{
        EUSART_RxDataHandler();
    }
    EUSART_RxInterruptHandler();
}

static void EUSART_RxDataHandler(void){
    eusartRxBuffer[eusartRxHead++] = RCREG;
    if(sizeof(eusartRxBuffer) <= eusartRxHead){
        eusartRxHead = 0;
    }
    else{/* Nothing */}
    eusartRxCount++;
}

static void EUSART_Mode_Select(const usart_t *usart_obj){
    if(usart_obj->eusart_config.EUSART_sync_async_mode == EUSART_SYNCHRONOUS_MODE){
        TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
    }
    else{
        TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
    }
}

static void EUSART_Receiver_Enable(const usart_t *usart_obj){
    if(usart_obj->eusart_config.receiver_enable == EUSART_RX_ENABLE){
        gpio_pin_direction_intialize(PORTC_INDEX, PIN7, DIRECTION_INPUT);
        RCSTAbits.SPEN = EUSART_ENABLE;
        RCSTAbits.CREN = EUSART_RX_ENABLE;
    }
    else{
        RCSTAbits.CREN = EUSART_RX_DISABLE;
    }
}

static void EUSART_Transmit_Enable(const usart_t *usart_obj){
    if(usart_obj->eusart_config.transmit_enable == EUSART_TX_ENABLE){
        gpio_pin_direction_intialize(PORTC_INDEX, PIN6, DIRECTION_INPUT);
        RCSTAbits.SPEN = EUSART_ENABLE;
        TXSTAbits.TXEN = EUSART_TX_ENABLE;
    }
    else{
        TXSTAbits.TXEN = EUSART_TX_DISABLE;
    }
}

static void EUSART_Baud_Rate_Calculation(const usart_t *usart_obj){
    float temp = 0;
    switch(usart_obj->baudrate_gen_gonfig){
        case BAUDRATE_ASYN_8BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            temp = (((_XTAL_FREQ / (float)(usart_obj->baudrate)) / 64) - 1);
            break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            temp = (((float)(_XTAL_FREQ) / (float)(usart_obj->baudrate * 16)) - 1);
            break;
        case BAUDRATE_ASYN_16BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            temp = (((float)(_XTAL_FREQ) / (float)(usart_obj->baudrate * 16)) - 1);
            break;
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            temp = (((float)(_XTAL_FREQ) / (float)(usart_obj->baudrate * 4)) - 1);
            break;
        case BAUDRATE_SYN_8BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            temp = (((float)(_XTAL_FREQ) / (float)(usart_obj->baudrate * 4)) - 1);
            break;
        case BAUDRATE_SYN_16BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            temp = (((float)(_XTAL_FREQ) / (float)(usart_obj->baudrate * 4)) - 1);
            break;
        default : /* Nothing */;
    }
    SPBRG  = (uint8_t)((uint32_t)temp);
    SPBRGH = (uint8_t)(((uint32_t)temp) >> 8);
}
