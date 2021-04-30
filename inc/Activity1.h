/**
 * @file Activity1.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains declaration of functions necessary to control an led based on inputs from heater & button sensor pins 
 * 
 * @version 0.1
 *
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY1_H__
#define __ACTIVITY1_H__

#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL//defining the frequency of atmega328

/**
 * @brief defining all the ports and pins necessary for controlling the led
 * 
 */
#define led_ddr DDRB
#define led_port PORTB
#define led_pin PORTB0

#define btn_sensor_ddr DDRD
#define btn_sensor_port PIND
#define btn_sensor_pin PIND3
#define btn_sensor_pullup_port PORTD

#define heater_port_ddr DDRD
#define heater_port PIND
#define heater_pin PIND4
#define heater_pullup_port PORTD

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief configures led pin as OUTPUT
 *
 */
void config_ledPIN();

/**
 * @brief configures button sensor pin as INPUT
 * 
*/
void config_btn_sensorPIN();

/**
 * @brief configures heater pin as INPUT
 * 
 */
void config_heaterPIN();

/**
 * @brief  switches the led ON or OFF based on inputs from heaterPIN & btn_sensorPIN
 * 
 */
void start_ledPIN();

#endif