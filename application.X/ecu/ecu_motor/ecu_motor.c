/* 
 * File:   ecu_motor.c
 * Author: Khelad Mohamed
 *
 * Created on October 24, 2020, 8:14 PM
 */
#include <stdlib.h>
#include "ecu_motor.h"

/**
 * 
 * @param led
 * @return 
 */
ret_status motot_initialize(motor_t *motor) {
    ret_status ret = R_NOK;
    if ((NULL == motor)) {
        return ret;
    } else {
        relay_initialize(&(motor->relay_1));
        relay_initialize(&(motor->relay_2));
        return R_OK;
    }
}

/**
 * 
 * @param led
 * @return 
 */
ret_status motor_rotate_right(motor_t *motor) {
    ret_status ret = R_NOK;

    if ((NULL == motor)) {
        return ret;
    } else {
        relay_turn_on(&(motor->relay_1));
        relay_turn_off(&(motor->relay_2));
        return R_OK;
    }
}

/**
 * 
 * @param led
 * @return 
 */
ret_status motor_rotate_left(motor_t *motor) {
    ret_status ret = R_NOK;

    if ((NULL == motor)) {
        return ret;
    } else {
        relay_turn_on(&(motor->relay_2));
        relay_turn_off(&(motor->relay_1));
        return R_OK;
    }
}
/**
 * 
 * @param motor
 * @return 
 */
ret_status motor_stop(motor_t *motor) {
    ret_status ret = R_NOK;

    if ((NULL == motor)) {
        return ret;
    } else {
        relay_turn_off(&(motor->relay_1));
        relay_turn_off(&(motor->relay_2));
        return R_OK;
    }
}
