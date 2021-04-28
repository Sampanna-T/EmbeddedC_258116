#include "Activity3.h"

volatile uint8_t count=0;
volatile uint8_t flag=0;

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

    /*Timer2 initialization is done*/
    TCCR2B |= (1<<CS22)|(1<<CS21)|(1<<CS20);//select prescaler of 1024
    TIMSK2 |= (1<<TOIE2);//enable interrupt on overflow
    TCNT0 = 0;//initialize the counter
    sei();//enable external interrupt
}


/**
 * @brief starts generating PWM wave at PWM pin
 * 
 * @param t_on
 */
void start_PWM(uint8_t t_on){
    if(flag==0)//after every 0.2 second OCR0A value will be updated if this function is called
        OCR0A = t_on;
}


ISR(TIMER2_OVF_vect){
    count = count+1;
    if(count>=12){//0.2sec delay
        flag ^= 1;
        count = 0;
    }
}