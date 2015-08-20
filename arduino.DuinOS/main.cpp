#include <FreeRTOSConfig.h>
#include <Arduino.h>

unsigned portBASE_TYPE mainSetupPriority  = configSETUP_PRIORITY;
unsigned portBASE_TYPE mainSetupStackSize = configMINIMAL_STACK_SIZE * 5;
unsigned portBASE_TYPE mainLoopPriority   = configLOOP_PRIORITY;
unsigned portBASE_TYPE mainLoopStackSize  = configMINIMAL_STACK_SIZE;

xTaskHandle xHandleLoop;
xTaskHandle xHandleSetup;

void main_Task(void *pvParameters)
{
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
		
} 

void setup_Task(void *pvParameters)
{

	setup();

	xTaskCreate(main_Task, (signed portCHAR *) "main", mainLoopStackSize, NULL, mainLoopPriority, &xHandleLoop);

#if INCLUDE_vTaskDelete
	vTaskDelete(xHandleSetup);
#else
	while(true) vTaskSuspend(NULL);
#endif

}

int main(void)
{

	init();

#if defined(USBCON)
	USBDevice.attach();
#endif

	xTaskCreate(setup_Task, (signed portCHAR *) "setup", mainSetupStackSize, NULL, mainSetupPriority, &xHandleSetup);

	vTaskStartScheduler();

	for (;;);
        
	return 0;
}

