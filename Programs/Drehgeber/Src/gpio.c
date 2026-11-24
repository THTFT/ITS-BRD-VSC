#include "gpio.h"
#include "Legacy/stm32_hal_legacy.h"
#include "fsm.h"
#include "stm32f429xx.h"
#include <stdint.h>
#include <stdlib.h>


#define MASK_PIN_0  0x1U
#define MASK_PIN_1 (0x1U << 1)
#define MASK_PIN_5 (0x1U << 5)
#define MASK_PIN_6 (0x1U << 6)
#define MASK_PIN_7 (0x1U << 7)

int buffer_counter = 0;
int buffer_direction = 0;

void read_channels(int* channel_a, int* channel_b) {
    uint32_t idr = GPIOF->IDR;
    *channel_a = idr & MASK_PIN_0; //NOLINT
    *channel_b = ((idr & MASK_PIN_1) >> 1); //NOLINT
}

void set_leds_event(int counter) {
    counter = abs(counter);
    GPIOD->ODR = 0;
    GPIOD->ODR = (uint32_t) counter;
}

void set_led_forwards() {
    GPIOE->ODR = MASK_PIN_7;
}

void set_led_backwards() {
    GPIOE->ODR = MASK_PIN_6;
}

void set_leds_direction(int direction) {
    if (direction == FORWARDS) {
        set_led_forwards();
    }
    else if (direction == BACKWARDS) {
        set_led_backwards();
    }
}

void set_led_error() {
    GPIOE->ODR = MASK_PIN_5;
}

void set_leds() {
    int counter = get_state_counter();
    if(counter != buffer_counter){
        set_leds_event(counter);
        buffer_counter = counter;
    }
    int direction = get_event();
    if(direction != buffer_direction) {
        set_leds_direction(direction);
        buffer_direction = direction;  
    }
}

uint32_t read_s6() {
    uint32_t idr = GPIOF->IDR;
    return ((~idr & MASK_PIN_6) >> 6); //NOLINT
}
