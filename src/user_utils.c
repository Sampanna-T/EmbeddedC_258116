#include "user_utils.h"
/**
 * @brief configures pins/ports as input or output
 * 
 */
void initialize(){
    DDRB |= (1<<ledOUT_pin);//configures ledOUT as output pin

    DDRD &= ~(1<<heaterIN_pin);//configures heaterIN as input pin
    DDRD &= ~(1<<btn_sensorIN_pin);//configures btn_sensorIN as input pin
}

/**
 * @brief controls led actuator based on heaterIN & btn_sensorIN
 * 
 */
void actuator_control(){
    if( !(heaterIN_port&(1<<heaterIN_pin)) && !(btn_sensorIN_port&(1<<btn_sensorIN_pin)) ){
        ledOUT_port |= (1<<ledOUT_pin);//Turns the ledOUT on
    }
    else{
        ledOUT_port &= ~(1<<ledOUT_pin);//Turns the ledOUT off
    }
}