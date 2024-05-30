#include "initPinsDisplay.h"


void PINS_DISPLAY_Init(void) {
	
  GPIO_InitTypeDef GPIOB_InitStruct;
	GPIO_InitTypeDef GPIOC_InitStruct;
	GPIO_InitTypeDef GPIOE_InitStruct;


  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();



  GPIOB_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
  GPIOB_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIOB_InitStruct.Pull = GPIO_NOPULL;
  GPIOB_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOB, &GPIOB_InitStruct);

	
	
  GPIOC_InitStruct.Pin = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  GPIOC_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIOC_InitStruct.Pull = GPIO_NOPULL;
  GPIOC_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOC, &GPIOC_InitStruct);

  GPIOE_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
  GPIOE_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIOE_InitStruct.Pull = GPIO_NOPULL;
  GPIOE_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOE, &GPIOE_InitStruct);
}
