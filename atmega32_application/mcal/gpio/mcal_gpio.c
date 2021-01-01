/*
* mcal_gpio.c
*
* Created: 10/27/2020 10:07:29 PM
*  Author: Khelad Mohamed
*/


#include "mcal_gpio.h"


static volatile uint8_t *ddr_register[] = {&DDRA, &DDRB, &DDRC, &DDRD}; 
static volatile uint8_t *port_register[] = {&PORTA, &PORTB, &PORTC, &PORTD};  
static volatile uint8_t *pin_register[] = {&PINA, &PINB, &PINC, &PIND}; 


ret_status gpio_pin_direction_intialize(port_index port, pin_index pin, direction_t direction) {
    ret_status ret = R_NOK;
    if (pin > PORT_PIN_MAX_NUMBERS - 1) {
        return ret;
    } else {
        switch (direction) {
            case DIRECTION_OUTPUT:
                SET_BIT(*ddr_register[port], pin);
                ret = R_OK;
                break;
            case DIRECTION_INPUT:
                CLR_BIT(*ddr_register[port], pin);
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
        *direction = READ_BIT(*ddr_register[port],pin);
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
                CLR_BIT(*port_register[port], pin);
                ret = R_OK;
                break;
            case PIN_HIGH:
                SET_BIT(*port_register[port], pin);
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
        *logic = READ_BIT(*pin_register[port],pin);
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
        TOG_BIT(*port_register[port],pin);;
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
            case DIRECTION_INPUT:
                *ddr_register[port] = 0x00;
                ret = R_OK;
                break;
            case DIRECTION_OUTPUT:
                *ddr_register[port] = 0xFF;
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
        *direction = *ddr_register[port];
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
        *port_register[port] = value;
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
        *value = *pin_register[port];
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
        TOG_PORT(*port_register[port]);
        ret = R_OK;
    }
    return ret;
}


