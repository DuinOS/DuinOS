/*
 * FreeRTOSConfigATmega168P.h
 *
 *  Created on: 27/01/2013
 *      Author: extracbd
 */

#ifndef FREERTOSCONFIGATMEGA168P_H_
#define FREERTOSCONFIGATMEGA168P_H_

	#define configMINIMAL_STACK_SIZE	( ( unsigned portSHORT ) 85 )
	//20101220 : decrease heap size from 800 to 500 - see http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1256745982/46#46
	#define configTOTAL_HEAP_SIZE		( (size_t ) ( 500 ) )
	//#define configMAX_TASK_NAME_LEN		( 8 )
	#define configMAX_TASK_NAME_LEN		( 16 )
	#define configUSE_TRACE_FACILITY	0
	#define configUSE_16_BIT_TICKS		1
	#define configIDLE_SHOULD_YIELD		0
	#define configQUEUE_REGISTRY_SIZE	0

	/* Co-routine definitions. */
	//##2009.10.20: defined as "0":
	#define configUSE_CO_ROUTINES 		0
	#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

	/* setup() and loop() parameters */
	#define configSETUP_STACK_SIZE          (configMINIMAL_STACK_SIZE * 2)
	#define configLOOP_STACK_SIZE           (configMINIMAL_STACK_SIZE)
	#define configSETUP_PRIORITY			HIGH_PRIORITY
	#define configLOOP_PRIORITY			LOW_PRIORITY

	/* Set the following definitions to 1 to include the API function, or zero
	to exclude the API function. */
	#define INCLUDE_vTaskPrioritySet		0
	#define INCLUDE_uxTaskPriorityGet		0
	#define INCLUDE_vTaskDelete				0
	#define INCLUDE_vTaskCleanUpResources	0
	#define INCLUDE_vTaskSuspend			1
	#define INCLUDE_vTaskDelayUntil			1
	#define INCLUDE_vTaskDelay				1
	#define INCLUDE_xTaskGetSchedulerState  0

#endif /* FREERTOSCONFIGATMEGA168P_H_ */
