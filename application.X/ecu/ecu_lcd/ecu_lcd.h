/* 
 * File:   ecu_lcd.h
 * Author: Khelad Mohamed
 *
 * Created on October 30, 2020, 8:15 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H


#include"../../mcal/mcal_gpio/mcal_gpio.h"

#define CHAR_LCD_MODE 8
/************* LCD commands *************/
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE                 0X06
#define _LCD_CURSOR_OFF_DISPLAY_ON      0X0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF     0x08
#define _LCD_CURSOR_ON_BLINK_ON         0x0F
#define _LCD_CURSOR_ON_BLINK_OFF        0x0E
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28
#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

typedef struct {
#if CHAR_LCD_MODE == 8
    uint8_t lcd_data_port : 4;
    uint8_t lcd_en_port : 4;
    uint8_t lcd_rs_port : 4;
    uint8_t lcd_en_pin : 3;
    uint8_t lcd_rs_pin : 3;
    uint8_t lcd_status : 6;
#elif CHAR_LCD_MODE ==4
    uint8_t lcd_data_port : 6;
    uint8_t lcd_data_pin4 : 3;
    uint8_t lcd_data_pin5 : 3;
    uint8_t lcd_data_pin6 : 3;
    uint8_t lcd_data_pin7 : 3;
    uint8_t lcd_en_pin : 3;
    uint8_t lcd_rs_pin : 3;
#else
#endif
} lcd_t;

void lcd_intialize(const lcd_t *lcd);
void lcd_set_cursor(const lcd_t *lcd, uint8_t row, uint8_t coulmn);
void lcd_send_enable(const lcd_t *lcd);
void lcd_send_4bit(const lcd_t *lcd, uint8_t data);
void lcd_send_command(const lcd_t *lcd, uint8_t command);
void lcd_send_char_data(const lcd_t *lcd, uint8_t data);
void lcd_send_char_data_pos(const lcd_t *lcd, uint8_t row, uint8_t coulmn, uint8_t data);
void lcd_send_string_data_current_pos(const lcd_t *lcd, uint8_t *data);
void lcd_send_string_data_pos(const lcd_t *lcd, uint8_t row, uint8_t coulmn, uint8_t *data);
void lcd_send_custome_char(const lcd_t *lcd, uint8_t row, uint8_t coulmn, const char arr[], uint8_t pos);
void lcd_clear_display(const lcd_t *lcd);

void byte_to_string(uint8_t number, uint8_t *output);
void short_to_string(uint16_t number, uint8_t *output);
void int_to_string(uint32_t number, uint8_t *output);

#endif	/* ECU_LCD_H */
