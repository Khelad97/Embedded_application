/* 
 * File:   std_types.h
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 7:59 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SET_BIT(reg,bit)  (reg|=(1<<bit))
#define CLR_BIT(reg,bit)  (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)  (reg^=(1<<bit))
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define SET_PORT(reg) (reg |= 0xff)
#define CLR_PORT(reg) (reg &= ~0xff)
#define TOG_PORT(reg) (reg ^= 0xff)

#define ZERO_INIT 0
#define TRUE  1
#define FALSE 0

typedef enum {
    R_NOK,
    R_OK
} ret_status;

#endif	/* STD_TYPES_H */

