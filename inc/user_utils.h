/**
 * @file user_utils.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief defines all the functions necessary for the project 
 * 
 * @version 0.1
 *
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __USER_UTILS_H__
#define __USER_UTILS_H__

#include "project_config.h"
#include <avr/io.h>
#include <util/delay.h>

void initialize();//to configure pins as input and output

void actuator_control();//to control actuator based on heaterIN and btn_sensorIN values

#endif