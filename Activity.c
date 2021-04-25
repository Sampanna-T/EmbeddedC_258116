#include "user_utils.h"
#include "ADC.h"

int main(void){
    /*ACTIVITY1*/
    initialize();

    /*ACTIVITY2*/
    initADC();
    uint16_t temperature;

    while(1){
        /*ACTIVITY1*/
        actuator_control();
        
        /*ACTIVITY2*/
        temperature = readADC(0);
        _delay_ms(200);

    }
return 0;
}
