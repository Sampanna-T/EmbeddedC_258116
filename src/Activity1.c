/**
 * @file Activity1.c
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief contains implementation of functions necessary to control an led based on inputs from heater & button sensor pins 
 * 
 * @version 0.1
 *
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 * 
 */
#include "Activity1.h"

/**
 * @brief 
 * configures the ledPIN as OUTPUT
 */
void config_ledPIN(){
    led_ddr |= (1<<led_pin);//setting the pin of DATA DIRECTION REGISTER to OUTPUT
}


/**
 * @brief configures the btn_sensorPIN as INPUT
 */
void config_btn_sensorPIN(){
   btn_sensor_ddr &= ~(1<<btn_sensor_pin);//setting the pin of DATA DIRECTION REGISTER to INPUT
   btn_sensor_pullup_port |= (1<<btn_sensor_pin);//enabling the pullup resistor within atmega328
}


/**
 * @brief configures the heaterPIN as INPUT
 */
void config_heaterPIN(){
    heater_port_ddr &= ~(1<<heater_pin);//setting the pin of DATA DIRECTION REGISTER to INPUT
    heater_pullup_port |= (1<<heater_pin);//enabling the pullup resistor within atmega328
}


/**
 * @brief switches the led ON or OFF based on inputs from heaterPIN & btn_sensorPIN
 * 
 */
void start_ledPIN(){
    if( !(btn_sensor_port&(1<<btn_sensor_pin)) && !(heater_port&(1<<heater_pin)) ){
        //if both btn_sensor & heater pins are 1 then led turns on
        led_port |= (1<<led_pin);//Turns the led on
    }
    else{
        //if both btn_sensor & heater pins are not 1 then led turns off
        led_port &= ~(1<<led_pin);//Turns the led off
    }
}