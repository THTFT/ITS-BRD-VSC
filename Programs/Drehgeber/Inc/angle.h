/**
 * @file angle.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of errorhandler module.
 */

#ifndef ANGLE_H
#define ANGLE_H

double angle;
double angle_velocity;

/*
 ****************************************************************************************
 * @brief:  This function calculates the angle relative to the start.
 *
 * @return: void
 ****************************************************************************************/
void update_angle();

/*
 ****************************************************************************************
 * @brief:  This function calculates the angle velocity if the state has changed.
 *
 * @return: void
 ****************************************************************************************/
void update_angle_velocity();

/*
 ****************************************************************************************
 * @brief:  This function returns the angle relative to the start.
 *
 * @return: The angle in degrees.
 ****************************************************************************************/
double get_angle();

/*
 ****************************************************************************************
 * @brief:  This function returns the angle velocity if the state has changed.
 *
 * @return: The angle velocity in degrees/s.
 ****************************************************************************************/
double get_angle_velocity();

#endif