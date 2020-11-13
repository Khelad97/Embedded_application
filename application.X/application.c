/*
 * File:   application.c
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:09 PM
 */

#include "application.h"
lcd_t lcd_1 = {
    .lcd_data_port = PORTC_INDEX,
    .lcd_rs_port = PORTD_INDEX,
    .lcd_en_port = PORTD_INDEX,
    .lcd_rs_pin = PIN0,
    .lcd_en_pin = PIN1
};

int main() {
    lcd_intialize(&lcd_1);

    lcd_send_string_data_pos(&lcd_1, 1, 1, "Time :");
    uint16_t h,m,s,hours[4],min[4],sec[4];
    
    while (TRUE) {
        for (h = 0; h < 12; h++) {
            for (m = 0; m < 60; m++) {
                for (s = 0; s < 60; s++) {
                    byte_to_string(h,&hours);
                    byte_to_string(m,&min);
                    byte_to_string(s,&sec);
                    lcd_send_string_data_pos(&lcd_1, 1, 7, hours);
                    lcd_send_string_data_pos(&lcd_1, 1, 9, ":");
                    lcd_send_string_data_pos(&lcd_1, 1, 10, min);
                    lcd_send_string_data_pos(&lcd_1, 1, 12, ":");
                    lcd_send_string_data_pos(&lcd_1, 1, 13, sec);
                }
                lcd_send_string_data_pos(&lcd_1, 1, 13, "  ");
            }
            lcd_send_string_data_pos(&lcd_1, 1, 10, " ");
        }
        

    }
}


