#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"

int main(void){

    config_btn_sensorPIN();//configuring button sensor pin as input
    config_heaterPIN();//configuring heater pin an input
    config_ledPIN();//configuring ledpin as output

    initialize_adc();//initializing the registers to perform ADC
    
    config_PWM_PIN();//configuring the PWM pin as output
    initialize_PWM();//initializing the registers to perform PWM(8bit)

    while(1){
        start_ledPIN();//led actuator turns on when both button sensor and heater is on
        start_ADC(2);//Analog to digital conversion takes place and the result is stored in 8 bit format in analog_value variable
        start_PWM(get_ADC());//performs PWM on the read ADC value 
    }


    return 0;
}