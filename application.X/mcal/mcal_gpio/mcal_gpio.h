/* 
 * File:   mcal_gpio.h
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:22 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H

#include"pic18f46k20.h"
#include "../../std_types.h"

#define PORT_PIN_MAX_NUMBERS 8UL
#define PORT_MAX_NUMBERS 5UL

typedef enum {
    PIN_LOW,
    PIN_HIGH
} pin_logic;

typedef enum {
    DIRECTION_OUTPUT,
    DIRECTION_INPUT
} direction_t;

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} pin_index;

typedef enum {
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
} port_index;

ret_status gpio_pin_direction_intialize(port_index port, pin_index pin, direction_t direction);
ret_status gpio_pin_get_direction_status(port_index port, pin_index pin, direction_t *direction);
ret_status gpio_pin_write_value(port_index port, pin_index pin, pin_logic logic);
ret_status gpio_pin_read_value(port_index port, pin_index pin, pin_logic *logic);
ret_status gpio_pin_toggle_value(port_index port, pin_index pin);

ret_status gpio_port_direction_intialize(port_index port, direction_t direction);
ret_status gpio_port_get_direction_status(port_index port, direction_t *direction);
ret_status gpio_port_write_value(port_index port, uint8_t value);
ret_status gpio_port_read_value(port_index port, uint8_t *value);
ret_status gpio_port_toggle_value(port_index port);

#endif	/* MCAL_GPIO_H */

