#include <Arduino.h>

unsigned portBASE_TYPE mainLoopPriority;

void main_Task(void *pvParameters)
{
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
}

int main(void) 
{
	mainLoopPriority = LOW_PRIORITY;

	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();

	xTaskCreate(main_Task, (signed portCHAR *) "main", configMINIMAL_STACK_SIZE, NULL, mainLoopPriority, NULL);
	vTaskStartScheduler();

	for(;;);

	return 0;
}

