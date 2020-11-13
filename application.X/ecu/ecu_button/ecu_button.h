/* 
 * File:   ecu_button.h
 * Author: Khelad Mohamed
 *
 * Created on October 25, 2020, 12:39 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H
#include <stdlib.h>
#include "../../mcal/mcal_gpio/mcal_gpio.h"

typedef enum {
    BUTTON_NOT_PRESSED,
    BUTTON_PRESSED
} button_status;

typedef struct {
    uint8_t port_name : 4;
    uint8_t pin : 3;
    uint8_t button_status : 1;
} button_t;

ret_status button_initialize(button_t *btn);
ret_status button_get_status(button_t *btn ,button_status *btn_status);
#endif	/* ECU_BUTTON_H */

