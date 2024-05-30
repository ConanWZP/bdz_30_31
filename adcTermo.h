#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "stm32f4xx_hal_adc.h"

extern GPIO_InitTypeDef GPIO_ADCInitStruct;
extern ADC_HandleTypeDef adcStruct;
extern ADC_ChannelConfTypeDef adcConfig;



void initAdc(void);

void ADC_IRQHandler(void);

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);