/*
 * File:   application.c
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:09 PM
 */


#include "application.h"

led_t led_0 = {. port_info.port_name = PORTC_INDEX, .port_info.pin = PIN0, .led_stutus = LED_OFF};
led_t led_1 = {. port_info.port_name = PORTC_INDEX, .port_info.pin = PIN1, .led_stutus = LED_OFF};
led_t led_2 = {. port_info.port_name = PORTC_INDEX, .port_info.pin = PIN2, .led_stutus = LED_OFF};

button_t btn = {.port_name = PORTD_INDEX, .pin = PIN0, .button_status = BUTTON_NOT_PRESSED};

uint8_t btn_status = ZERO_INIT;
uint8_t number_of_click = ZERO_INIT, number_of_task = ZERO_INIT, back = ZERO_INIT;

void task_0(void);
void task_1(void);
void task_2(void);
void task_3(void);
void task_4(void);

int main() {
    led_initialize(&led_0);
    led_initialize(&led_1);
    led_initialize(&led_2);
    button_initialize(&btn);
    button_get_status(&btn, &btn_status);
    while (TRUE) {
        button_get_status(&btn, &btn_status);
        /**
         * 
         * @return 
         */

        if ((btn_status == BUTTON_PRESSED) && back == 0) {

            number_of_task = number_of_click % 5;
            switch (number_of_task) {
                case 0:
                    task_0();
                    break;
                case 1:
                    task_1();
                    break;
                case 2:
                    task_2();
                    break;
                case 3:
                    task_3();
                    break;
                case 4:
                    task_4();
                    break;
            }
            number_of_click++;
            back = 1;
        } else if ((btn_status == BUTTON_NOT_PRESSED)) {
            back = 0;
        }
    }
}

void task_0(void) {
    led_turn_on(&led_0);
    __delay_ms(1000);
    led_turn_off(&led_0);
}

void task_1(void) {
    led_turn_on(&led_1);
    __delay_ms(1000);
    led_turn_off(&led_1);
    __delay_ms(1000);
    led_turn_on(&led_1);
    __delay_ms(1000);
    led_turn_off(&led_1);
}

void task_2(void) {
    led_turn_on(&led_2);
    __delay_ms(1000);
    led_turn_off(&led_2);
    __delay_ms(1000);
    led_turn_on(&led_2);
    __delay_ms(1000);
    led_turn_off(&led_2);
    __delay_ms(1000);
    led_turn_on(&led_2);
    __delay_ms(1000);
    led_turn_off(&led_2);
}

void task_3(void) {
    led_turn_on(&led_0);
    led_turn_on(&led_1);
    led_turn_on(&led_2);
}

void task_4(void) {
    led_turn_off(&led_0);
    led_turn_off(&led_1);
    led_turn_off(&led_2);
}
