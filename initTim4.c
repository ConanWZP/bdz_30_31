#include "initTim4.h"


TIM_HandleTypeDef timerFour;

void initTim4(void){
	//init timer
	__HAL_RCC_TIM4_CLK_ENABLE();

	timerFour.Instance = TIM4;

	timerFour.Init.Prescaler = 13;
	timerFour.Init.CounterMode = TIM_COUNTERMODE_UP;
	timerFour.Init.Period = 1000;


	HAL_TIM_Base_Init(&timerFour);
	
}
