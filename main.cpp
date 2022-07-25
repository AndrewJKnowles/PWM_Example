/*  PWM Example
*   ===========
*
*   Function:
*   This example shows two ways to control the PWM output to an LED. The first uses a pot to set the PWM
*   duty cycle, while the second cycles from 0% (Off) up to 100% duty cycle and then back to 0%. The first
*   example is commented out (Line 23 to 27) while the second example is define in lines 29 to 46.
*  
*   Circuit Schematic No.:  
*   Required Libraries:     
*
*   Authored by:            Andrew Knowles
*   Date:                   2021
*   Version:                1.0
*   Revision Date:          
*   MBED Studio Version:    1.4.1
*   MBED OS Version:        6.14.0
*   Board:	                NUCLEO L476RG*/

#include "mbed.h"

AnalogIn pot(PC_3);     //analogue input from pot
PwmOut red_LED(PB_0);   //PWM output to led

float pot_value;
float PWM_value = 0.0;  //set inital PWM value to 0.0 = 0%
float frequency = 100;  //set frequency to 100Hz

void init();

int main(){
    init();

    while (1) {
        /*PWM_value = pot.read();   //set the PWM_value equal to the pot value (pot reads between 0.0, 1.0 which sets the PWM between 0% and 100%)
        red_LED.write(PWM_value);   //write PWM duty cycle to LED

        printf(" Duty Cycle: %.2f\n", PWM_value);   
        ThisThread::sleep_for(20ms);*/

        if(PWM_value >= 0.0 && PWM_value <= 1.0){
            for(float PWM = 0.0; PWM <= 1.1; PWM += 0.1){   //cycle up from 0% duty cycle to 100% in increments of 10% 
                red_LED.write(PWM);                         //write PWM duty cycle to LED
                PWM_value = PWM;                            //store current duty cycle value
                printf(" Duty cycle: %.2f\n", PWM_value);

                ThisThread::sleep_for(500ms);
            }

        }else{
            for(float PWM = 1.0; PWM >= -0.0; PWM -= 0.1){  //cycle down from 100% duty cycle to 0% in increments of 10%
                red_LED.write(PWM);                         //write PWM duty cycle to LED
                PWM_value = PWM;                            //store current duty cycle value
                printf(" Duty cycle: %.2f\n", PWM_value);

                ThisThread::sleep_for(500ms);
            } 
        }
    }
}

void init(){
    red_LED.write(0);               //initialise led
    red_LED.period(1/frequency);    //set the period of the wave form as 1/100Hz
}
