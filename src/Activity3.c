/**
 * @file Activity3.c
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
#include "Activity3.h"

volatile uint8_t count_timer2=0;
volatile uint8_t flag_timer2=0;

/**
 * @brief configures PWM pin as INPUT
 * 
*/
void config_PWM_PIN(){
    PWM_ddr |= (1<<PWM_pin);
}


/**
 * @brief  initializes all the registers and pins to set up for PWM
 * 
 */
void initialize_PWM(){
        
    TCCR0A |= (1<<COM0A1); //clears OCOA on compare match and sets OCOA=1
    TCCR0A |= (1<<WGM00)|(1<<WGM01);//mode of Operation is fast PWM and top=0xFF
    TCCR0B |= (1<<CS01)|(1<<CS00);// select prescaler of 64 (i.e clk/64)
    TCNT0 = 0;//initialize the count_timer2er0

    /*Timer2 initialization is done*/
    TCCR2B |= (1<<CS22)|(1<<CS21)|(1<<CS20);//select prescaler of 1024
    TIMSK2 |= (1<<TOIE2);//enable interrupt on overflow
    TCNT2 = 0;//initialize count_timer2er2
    sei();//enable external interrupt
}


/**
 * @brief starts generating PWM wave at PWM pin
 * 
 * @param t_on
 */
void start_PWM(uint8_t t_on){
    if(flag_timer2==1){//after every 0.2 second OCR0A value will be updated if this function is called
        OCR0A = t_on;
        flag_timer2=0;
    }
}


ISR(TIMER2_OVF_vect){
    count_timer2 = count_timer2+1;
    if(count_timer2>=12){//0.2sec delay
        flag_timer2 = 1;
        count_timer2 = 0;
    }
}
