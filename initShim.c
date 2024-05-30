#include "initShim.h"




void initShim(void){

	// comment because was said to do it in laba 4
	__HAL_RCC_GPIOD_CLK_ENABLE();

	// init shim
	GPIO_InitTypeDef SHIM;

	SHIM.Pin = GPIO_PIN_14;

	// altarate + push pull 
	SHIM.Mode = GPIO_MODE_AF_PP;

	SHIM.Alternate = GPIO_AF2_TIM4;

	SHIM.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(GPIOD, &SHIM);
	
}
