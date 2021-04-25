/**
 * @file ADC.h
 * 
 * @author Sampanna T (kashi16sadan@gamil.com)
 * 
 * @brief gives all the functions for reading Analog values
 * 
 * @version 0.1
 * 
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ADC_H__
#define __ADC_H__

#include "project_config.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void initADC();//To initialize all the registers and pins to set up for ADC

uint16_t readADC(uint8_t);//reads the analog value and returns it 


#endif
