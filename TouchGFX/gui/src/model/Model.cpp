#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "cmsis_os.h"

#define LED_TOGGLE_SET 1
#define BUTTON_ALARM_SET 2
#define BUTTON_ALARM_CLEAR 3

extern "C"
{
    extern osMessageQueueId_t guiQueueHandle;
    extern osMessageQueueId_t buttonQueueHandle;
}

#endif

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
    // Check for messages from backend, with zero timeout
    static uint16_t msg = 0;
    if (osMessageQueueGet(buttonQueueHandle, &msg, 0U, 0) == osOK)
    {
        if (msg == BUTTON_ALARM_SET)
        {
            // Notify current presenter that an alarm is active
            modelListener->buttonAlarmOn();
        }
        else if (msg == BUTTON_ALARM_CLEAR)
        {
            // Notify current presenter that an alarm is no longer active
            modelListener->buttonAlarmOff();
        }
    }
#endif
}

void Model::toggleLED()
{
#ifndef SIMULATOR

#endif
}
