# Activity1 in action

|CASE1|CASE2|CASE3|CASE4|
|:--:|:--:|:--:|:--:|
|\image html Activity1(CASE1).png|\image html Activity1(CASE2).png|\image html Activity1(CASE3).png|\image html Activity1(CASE4).png|

## Code 
```
while(1){
    if( !(heaterIN_port&(1<<heaterIN_pin)) && !(btn_sensorIN_port&(1<<btn_sensorIN_pin)) ){
        ledOUT_port |= (1<<ledOUT_pin);//Turns the ledOUT on
    }
    else{
        ledOUT_port &= ~(1<<ledOUT_pin);//Turns the ledOUT off
    }
}
```
