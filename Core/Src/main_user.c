#include "main_user.h"
#include "stm32746g_discovery.h"
#include "cmsis_os.h"
#include <stdio.h>

#define TOGGLE_LED 1
#define BUTTON_ALARM_SET 2
#define BUTTON_ALARM_CLEAR 3

extern osMessageQueueId_t buttonQueueHandle;
extern osMessageQueueId_t guiQueueHandle;

void StartButtonAndLEDTask(void* argument)
{ 
    BSP_LED_Init(LED_GREEN);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    static uint16_t msg = 0;
//    uint16_t last_btn_state = 0;
//    uint16_t btn_state = 0;
    uint8_t LED_Toggle_enable = 0;
    uint16_t app_signal_state = 0;
    uint16_t last_app_signal_state = 0;
    for (;;)
    {
        osDelay(500); // changed to 0.5 sec to avoid ambigous state
        if (osMessageQueueGet(guiQueueHandle, &msg, 0U, 0) == osOK)
        {
            if (msg == TOGGLE_LED)
            {
                LED_Toggle_enable = !LED_Toggle_enable;
            }
        }
        if (LED_Toggle_enable)
        {
            BSP_LED_Toggle(LED_GREEN);
        }
/*
        btn_state = BSP_PB_GetState(BUTTON_KEY);
        if (btn_state != last_btn_state)
        {
            msg = btn_state ? BUTTON_ALARM_SET : BUTTON_ALARM_CLEAR;
            osMessageQueuePut(buttonQueueHandle, &msg, 0U, 0);
            last_btn_state = btn_state;
        // gpio output example: pull-down required
        //           HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_6); // D2 pin
        //           printf("HAL_GPIO_TogglePin : %d, %d\r\n", GPIOG, GPIO_PIN_6);
        //           printf( "HAL_GPIO_ReadPin GPIOG GPIO_PIN_6(Board D2_pin): %d (0 reset, 1 set)\r\n", HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6));
        ///////////////////////////////////////////

        // gpio input example:
 //           printf( "HAL_GPIO_ReadPin GPIOG GPIO_PIN_6(Board D2): %d (0 reset, 1 set)\r\n", HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6));
        }
 */
        app_signal_state = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6);
        if ( app_signal_state != last_app_signal_state ) {
        	if ( app_signal_state == GPIO_PIN_RESET ) {
        		msg = BUTTON_ALARM_SET;
        	} else if (app_signal_state == GPIO_PIN_SET ) {
        		msg = BUTTON_ALARM_CLEAR;
        	}
        	osMessageQueuePut(buttonQueueHandle, &msg, 0U, 0);
        	last_app_signal_state = app_signal_state;
            printf( "HAL_GPIO_ReadPin GPIOG GPIO_PIN_6(Board D2): %d (0 reset, 1 set)\r\n", app_signal_state );
        }
    }

}


