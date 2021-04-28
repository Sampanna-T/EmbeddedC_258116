/**
 * @file Activity2.c
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief 
 * 
 * @version 0.1
 * 
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Activity2.h"

/**
 * @brief holds the analog value in 8bit format
 */
volatile uint8_t analog_value=0;

/**
 * @brief initializes all the registers for setting up adc
 * 
 */
void initialize_adc(){
    ADMUX |= (1<<REFS0);//AREF connected to AVCC
    ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);//enables ADC and sets prescalar to 128
    ADCSRA |= (1<<ADIE);//Enables timer overflow interrupt
    sei();//enabling global interrupt flag
}

/**
 * @brief returns 1 if the channel is valid for atmega328
 * 
 * @param channel 
 * @return uint8_t 
 */
uint8_t is_channel_valid(uint8_t channel){
    
    if(channel>=0 && channel<=7){
        return 1;
    }
    return 0;
}


/**
 * @brief starts adc convertion for given channel
 * 
 * @param channel 
 */
void start_ADC(uint8_t channel){
    
    ADMUX &= 0xf8;//clearing MUX0,MUX1,MUX2 for setting up the channel
    if( !is_channel_valid(channel) )//if invalid channel is given, then ADC is not performed
        return;

    ADMUX |= channel;//select a particular ADC channel(i.e. 0,1,2,3,4,5,6,7)
    ADCSRA |= (1<<ADSC);//start Analog to Digital conversion

}

/**
 * @brief returns analog value in 8 bit format
 * 
 * @return uint8_t 
 */
uint8_t get_ADC(){
    return analog_value;//returns the read analog value
}

ISR(ADC_vect){
    analog_value = ADC/4;//sets the analog value in 8 bit format
}