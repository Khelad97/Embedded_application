/* 
 * File:   ecu_lcd.c
 * Author: Khelad Mohamed
 *
 * Created on October 30, 2020, 8:14 PM
 */

#include "ecu_lcd.h"

/**
 * 
 * @param _lcd
 */
void lcd_intialize(const lcd_t *lcd) {
#if CHAR_LCD_MODE == 8
    gpio_port_direction_intialize(lcd->lcd_data_port, PORT_DIRECTION_OUTPUT);
    gpio_port_write_value(lcd->lcd_data_port, PORT_ALL_CLEAR);
    gpio_pin_direction_intialize(lcd->lcd_en_port, lcd->lcd_en_pin, DIRECTION_OUTPUT);
    gpio_pin_write_value(lcd->lcd_en_port, lcd->lcd_en_pin, PIN_LOW);
    gpio_pin_direction_intialize(lcd->lcd_rs_port, lcd->lcd_rs_pin, DIRECTION_OUTPUT);
    gpio_pin_write_value(lcd->lcd_rs_port, lcd->lcd_rs_pin, PIN_LOW);
    __delay_ms(40);
    lcd_send_command(lcd, _LCD_8BIT_MODE_2_LINE); // 8 Bit Mode
    __delay_ms(5);
    lcd_send_command(lcd, _LCD_8BIT_MODE_2_LINE); // 8 Bit Mode
    __delay_us(300);
    lcd_send_command(lcd, _LCD_8BIT_MODE_2_LINE); // 8 Bit Mode

    lcd_send_command(lcd, _LCD_CLEAR);
    lcd_send_command(lcd, _LCD_RETURN_HOME);
    lcd_send_command(lcd, _LCD_ENTRY_MODE);
    lcd_send_command(lcd, _LCD_CURSOR_OFF_DISPLAY_ON);
    lcd_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
    lcd_send_command(lcd, 0x80);
#elif CHAR_LCD_MODE == 4 
    gpio_pin_direction_intialize(lcd->lcd_data_port, lcd->lcd_data_pin4, DIRECTION_OUTPUT);
    gpio_pin_direction_intialize(lcd->lcd_data_port, lcd->lcd_data_pin5, DIRECTION_OUTPUT);
    gpio_pin_direction_intialize(lcd->lcd_data_port, lcd->lcd_data_pin6, DIRECTION_OUTPUT);
    gpio_pin_direction_intialize(lcd->lcd_data_port, lcd->lcd_data_pin7, DIRECTION_OUTPUT);
    gpio_pin_direction_intialize(lcd->lcd_data_port, lcd->lcd_en_pin, DIRECTION_OUTPUT);
    gpio_pin_direction_intialize(lcd->lcd_data_port, lcd->lcd_rs_pin, DIRECTION_OUTPUT);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin4, PIN_LOW);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin5, PIN_LOW);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin6, PIN_LOW);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin7, PIN_LOW);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_en_pin, PIN_LOW);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_rs_pin, PIN_LOW);

    lcd_send_command(lcd, _LCD_CLEAR);
    lcd_send_command(lcd, _LCD_RETURN_HOME);
    lcd_send_command(lcd, _LCD_CURSOR_OFF_DISPLAY_ON);
    lcd_send_command(lcd, _LCD_DISPLAY_SHIFT_RIGHT);
    lcd_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
    lcd_send_command(lcd, _LCD_DDRAM_START);
#endif

}

/**
 * 
 * @param lcd
 */
void lcd_send_enable(const lcd_t *lcd) {
#if CHAR_LCD_MODE == 8
    gpio_pin_write_value(lcd->lcd_en_port, lcd->lcd_en_pin, PIN_HIGH);
    __delay_us(200);
    gpio_pin_write_value(lcd->lcd_en_port, lcd->lcd_en_pin, PIN_LOW);
#elif CHAR_LCD_MODE == 4 
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_en_pin, PIN_HIGH);
    __delay_us(200);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_en_pin, PIN_LOW);
#endif
}

/**
 * 
 * @param _lcd
 * @param row
 * @param coulmn
 */
void lcd_set_cursor(const lcd_t *lcd, uint8_t row, uint8_t coulmn) {
    coulmn=coulmn-1;
    switch (row) {
        case 1:
            lcd_send_command(lcd, (0x80 + coulmn));
            break;
        case 2:
            lcd_send_command(lcd, (0xC0 + coulmn));
            break;
        case 3:
            lcd_send_command(lcd, (0x94 + coulmn));
            break;
        case 4:
            lcd_send_command(lcd, (0xD4 + coulmn));
            break;
        default:
            break;
    }
}

/**
 * 
 * @param lcd
 * @param data
 */
void lcd_send_4bit(const lcd_t *lcd, uint8_t data) {
#if CHAR_LCD_MODE ==4
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin4, ((data >> 4)&0x01));
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin5, ((data >> 5)&0x01));
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin6, ((data >> 6)&0x01));
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin7, ((data >> 7)&0x01));
    lcd_send_enable(lcd);
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin4, ((data >> 0)&0x01));
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin5, ((data >> 1)&0x01));
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin6, ((data >> 2)&0x01));
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_data_pin7, ((data >> 3)&0x01));
    lcd_send_enable(lcd);
#endif
}

void lcd_send_command(const lcd_t *lcd, uint8_t command) {
#if CHAR_LCD_MODE == 8
    gpio_pin_write_value(lcd->lcd_rs_port, lcd->lcd_rs_pin, PIN_LOW);
    gpio_port_write_value(lcd->lcd_data_port, command);
    lcd_send_enable(lcd);
    __delay_ms(2);

#elif CHAR_LCD_MODE == 4 
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_rs_pin, PIN_LOW);
    lcd_send_4bit(lcd, command);

#endif

}

/**
 * 
 * @param lcd
 * @param data
 */
void lcd_send_char_data(const lcd_t *lcd, uint8_t data) {
#if CHAR_LCD_MODE == 8
    gpio_pin_write_value(lcd->lcd_rs_port, lcd->lcd_rs_pin, PIN_HIGH);
    gpio_port_write_value(lcd->lcd_data_port, data);
    lcd_send_enable(lcd);
#elif CHAR_LCD_MODE == 4 
    gpio_pin_write_value(lcd->lcd_data_port, lcd->lcd_rs_pin, PIN_HIGH);
    lcd_send_4bit(lcd, data);

#endif

}

/**
 * 
 * @param _lcd
 * @param row
 * @param coulmn
 * @param _data
 * @return 
 */
void lcd_send_char_data_pos(const lcd_t *lcd, uint8_t row, uint8_t coulmn, uint8_t data) {
    lcd_set_cursor(lcd, row, coulmn);
    lcd_send_char_data(lcd, data);
}

/**
 * 
 * @param _lcd
 * @param _data
 * @return 
 */
void lcd_send_string_data_current_pos(const lcd_t *lcd, uint8_t *data) {

    while (*data) {
        lcd_send_char_data(lcd, *data++);
        __delay_ms(1);
    }
}

/**
 * 
 * @param _lcd
 * @param row
 * @param coulmn
 * @param _data
 * @return 
 */
void lcd_send_string_data_pos(const lcd_t *lcd, uint8_t row, uint8_t coulmn, uint8_t * data) {

    lcd_set_cursor(lcd, row, coulmn);
    while (*data) {
        lcd_send_char_data(lcd, *data++);
        __delay_ms(1);
    }
}

/**
 * 
 * @param _lcd
 * @param row
 * @param coulmn
 * @param arr
 * @param _pos
 * @return 
 */
void lcd_send_custome_char(const lcd_t *lcd, uint8_t row, uint8_t coulmn, const char arr[], uint8_t pos) {

    uint8_t l_counter = 0;
    lcd_send_command(lcd, _LCD_CGRAM_START + (pos * 8));
    for (l_counter = 0; l_counter <= 7; l_counter++) {
        lcd_send_char_data(lcd, arr[l_counter]);
    }
    lcd_send_command(lcd, _LCD_RETURN_HOME);
    lcd_send_char_data_pos(lcd, row, coulmn, pos);


}

/**
 * 
 * @param _lcd
 * @return 
 */
void lcd_clear_display(const lcd_t * lcd) {
    lcd_send_command(lcd, _LCD_CLEAR);
}

/**
 * 
 * @param number
 * @param _output
 */
void byte_to_string(uint8_t number, uint8_t * output) {
    sprintf(output, "%i", number);
}

/**
 * 
 * @param number
 * @param _output
 */
void short_to_string(uint16_t number, uint8_t * output) {
    sprintf(output, "%i", number);
}

/**
 * 
 * @param number
 * @param _output
 */
void int_to_string(uint32_t number, uint8_t * output) {
    sprintf(output, "%i", number);
}
