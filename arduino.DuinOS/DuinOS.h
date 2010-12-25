#ifndef DuinOS__h
#define DuinOS__h

#ifndef FREERTOS_ARDUINO
  #define FREERTOS_ARDUINO 1
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <string.h>

//#ifdef GCC_MEGA_AVR
	/* EEPROM routines used only with the WinAVR compiler. */
	#include <avr/eeprom.h>
//#endif

/* Scheduler include files. */
#include "DuinOS/FreeRTOS.h"
#include "DuinOS/task.h"

#ifdef __cplusplus
} // extern "C"
#endif

extern unsigned portBASE_TYPE mainLoopPriority;

//In small devices, we use only 3 priorities:
#define LOW_PRIORITY		(tskIDLE_PRIORITY)
#define NORMAL_PRIORITY		(tskIDLE_PRIORITY + 1)
#define HIGH_PRIORITY		(tskIDLE_PRIORITY + 2)

#define taskLoop(name)\
void name##Function();\
xTaskHandle name;\
void name##_Task(void *pvParameters)\
{\
	for(;;)\
		name##Function();\
}\
void name##Function()

//This macro enables the forward declaration of a task, to allow other tasks previous defined (with the
//taskLoop()macro use and reference them:
#define declareTaskLoop(name) extern xTaskHandle name

#define createTaskLoop(name, priority)\
{\
	xTaskCreate(name##_Task, (signed portCHAR *) #name, configMINIMAL_STACK_SIZE, NULL, priority, &name);\
}

#define createTaskLoopWithStackSize(name, priority, ssize)\
{\
	xTaskCreate(name##_Task, (signed portCHAR *) #name, ssize, NULL, priority, &name);\
}

#define suspend() vTaskSuspend(NULL)

#define suspendTask(name) vTaskSuspend(name)

#define suspendAll() vTaskSuspendAll()

#define resumeTask(name) vTaskResume(name)

#define resumeAll() xTaskResumeAll()

#define nextTask() taskYIELD()

#define delay(ticks) vTaskDelay(ticks)
/*
inline void delay(const portTickType ticks)
{
	portTickType xLastWakeTime = xTaskGetTickCount();

	//Better than vTaskDelay:
	vTaskDelayUntil( &xLastWakeTime, ticks);
}
*/

//This macro is quiet different from setPriority, because this works even in those CPUs wich does not support
//the set/getPriority macros (due to their small RAM memories). And, this only has effect if called in setup().
#define initMainLoopPriority(priority) (mainLoopPriority = priority)

//These only works if INCLUDE_vTaskPrioritySet / INCLUDE_vTaskPriorityGet are != 0
//(disabled for CPUs with less than 2KB RAM):
#if INCLUDE_vTaskPriorityGet //This #if is to improve the error readability.
	#define getPriority(name) uxTaskPriorityGet(name)
#endif
#if INCLUDE_vTaskPrioritySet
	#define setPriority(name, priority) uxTaskPrioritySet(name, priority)
#endif

//##In bigger CPUs, DuinOS may use cTaskDelete, and uxTaskPrioritySet/Get.

#endif
