#include "leds.h"

void allLedsHalInit(void) {
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	GPIO_InitTypeDef allLedInit;
	
	allLedInit.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	
	allLedInit.Mode = GPIO_MODE_OUTPUT_PP;
	
	allLedInit.Speed = GPIO_SPEED_LOW;
	
	HAL_GPIO_Init(GPIOD, &allLedInit);

}
