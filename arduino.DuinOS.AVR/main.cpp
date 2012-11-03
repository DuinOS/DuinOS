#include <Arduino.h>


unsigned portBASE_TYPE mainLoopPriority;

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
	mainLoopPriority = LOW_PRIORITY;
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif

//	setup();

	xTaskCreate(setup_Task, (signed portCHAR *) "setup", configMINIMAL_STACK_SIZE, NULL, HIGH_PRIORITY, &xHandleSetup);

	xTaskCreate(main_Task, (signed portCHAR *) "main", configMINIMAL_STACK_SIZE, NULL, mainLoopPriority, &xHandleLoop);
	vTaskSuspend(xHandleLoop);

	vTaskStartScheduler();

	for (;;);
        
	return 0;
}

