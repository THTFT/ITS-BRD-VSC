/**
 * @file gpio.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of gpio module.
 */

#ifndef GPIO_H
#define GPIO_H

/*
 ****************************************************************************************
 * @brief:  This function reads the channel a and b from the GPIO device.
 *
 * @return: The values are returned in the arguments of the function.
 ****************************************************************************************/
void read_channels(int* channel_a, int* channel_b);

#endif