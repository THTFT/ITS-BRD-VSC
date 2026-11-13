#include "gpio.h"
#include "stm32f429xx.h"
#include <stdint.h>

#define IDR_MASK_PIN_0  0x1U
#define IDR_MASK_PIN_1 (0x1U << 1)

void read_channels(int* channel_a, int* channel_b) {
    uint32_t idr = GPIOF->IDR;
    *channel_a = idr & IDR_MASK_PIN_0; //NOLINT
    *channel_b = ((idr & IDR_MASK_PIN_1) >> 1); //NOLINT
}
