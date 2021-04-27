/**
 * @file project_config.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief  defines all the pins used for the project
 * 
 * @version 0.1
 *
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __PROJECT_CONFIG_H__
#define __PROJECT_CONFIG_H__


#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL//defining the frequency of the microcontroller

#define heaterIN_port PIND//defining the port of heaterIN
#define heaterIN_pin PIND0//defining the pin of heaterIN

#define btn_sensorIN_port PIND//defining the port of btn_sensorIN
#define btn_sensorIN_pin PIND1//defining the pin of btn_sensorIN

#define ledOUT_port PORTB//defining the port of ledOUT
#define ledOUT_pin PORTB0//defining the pin of ledOUT


#endif

