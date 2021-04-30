/**
 * @file Activity4.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief 
 * 
 * @version 0.1
 * 
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY4_H__
#define __ACTIVITY4_H__

#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL

#define BAUD 9600
#define BRC ((F_CPU/16/BAUD)-1)

#define TX_BUFFER_SIZE 128

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/**
 * @brief initializes all the registers necessary to perform transmission
 * 
 */
void initialize_tx();

/**
 * @brief transmission of 1 byte data
 * 
 * @param data 
 */
void start_tx(uint8_t data);

/**
 * @brief adds characters to the serial_buffer array and updates the write postion
 * 
 * @param data 
 */
void append_serial(char data);

/**
 * @brief 
 * 
 * @param data 
 */
void serial_write(char data[], uint8_t value);

#endif