/**
 * @file gpio.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of gpio module.
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/*
 ****************************************************************************************
 * @brief:  This function reads the channel a and b from the GPIO device.
 *
 * @param   channel_a The adress for the return value of channel a.
 *          channel_b The adress for the return value of channel b.
 *
 * @return: void
 ****************************************************************************************/
void read_channels(int *channel_a, int *channel_b);

/*
 ****************************************************************************************
 * @brief:  Sets the error LED D21.
 *
 * @return: void
 ****************************************************************************************/
void set_led_error();

/*
 ****************************************************************************************
 * @brief:  Sets the LEDs of the fsm.
 *
 * @return: void
 ****************************************************************************************/
void set_leds();

/*
 ****************************************************************************************
 * @brief:  Reads the value of the button S6.
 *
 * @return: 0 if the button is not pressed, 1 if it is pressed.
 ****************************************************************************************/
uint32_t read_s6();

/*
 ****************************************************************************************
 * @brief:  Clears all LEDs. 
 *
 * @return: void
 ****************************************************************************************/
void clear_leds();

#endif