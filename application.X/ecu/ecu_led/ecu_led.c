/* 
 * File:   ecu_led.c
 * Author: Khelad Mohamed
 *
 * Created on October 24, 2020, 8:14 PM
 */
#include <stdlib.h>
#include "ecu_led.h"

/**
 * 
 * @param led
 * @return 
 */
ret_status led_initialize(led_t *led) {
    ret_status ret = R_NOK;

    if ((NULL == led) || (led->port_name > PORT_MAX_NUMBERS - 1) ||
            (led->pin > PORT_PIN_MAX_NUMBERS - 1)) {
        return ret;
    } else {
        gpio_pin_direction_intialize(led->port_name, led->pin, DIRECTION_OUTPUT);
        gpio_pin_write_value(led->port_name, led->pin, PIN_LOW);
        return R_OK;
    }
}

/**
 * 
 * @param led
 * @return 
 */
ret_status led_turn_on(led_t *led) {
    ret_status ret = R_NOK;
    if ((NULL == led) || (led->port_name > PORT_MAX_NUMBERS - 1) ||
            (led->pin > PORT_PIN_MAX_NUMBERS - 1)) {
        return ret;
    } else {
        gpio_pin_write_value(led->port_name, led->pin, PIN_HIGH);
        return R_OK;
    }
}

/**
 * 
 * @param led
 * @return 
 */
ret_status led_turn_off(led_t *led) {
    ret_status ret = R_NOK;
    if ((NULL == led) || (led->port_name > PORT_MAX_NUMBERS - 1) ||
            (led->pin > PORT_PIN_MAX_NUMBERS - 1)) {
        return ret;
    } else {
        gpio_pin_write_value(led->port_name, led->pin, PIN_LOW);
        return R_OK;
    }
}

/**
 * 
 * @param led
 * @return 
 */
ret_status led_turn_toggle(led_t *led) {
    ret_status ret = R_NOK;
    if ((NULL == led) || (led->port_name > PORT_MAX_NUMBERS - 1) ||
            (led->pin > PORT_PIN_MAX_NUMBERS - 1)) {
        return ret;
    } else {
        gpio_pin_toggle_value(led->port_name, led->pin);
        return R_OK;
    }
}