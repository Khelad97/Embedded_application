/* 
 * File:   ecu_relay.h
 * Author: Khelad Mohamed
 *  
 * Created on October 24, 2020, 8:15 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H


#include"../../mcal/mcal_gpio/mcal_gpio.h"

typedef enum {
    RELAY_OFF,
    RELAY_ON
} relay_status_t;

typedef struct {
    uint8_t port_name : 4;
    uint8_t pin : 3;
    uint8_t relay_stutus : 1;
} relay_t;

ret_status relay_initialize(relay_t *relay);

ret_status relay_turn_on(relay_t *relay);

ret_status relay_turn_off(relay_t *relay);

#endif	/* ECU_RELAY_H */

