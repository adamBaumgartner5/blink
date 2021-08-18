
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
    int led1= GPIO_OpenAsOutput(LED1_R, GPIO_OutputMode_PushPull, GPIO_Value_High);

    if (led1 < 0){
        return ExitCode_Main_Led;
    }

    const struct timespec sleepTime = {.tv_sec = 1, .tv_nsec = 0};

    while (true) {
        Log_Debug("Hello World\n");
        GPIO_SetValue(led1, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);
        GPIO_SetValue(led1, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);
    }
}