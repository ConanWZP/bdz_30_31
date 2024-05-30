#include "pwmSetPulse.h"




void pwmSetPulse(uint32_t pulse, TIM_HandleTypeDef timerFour){

	TIM_OC_InitTypeDef timerShim;
	
	timerShim.OCMode = TIM_OCMODE_PWM1;
	
	timerShim.OCPolarity = TIM_OCPOLARITY_HIGH;
	
	timerShim.OCFastMode = TIM_OCFAST_DISABLE;
	
	timerShim.OCIdleState = TIM_OCNIDLESTATE_SET;
	
	timerShim.Pulse = pulse;
	
	
		// init shim, where timerShim imported from pwtSetPulse.h (c) 
	HAL_TIM_PWM_ConfigChannel(&timerFour, &timerShim, TIM_CHANNEL_3 );



	// turn on generation of shim
	HAL_TIM_PWM_Start(&timerFour, TIM_CHANNEL_3);
	
}
