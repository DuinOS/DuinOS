
unsigned portBASE_TYPE mainLoopPriority;

void main_Task(void *pvParameters)
{
	for(;;)
		loop();
}


int main(void)
{
	//This is made prior to setup(), so this priority could be changed in setup():
	mainLoopPriority = LOW_PRIORITY;

	init();
	setup();

	xTaskCreate(main_Task, (signed portCHAR *) "main", configMINIMAL_STACK_SIZE, NULL, mainLoopPriority, NULL);
	vTaskStartScheduler();

	//Will not get here unless a task calls vTaskEndScheduler():
	for (;;);

	return 0;
}
