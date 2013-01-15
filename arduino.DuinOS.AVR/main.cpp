#include <Arduino.h>


unsigned portBASE_TYPE mainSetupPriority;
unsigned portBASE_TYPE mainSetupStackSize;
unsigned portBASE_TYPE mainLoopPriority;
unsigned portBASE_TYPE mainLoopStackSize;

xTaskHandle xHandleLoop;
xTaskHandle xHandleSetup;

void main_Task(void *pvParameters)
{
#if INCLUDE_vTaskDelete
	vTaskDelete(xHandleSetup);
#endif
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
		
} 

void setup_Task(void *pvParameters)
{

	setup();
	vTaskResume(xHandleLoop);
	vTaskSuspend(NULL);

}

int main(void)
{
	mainSetupPriority  = HIGH_PRIORITY;
	mainSetupStackSize = configMINIMAL_STACK_SIZE * 2;
	mainLoopPriority   = LOW_PRIORITY;
	mainLoopStackSize  = configMINIMAL_STACK_SIZE;
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif

//	setup();

	xTaskCreate(setup_Task, (signed portCHAR *) "setup", mainSetupStackSize, NULL, mainSetupStackSize, &xHandleSetup);

	xTaskCreate(main_Task, (signed portCHAR *) "main", mainLoopStackSize, NULL, mainLoopPriority, &xHandleLoop);
	vTaskSuspend(xHandleLoop);

	vTaskStartScheduler();

	for (;;);
        
	return 0;
}

