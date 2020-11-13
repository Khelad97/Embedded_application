/* 
 * File:   ecu_motor.h
 * Author: Khelad Mohamed
 *  
 * Created on October 24, 2020, 8:15 PM
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H


#include"../ecu_relay/ecu_relay.h"

typedef enum {
    MOTOR_OFF,
    MOTOR_ON
} motor_status;

typedef struct {
    relay_t relay_1;
    relay_t relay_2;
} motor_t;

ret_status motot_initialize(motor_t *motor);

ret_status motor_rotate_right(motor_t *motor);

ret_status motor_rotate_left(motor_t *motor);

ret_status motor_stop(motor_t *motor);

#endif	/* ECU_MOTOR_H */

