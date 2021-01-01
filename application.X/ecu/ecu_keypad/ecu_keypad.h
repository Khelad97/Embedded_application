/* 
 * File:   ecu_keypad.h
 * Author: Khelad Mohamed
 *
 * Created on November 16, 2020, 12:54 PM
 */
#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section: Include */
#include "../../mcal/mcal_gpio/mcal_gpio.h"

#define KEYPAD_ROW      4
#define KEYPAD_COLUMNS  4

typedef struct{
    uint8_t port_name : 4;
    uint8_t pin_number : 4;
}keypad_pin_t;

typedef struct{
    keypad_pin_t keypad_rows[KEYPAD_ROW];
    keypad_pin_t keypad_columns[KEYPAD_COLUMNS];
}keypad_t;

ret_status keypad_initialize(const keypad_t *_keypad);
uint8_t keypad_read_value(const keypad_t *_keypad);

#endif	/* ECU_KEYPAD_H */

