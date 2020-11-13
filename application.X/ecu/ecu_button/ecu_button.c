/* 
 * File:   ecu_button.c
 * Author: Khelad Mohamed
 *
 * Created on October 25, 2020, 12:38 PM
 */

#include <stdlib.h>

#include "ecu_button.h"

/**
 * 
 * @param btn
 * @return 
 */
ret_status button_initialize(button_t *btn) {
    ret_status ret = R_NOK;
    if (btn->port_name > PORT_MAX_NUMBERS - 1 || btn == NULL) {
        return ret;
    } else {
        gpio_pin_direction_intialize(btn->port_name, btn->pin, DIRECTION_INPUT);
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param btn
 * @param btn_status
 * @return 
 */
ret_status button_get_status(button_t *btn, button_status *btn_status) {

    ret_status ret = R_NOK;
    if (btn->port_name > PORT_MAX_NUMBERS - 1 || btn == NULL) {
        return ret;
    } else {
        gpio_pin_read_value(btn->port_name, btn->pin, btn_status);
        btn->button_status = *btn_status;
        ret = R_OK;
    }
    return ret;
}

