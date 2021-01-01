/* 
 * File:   ecu_relay.c
 * Author: Khelad Mohamed
 *
 * Created on October 24, 2020, 8:14 PM
 */
#include <stdlib.h>
#include "ecu_relay.h"

/**
 * 
 * @param led
 * @return 
 */
ret_status relay_initialize(relay_t *relay) {
    ret_status ret = R_NOK;

    if ((NULL == relay) || (relay->port_name > PORT_MAX_NUMBERS - 1) ||
            (relay-> pin > PORT_PIN_MAX_NUMBERS - 1)) {
        return ret;
    } else {
        gpio_pin_direction_intialize(relay->port_name, relay->pin, DIRECTION_OUTPUT);
        gpio_pin_write_value(relay->port_name, relay->pin, RELAY_OFF);
        return R_OK;
    }
}

/**
 * 
 * @param led
 * @return 
 */
ret_status relay_turn_on(relay_t *relay) {
    ret_status ret = R_NOK;
    if ((NULL == relay) || (relay->port_name > PORT_MAX_NUMBERS - 1) ||
            (relay->pin > PORT_PIN_MAX_NUMBERS - 1)) {
        return ret;
    } else {
        gpio_pin_write_value(relay->port_name, relay->pin, RELAY_ON);
        return R_OK;
    }
}

/**
 * 
 * @param led
 * @return 
 */
ret_status relay_turn_off(relay_t *relay) {
    ret_status ret = R_NOK;
    if ((NULL == relay) || (relay->port_name > PORT_MAX_NUMBERS - 1) ||
            (relay->pin > PORT_PIN_MAX_NUMBERS - 1)) {
        return ret;
    } else {
        gpio_pin_write_value(relay->port_name, relay->pin, RELAY_OFF);
        return R_OK;
    }
}

