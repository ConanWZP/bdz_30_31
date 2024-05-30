#include "keyboard.h"

GPIO_InitTypeDef GPIO_B_KeyboardInit;

GPIO_InitTypeDef GPIO_E_KeyboardInit;

void initKeyboard(void) {

	// podklychenie modylya klaviatyri sleva
	
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	__HAL_RCC_GPIOE_CLK_ENABLE();

	GPIO_B_KeyboardInit.Pin = GPIO_PIN_2;
	GPIO_B_KeyboardInit.Mode = GPIO_MODE_OUTPUT_PP;
	//GPIO_B_KeyboardInit.Pull = GPIO_PULLDOWN;
	GPIO_B_KeyboardInit.Speed = GPIO_SPEED_LOW;
	GPIO_B_KeyboardInit.Pull = GPIO_PULLUP;
	// dlya 4 labi
  //GPIO_B_KeyboardInit.Mode = GPIO_MODE_IT_RISING_FALLING;
	//GPIO_B_KeyboardInit.Mode = GPIO_MODE_IT_FALLING;
  //GPIO_B_KeyboardInit.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_B_KeyboardInit);
	
	
	
	
	GPIO_E_KeyboardInit.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	GPIO_E_KeyboardInit.Mode = GPIO_MODE_IT_FALLING;
	GPIO_E_KeyboardInit.Speed = GPIO_SPEED_LOW;
	GPIO_E_KeyboardInit.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_E_KeyboardInit);
	
	// vozmogno ponadobitsya
	//HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	// vozmogno ponadobitsya
	//HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	
}
