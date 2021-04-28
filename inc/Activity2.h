/**
 * @file Activity2.h
 * 
 * @author Sampanna T (kashi16sadan@gamil.com)
 * 
 * @brief contains declaration of all the functions necessary for reading Analog values
 * 
 * @version 0.1
 * 
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY2_H__
#define __ACTIVITY2_H__

#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL//defining the frequency of the microcontroller

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/**
 * @brief  initializes all the registers and pins to set up for ADC
 * 
 */
void initialize_adc();

/**
 * @brief starts ADC conversion for a given channel
 * 
 * @param channel 
 */
void start_ADC(uint8_t channel); 

/**
 * @brief returns ADC value in 8 bit format
 * 
 * @return uint8_t 
 */
uint8_t get_ADC();


#endif
