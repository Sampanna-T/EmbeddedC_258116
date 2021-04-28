/**
 * @file Activity3.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains function to perform PWM (8bit)
 * 
 * @version 0.1
 * 
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL

/**
 * @brief defining all the ports and pins necessary to produce PWM output
 * 
 */
#define PWM_ddr DDRD
#define PWM_pin DDD6 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


/**
 * @brief configures PWM pin as INPUT
 * 
*/
void config_PWM_PIN();


/**
 * @brief  initializes all the registers and pins to set up for PWM
 * 
 */
void initialize_PWM();


/**
 * @brief starts generating PWM wave at PWM pin
 * 
 * @param t_on
 */
void start_PWM(uint8_t t_on);