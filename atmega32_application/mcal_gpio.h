/*
* mcal_gpio.h
*
* Created: 10/27/2020 10:07:51 PM
*  Author: Khelad Mohamed
*/



#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

#include "atmega32_application.h"

#define PORT_PIN_MAX_NUMBERS 8U
#define PORT_MAX_NUMBERS 4U

typedef enum {
	PIN_LOW,
	PIN_HIGH
}pin_logic;

typedef enum {
	DIRECTION_INPUT,
	DIRECTION_OUTPUT
}direction_t;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}pin_index;

typedef enum {
	PORTA_INDEX,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX
}port_index;

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

#endif /* MCAL_GPIO_H_ */