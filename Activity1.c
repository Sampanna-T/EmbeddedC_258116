#include "user_utils.h"

int main(void){
    initialize();
    while(1){
        actuator_control();
    }
return 0;
}
