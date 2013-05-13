 int main( void )
    {
        /* Setup the microcontroller hardware for the demo. */
        prvSetupHardware();

        /* Create the common demo application tasks, for example: */
        vCreateFlashTasks();
        vCreatePollQTasks();
        vCreateComTestTasks();
       // Etc.

        /* Create any tasks defined within main.c itself, or otherwise specific to the
        demo being built. */
        //xTaskCreate( vCheckTask, "check", STACK_SIZE, NULL, TASK_PRIORITY, NULL );
        //Etc.

       /*Start the RTOS scheduler, this function should not return as it causes the execution
        context to change from main() to one of the created tasks. */
        vTaskStartScheduler();

        /* Should never get here! */
        return 0;
    }
