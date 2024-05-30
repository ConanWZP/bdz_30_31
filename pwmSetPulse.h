#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "stm32f4xx_hal_tim.h"

//extern TIM_OC_InitTypeDef timerShim;

void pwmSetPulse(uint32_t pulse, TIM_HandleTypeDef timerFour);
