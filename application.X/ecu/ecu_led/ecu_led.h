/* 
 * File:   ecu_led.h
 * Author: Khelad Mohamed
 *
 * Created on October 24, 2020, 8:15 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


#include"../../mcal/mcal_gpio/mcal_gpio.h"

typedef enum {
    LED_OFF,
    LED_ON
} led_status;

typedef struct {

    struct {
        uint8_t port_name : 4;
        uint8_t pin : 4;
    } port_info;
    led_status led_stutus;
} led_t;

ret_status led_initialize(led_t *led);

ret_status led_turn_on(led_t *led);

ret_status led_turn_off(led_t *led);

ret_status led_turn_toggle(led_t *led);

#endif	/* ECU_LED_H */

