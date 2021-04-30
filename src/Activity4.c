/**
 * @file Activity4.c
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

#include "Activity4.h"

char serial_buffer[TX_BUFFER_SIZE];//creating a buffer of size 128 bytes to hold data that needs to be transmitted
uint8_t serial_readPOS = 0;//the position ready for transmission
uint8_t serial_writePOS = 0;//the position ready to write

uint8_t count_timer1 = 0;
uint8_t flag_timer1 = 0;

/**
 * @brief initializes all the registers necessary to perform transmission
 * 
 */
void initialize_tx(){
    /*UBRR0H & UBRR0L holds value requird to set speed of transmission*/
    UBRR0H = BRC >> 8; 
    UBRR0L = BRC;
    UCSR0B |= (1<<TXEN0);//enabling the USART communication
    UCSR0B |= (1 << TXCIE0);//enabling the interrupt for tx completion
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);//8 bit per transmission
    sei();//enable external interrupts

    /*Timer2 initialization is done*/
    TCCR1B |= (1<<CS10);//select prescaler of 1
    TIMSK1 |= (1<<TOIE2);//enable interrupt on overflow
    TCNT1 = 0;//initialize the counter
    sei();//enable external interrupt
}

/**
 * @brief transmission of 1 byte data
 * 
 * @param data 
 */
void start_tx(uint8_t data){
    UDR0 = data;//data to be transmitted will be placed in this register
}

/**
 * @brief adds characters to the serial_buffer array and updates the write postion
 * 
 * @param data 
 */
void append_serial(char data){
    serial_buffer[serial_writePOS] = data;
    serial_writePOS++;
    if(serial_writePOS >= TX_BUFFER_SIZE){
        serial_writePOS = 0;
    }
}

/**
 * @brief prints the temperature value with C symbol indicating Celsius
 * 
 * @param value 
 */
void serial_write_temperature(uint8_t value){
    uint8_t digit1 = (value & 0x0f)+48; 
    uint8_t digit2 = (value>>4)+48;

    start_tx(digit2);//displays the tens's place
    start_tx(digit1);//displays the one's place
    start_tx(' ');//represents a space
    start_tx('C');//representing a Celsius
    start_tx('\n');//moves to the next line
}

/**
 * @brief 
 * 
 * @param data 
 */
void serial_write(char data[], uint8_t value){

    if(flag_timer1==1){
        uint8_t length = 0;//variable to find the length of the data
        uint8_t i;

        while(data[length] != '\0')length++;//calculating the length of data array
        
        for(i = 0; i < length; i++)//adding character data to the serial_buffer
            append_serial(data[i]);
        
        if(UCSR0A & (1<<UDRE0)){//if UDR0 is empty UDRE0 will be 1 hence the below statement will be executed
            UDR0=0;//This statement is to trigger the ISR so that serial_buffer data will be transmitted
        }
    serial_write_temperature(value);
    flag_timer1=0;//reset the flag once the data is transmitted
    }
    
}

ISR(USART_TX_vect){

    if(serial_readPOS != serial_writePOS){
        UDR0 = serial_buffer[serial_readPOS];//writing serial_buffer data one at at time to UDR0 for transmission
        serial_readPOS++;//incrementing the read position

        if(serial_readPOS >= TX_BUFFER_SIZE){
            serial_readPOS = 0;//start reading from the starting when the readPOS reaches the end
        }
    }
}


ISR(TIMER1_OVF_vect){
    count_timer1 = count_timer1+1;
    if(count_timer1>=244){//1sec delay
        flag_timer1 = 1;
        count_timer1 = 0;
    }
}