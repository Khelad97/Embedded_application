/*
 * File:   application.c
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:09 PM
 */

#include "application.h"
#include "mcal/timers/mcal_timer0.h"

led_t led1 = {.port_name = PORTC_INDEX, .pin = PIN0, .led_stutus = LED_OFF};
led_t led2 = {.port_name = PORTC_INDEX, .pin = PIN1, .led_stutus = LED_OFF};
led_t led3 = {.port_name = PORTC_INDEX, .pin = PIN2, .led_stutus = LED_OFF};
led_t led4 = {.port_name = PORTC_INDEX, .pin = PIN3, .led_stutus = LED_OFF};

timer0_t timer_0 = {
    .TMR0_InterruptHandler = timer0_DefaultInterruptHandler,
    .timer_register_mode = TIMER0_16BIT_MODE,
    .timer_mode = TIMER0_TIMER_MODE,
    .timer_prescaler_mode = TIMER0_PRESCALER_ON_MODE,
    .timer_prescaler_value = TIMER0_PRESCALER_DIV_BY_16,
    .timer_preload_value = 3036,
    .timer_interrupt_mode = TIMER0_INTERRUPT_EN,
    .timer_current_edge_mode = TIMER0_RISING_MODE
};

int main() {
    application_initilaze();
    while (TRUE) {

    }
}

void application_initilaze(void) {
    ENABLE_GLOBAL_INTERRUPT();
    ENABLE_PERIPHERAL_INTERRUPT();
    led_initialize(&led1);
    led_initialize(&led2);
    led_initialize(&led3);
    led_initialize(&led4);
    timer0_initilize(&timer_0);
}

void timer0_DefaultInterruptHandler() {
    led_turn_toggle(&led1);
}