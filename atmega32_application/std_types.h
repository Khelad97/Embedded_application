/*
 * std_types.h
 *
 * Created: 10/28/2020 12:03:53 AM
 *  Author: Khelad Mohamed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;

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




#endif /* STD_TYPES_H_ */