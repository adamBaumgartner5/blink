// This minimal Azure Sphere app repeatedly toggles an LED. Use this app to test that
// installation of the device and SDK succeeded, and that you can build, deploy, and debug an app.

#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include <applibs/log.h>
#include <applibs/gpio.h>
#include <hw/template_appliance.h>

typedef enum {
    ExitCode_Success = 0,
    ExitCode_Main_Led = 1
} ExitCode;

int main(void)
{
    int led1_r = GPIO_OpenAsOutput(LED1_R, GPIO_OutputMode_PushPull, GPIO_Value_High);
    int led1_g = GPIO_OpenAsOutput(LED1_G, GPIO_OutputMode_PushPull, GPIO_Value_High);
    int led1_b = GPIO_OpenAsOutput(LED1_B, GPIO_OutputMode_PushPull, GPIO_Value_High);

    if (led1_r < 0){
        return ExitCode_Main_Led;
    }

    const struct timespec sleepTime = {.tv_sec = 1, .tv_nsec = 0};

    while (true) {
        GPIO_SetValue(led1_r, GPIO_Value_High);
        GPIO_SetValue(led1_g, GPIO_Value_High);
        GPIO_SetValue(led1_b, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);
        GPIO_SetValue(led1_r, GPIO_Value_Low);
        GPIO_SetValue(led1_g, GPIO_Value_High);
        GPIO_SetValue(led1_b, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);
        GPIO_SetValue(led1_r, GPIO_Value_High);
        GPIO_SetValue(led1_g, GPIO_Value_Low);
        GPIO_SetValue(led1_b, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);
        GPIO_SetValue(led1_r, GPIO_Value_High);
        GPIO_SetValue(led1_g, GPIO_Value_High);
        GPIO_SetValue(led1_b, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);
    }
}