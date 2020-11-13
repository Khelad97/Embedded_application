/* 
 * File:   mcal_gpio.c
 * Author: khelad Moahmed
 *
 * Created on October 22, 2020, 11:03 PM
 */

#include <stdlib.h>

#include "mcal_gpio.h"
#include"../../std_types.h"

static volatile uint8_t *tris_register[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};  // input or output 
static volatile uint8_t *lat_register[] = {&LATA, &LATB, &LATC, &LATD, &LATE};        // set high or low 
static volatile uint8_t *port_register[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};  // read status 
/**
 * 
 * @param port
 * @param pin
 * @param direction
 * @return 
 */
ret_status gpio_pin_direction_intialize(port_index port, pin_index pin, direction_t direction) {
    ret_status ret = R_NOK;
    if (pin > PORT_PIN_MAX_NUMBERS - 1) {
        return ret;
    } else {
        switch (direction) {
            case DIRECTION_OUTPUT:
                CLR_BIT(*tris_register[port], pin);
                ret = R_OK;
                break;
            case DIRECTION_INPUT:
                SET_BIT(*tris_register[port], pin);
                ret = R_OK;
                break;
            default:
                return R_NOK;
        }
    }
    return ret;
}
/**
 * 
 * @param port
 * @param pin
 * @param direction
 * @return 
 */
ret_status gpio_pin_get_direction_status(port_index port, pin_index pin, direction_t *direction) {
    ret_status ret = R_NOK;
    if (pin > PORT_PIN_MAX_NUMBERS - 1) {
        return ret;
    } else {
        *direction = ((*tris_register[port] >> pin)&1);
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param pin
 * @param logic
 * @return 
 */
ret_status gpio_pin_write_value(port_index port, pin_index pin, pin_logic logic) {
    ret_status ret = R_NOK;
    if (pin > PORT_PIN_MAX_NUMBERS - 1) {
        return ret;
    } else {
        switch (logic) {
            case PIN_LOW:
                CLR_BIT(*lat_register[port], pin);
                ret = R_OK;
                break;
            case PIN_HIGH:
                SET_BIT(*lat_register[port], pin);
                ret = R_OK;
                break;
            default:
                ret = R_NOK;
        }
    }
    return ret;
}
/**
 * 
 * @param port
 * @param pin
 * @param logic
 * @return 
 */
ret_status gpio_pin_read_value(port_index port, pin_index pin, pin_logic *logic) {
    ret_status ret = R_NOK;
    if (pin > PORT_PIN_MAX_NUMBERS - 1) {
        return ret;
    } else {
        *logic = ((*port_register[port] >> pin)&1);
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param pin
 * @return 
 */
ret_status gpio_pin_toggle_value(port_index port, pin_index pin) {
    ret_status ret = R_NOK;
    if (pin > PORT_PIN_MAX_NUMBERS - 1) {
        return ret;
    } else {
        *lat_register[port] ^= (1 << pin);
        ret = R_OK;
    }
    return ret;

}
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
ret_status gpio_port_direction_intialize(port_index port, direction_t direction) {
    ret_status ret = R_NOK;
    if (port > PORT_MAX_NUMBERS - 1) {
        return ret;
    } else {
        switch (direction) {
            case DIRECTION_OUTPUT:
                *tris_register[port] = 0x00;
                ret = R_OK;
                break;
            case DIRECTION_INPUT:
                *tris_register[port] = 0xFF;
                ret = R_OK;
                break;
            default:
                return R_NOK;
        }
    }
    return ret;

}
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
ret_status gpio_port_get_direction_status(port_index port, direction_t *direction) {
    ret_status ret = R_NOK;
    if (port > PORT_MAX_NUMBERS - 1 || NULL == direction) {
        return ret;
    } else {
        *direction = *tris_register[port];
        ret = R_OK;
    }
    return ret;

}
/**
 * 
 * @param port
 * @param value
 * @return 
 */
ret_status gpio_port_write_value(port_index port, uint8_t value) {
    ret_status ret = R_NOK;
    if (port > PORT_MAX_NUMBERS - 1) {
        return ret;
    } else {
        *lat_register[port] = value;
        ret = R_OK;
    }
    return ret;


}
/**
 * 
 * @param port
 * @param value
 * @return 
 */
ret_status gpio_port_read_value(port_index port, uint8_t *value) {
    ret_status ret = R_NOK;
    if (port > PORT_MAX_NUMBERS - 1 || NULL == value) {
        return ret;
    } else {
        *value = *port_register[port];
        ret = R_OK;
    }
    return ret;


}
/**
 * 
 * @param port
 * @return 
 */
ret_status gpio_port_toggle_value(port_index port) {
    ret_status ret = R_NOK;
    if (port > PORT_MAX_NUMBERS - 1) {
        return ret;
    } else {
        TOG_PORT(*lat_register[port]);
        ret = R_OK;
    }
    return ret;
}
