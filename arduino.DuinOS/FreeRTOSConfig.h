/*
	FreeRTOS.org V5.3.0 - Copyright (C) 2003-2009 Richard Barry.

	This file is part of the FreeRTOS.org distribution.

	FreeRTOS.org is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License (version 2) as published
	by the Free Software Foundation and modified by the FreeRTOS exception.
	**NOTE** The exception to the GPL is included to allow you to distribute a
	combined work that includes FreeRTOS.org without being obliged to provide
	the source code for any proprietary components.  Alternative commercial
	license and support terms are also available upon request.  See the
	licensing section of http://www.FreeRTOS.org for full details.

	FreeRTOS.org is distributed in the hope that it will be useful,	but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
	more details.

	You should have received a copy of the GNU General Public License along
	with FreeRTOS.org; if not, write to the Free Software Foundation, Inc., 59
	Temple Place, Suite 330, Boston, MA  02111-1307  USA.


	***************************************************************************
	*                                                                         *
	* Get the FreeRTOS eBook!  See http://www.FreeRTOS.org/Documentation      *
	*                                                                         *
	* This is a concise, step by step, 'hands on' guide that describes both   *
	* general multitasking concepts and FreeRTOS specifics. It presents and   *
	* explains numerous examples that are written using the FreeRTOS API.     *
	* Full source code for all the examples is provided in an accompanying    *
	* .zip file.                                                              *
	*                                                                         *
	***************************************************************************

	1 tab == 4 spaces!

	Please ensure to read the configuration and relevant port sections of the
	online documentation.

	http://www.FreeRTOS.org - Documentation, latest information, license and
	contact details.

	http://www.SafeRTOS.com - A version that is certified for use in safety
	critical systems.

	http://www.OpenRTOS.com - Commercial support, development, porting,
	licensing and training services.
*/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <avr/io.h>

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

// XXX: rsanders testing
#define portBYTE_ALIGNMENT 1
#define DUINOS_USE_HEAP2 1


//##2009.10.29: These values may be improved:
#if defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__)

	//##Multiplo.Brain.M644:
	#define configUSE_PREEMPTION		1
	#define configUSE_IDLE_HOOK			0
	#define configUSE_TICK_HOOK			0

	//##20091029: Use compiler defined freq.:
	#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) F_CPU )
	//#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) 18432000 )

	#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
	//##For these big cpus, it's possible to define more priorities if necessary:
	#define configMAX_PRIORITIES		( ( unsigned portBASE_TYPE ) 3 )
	#define configMINIMAL_STACK_SIZE	( ( unsigned portSHORT ) 85 )
	//##Run experiments to test this value:
	#define configTOTAL_HEAP_SIZE		( (size_t ) ( 2048 ) )
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

	/* Set the following definitions to 1 to include the API function, or zero
	to exclude the API function. */
	#define INCLUDE_vTaskPrioritySet		1
	#define INCLUDE_uxTaskPriorityGet		1
	//##If the following value is set to 1, change the memory managment scheme to heap_2.c:
	#define INCLUDE_vTaskDelete				0
	#define INCLUDE_vTaskCleanUpResources	0
	#define INCLUDE_vTaskSuspend			1
	#define INCLUDE_vTaskDelayUntil			1
	#define INCLUDE_vTaskDelay				1

#elif defined(__AVR_ATmega1284P__)

	//##Multiplo.Brain.M1284
	#define configUSE_PREEMPTION		1
	#define configUSE_IDLE_HOOK			0
	#define configUSE_TICK_HOOK			0

	//##20091029: Use compiler defined freq.:
	#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) F_CPU )
	//#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) 18432000 )

	#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
	//##For these big cpus, it's possible to define more priorities if necessary:
	#define configMAX_PRIORITIES		( ( unsigned portBASE_TYPE ) 3 )
	#define configMINIMAL_STACK_SIZE	( ( unsigned portSHORT ) 85 )
	//##Run experiments to test this value:
	#define configTOTAL_HEAP_SIZE		( (size_t ) ( 4096 ) )
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

	/* Set the following definitions to 1 to include the API function, or zero
	to exclude the API function. */
	#define INCLUDE_vTaskPrioritySet		1
	#define INCLUDE_uxTaskPriorityGet		1
	//##If the following value is set to 1, change the memory managment scheme to heap_2.c:
	#define INCLUDE_vTaskDelete				0
	#define INCLUDE_vTaskCleanUpResources	0
	#define INCLUDE_vTaskSuspend			1
	#define INCLUDE_vTaskDelayUntil			1
	#define INCLUDE_vTaskDelay				1

#elif defined(__AVR_ATmega1280__)
	//##Arduino Mega? Not tested yet:

	#define configUSE_PREEMPTION		1
	#define configUSE_IDLE_HOOK			0
	#define configUSE_TICK_HOOK			0

	//##20091029: Use compiler defined freq.:
	#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) F_CPU )
	//#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) 16000000 )

	#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
	//##For these bigger cpus, it's possible to define more priorities if necessary:
	#define configMAX_PRIORITIES		( ( unsigned portBASE_TYPE ) 3 )
	#define configMINIMAL_STACK_SIZE	( ( unsigned portSHORT ) 85 )
	//##Run experiments to test this value:
	#define configTOTAL_HEAP_SIZE		( (size_t ) ( 4096 ) )
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

	/* Set the following definitions to 1 to include the API function, or zero
	to exclude the API function. */
	#define INCLUDE_vTaskPrioritySet		1
	#define INCLUDE_uxTaskPriorityGet		1
	//##If the following value is set to 1, change the memory managment scheme to heap_2.c:
	#define INCLUDE_vTaskDelete				0
	#define INCLUDE_vTaskCleanUpResources	0
	#define INCLUDE_vTaskSuspend			1
	#define INCLUDE_vTaskDelayUntil			1
	#define INCLUDE_vTaskDelay				1

#elif defined(__AVR_ATmega328P__)
	//##Mega328p:

	#define configUSE_PREEMPTION		1
	#define configUSE_IDLE_HOOK			0
	#define configUSE_TICK_HOOK			0

	//##20091029: Use compiler defined freq.:
	#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) F_CPU )
	//#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) 12000000 )

	#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
	//##For these bigger cpus, it's possible to define more priorities if necessary:
	#define configMAX_PRIORITIES		( ( unsigned portBASE_TYPE ) 3 )
	#define configMINIMAL_STACK_SIZE	( ( unsigned portSHORT ) 85 )
	#define configTOTAL_HEAP_SIZE		( (size_t ) ( 1200 ) )
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

	/* Set the following definitions to 1 to include the API function, or zero
	to exclude the API function. */
	#define INCLUDE_vTaskPrioritySet		0
	#define INCLUDE_uxTaskPriorityGet		0
	#define INCLUDE_vTaskDelete				1
	#define INCLUDE_vTaskCleanUpResources	1
	#define INCLUDE_vTaskSuspend			1
	#define INCLUDE_vTaskDelayUntil			1
	#define INCLUDE_vTaskDelay				1

#elif defined(__AVR_ATmega88__) || defined(__AVR_ATmega88P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__)
	//##Mega88, Mega88p, Mega168, Mega168p:

	#define configUSE_PREEMPTION		1
	#define configUSE_IDLE_HOOK			0
	#define configUSE_TICK_HOOK			0

	//##20091029: Use compiler defined freq.:
	#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) F_CPU )
	//#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) 12000000 )

	#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
	//##For these bigger cpus, it's possible to define more priorities if necessary:
	#define configMAX_PRIORITIES		( ( unsigned portBASE_TYPE ) 3 )
	#define configMINIMAL_STACK_SIZE	( ( unsigned portSHORT ) 85 )
	#define configTOTAL_HEAP_SIZE		( (size_t ) ( 800 ) )
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

	/* Set the following definitions to 1 to include the API function, or zero
	to exclude the API function. */
	#define INCLUDE_vTaskPrioritySet		0
	#define INCLUDE_uxTaskPriorityGet		0
	#define INCLUDE_vTaskDelete				0
	#define INCLUDE_vTaskCleanUpResources	0
	#define INCLUDE_vTaskSuspend			1
	#define INCLUDE_vTaskDelayUntil			1
	#define INCLUDE_vTaskDelay				1

#else
	#error "Device is not supported by DuinOS"

#endif

#if !defined(DUINOS_USE_HEAP1) && ! defined(DUINOS_USE_HEAP2) && !defined(DUINOS_USE_HEAP3)
  #define DUINOS_USE_HEAP1 1
#endif


#endif /* FREERTOS_CONFIG_H */
