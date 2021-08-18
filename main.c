#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <applibs/log.h>
#include <applibs/gpio.h>
#include <hw/template_appliance.h>

#define TIMER_uS 1000000

// Variables
clock_t now = 0; 
bool led_on;

int main(void)
{
    Log_Debug("Blink without nanosleep()\n");
    int led1= GPIO_OpenAsOutput(LED1_R, GPIO_OutputMode_PushPull, GPIO_Value_High);

    while (true) {

        if(clock() - now > TIMER_uS){
            now = clock();

            if(!led_on){
                led_on = true;
                GPIO_SetValue(led1, GPIO_Value_Low); // turn led on
                Log_Debug("%lu , %lu: Led on\n", clock(), now);
            } else {
                led_on = false;
                GPIO_SetValue(led1, GPIO_Value_High); // turn led off
                Log_Debug("%lu , %lu: Led off\n", clock(), now);
            }
        }
    }
}