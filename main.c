#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"


xTaskHandle hzapal_ziel;
xTaskHandle hzapal_czer;
portTASK_FUNCTION_PROTO( zapal_ziel, pvParameters );



/*void zapal_ziel(void *pvParameters)
{
 for(;;)
 {

  if(TIM_GetCounter(TIM3) == 200)
	   {
	        TIM_SetCounter(TIM3,0);
	        GPIO_SetBits(GPIOD,GPIO_Pin_12);

	   }

 }

}*/

void zapal_czer(void *pvParameters)
{

 for(;;)
 {
 	vTaskDelay( 500 / portTICK_RATE_MS );
	// if(TIM_GetCounter(TIM3)==200)
	      //{
	          //TIM_SetCounter(TIM3,0);
	          GPIO_ToggleBits(GPIOD,GPIO_Pin_14);
	      //}
 }
}


int main(void)
{
	SystemInit();

	/* GPIOD Periph clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE) ;
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE) ;


	GPIO_InitTypeDef  GPIO_InitStructure;
	/* Configure PD12, PD13, PD14 and PD15 in output pushpull mode*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/*TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure ;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000-1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 2000;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0 ;

	// przypisanie struktury do odpowiedniego timer'a
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);


	// uruchomienie timer'a
	TIM_Cmd(TIM3, ENABLE);
	TIM_Cmd(TIM4, ENABLE);*/


	xTaskCreate(zapal_ziel,NULL,configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, &hzapal_ziel);
	xTaskCreate(zapal_czer,NULL,configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, &hzapal_czer);

	vTaskStartScheduler();

	while(1)
	   {
	   }
}


portTASK_FUNCTION( zapal_ziel, pvParameters ) {

    portTickType xLastWakeTime;

    xLastWakeTime = xTaskGetTickCount();

    for(;;) {

        vTaskDelayUntil( &xLastWakeTime, ( 50 / portTICK_RATE_MS ) );
        //if(TIM_GetCounter(TIM4)==300)
        	      //{
        	          //TIM_SetCounter(TIM4,0);
        	          GPIO_ToggleBits(GPIOD,GPIO_Pin_12);
        	      //}
    }
}





