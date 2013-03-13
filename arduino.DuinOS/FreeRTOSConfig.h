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
 * For each atmega or attiny chip have a file, you can reutilizes a existent
 * or create a new.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#ifndef FREERTOS_ARDUINO
#define FREERTOS_ARDUINO 1
#endif

#if defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__)
#include "FreeRTOSConfigATmega644.h"

#elif defined(__AVR_ATmega1284P__)
#include "FreeRTOSConfigATmega1284P.h"

#elif defined(__AVR_ATmega1280__)
#include "FreeRTOSConfigATmega1280.h"

#elif defined(__AVR_ATmega2560__)
#include "FreeRTOSConfigATmega2560.h"

#elif defined(__AVR_ATmega328P__)
#include "FreeRTOSConfigATmega328P.h"

#elif defined(__AVR_ATmega88__) || defined(__AVR_ATmega88P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__)
#include "FreeRTOSConfigATmega168P.h"
#else
#error "Device is not supported by DuinOS"

#endif

#ifndef configUSE_PREEMPTION
#define configUSE_PREEMPTION		1
#endif

#ifndef configUSE_IDLE_HOOK
#define configUSE_IDLE_HOOK			0
#endif

#ifndef configUSE_TICK_HOOK
#define configUSE_TICK_HOOK			1
#endif

#ifndef configCPU_CLOCK_HZ
#define configCPU_CLOCK_HZ			( ( unsigned portLONG ) F_CPU )
#endif

#ifndef configTICK_RATE_HZ
#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
#endif

#ifndef configMAX_PRIORITIES
#define configMAX_PRIORITIES		( ( unsigned portBASE_TYPE ) 3 )
#endif

	/* setup() and loop() parameters */
#ifndef configSETUP_STACK_SIZE
	#define configSETUP_STACK_SIZE          (configMINIMAL_STACK_SIZE)
#endif
#ifndef configLOOP_STACK_SIZE
	#define configLOOP_STACK_SIZE           (configMINIMAL_STACK_SIZE)
#endif
#ifndef configSETUP_PRIORITY
	#define configSETUP_PRIORITY			HIGH_PRIORITY
#endif
#ifndef configLOOP_PRIORITY
	#define configLOOP_PRIORITY				LOW_PRIORITY
#endif

#if INCLUDE_vTaskDelete == 1
#define CONFIG_HEAP_MODEL 2
#else
#define CONFIG_HEAP_MODEL 1
#endif

#endif /* FREERTOS_CONFIG_H */
