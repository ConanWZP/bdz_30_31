#include "timerForDisplay.h"


TIM_HandleTypeDef timerInit;


void initDelay(void) {

    __HAL_RCC_TIM2_CLK_ENABLE();

    timerInit.Instance = TIM2;
    timerInit.Init.Prescaler = 1;
    timerInit.Init.CounterMode = TIM_COUNTERMODE_UP;
    timerInit.Init.Period = 12;

    HAL_TIM_Base_Init(&timerInit);

    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    HAL_TIM_Base_Start(&timerInit);
}


void Delay_us(uint32_t microseconds) {
		/*
    uint32_t startTime = __HAL_TIM_GET_COUNTER(&timerInit);

    while ((__HAL_TIM_GET_COUNTER(&timerInit) - startTime) < microseconds) {
       // gdet ykazannoe chislo microsenods
    }
	  */
  __HAL_TIM_SET_COUNTER(&timerInit, 0);
  __HAL_TIM_CLEAR_FLAG(&timerInit, TIM_FLAG_UPDATE);
	
  while(__HAL_TIM_GET_COUNTER(&timerInit) < microseconds) {
    if (__HAL_TIM_GET_FLAG(&timerInit, TIM_FLAG_UPDATE) != RESET) {
      break;
    }
		
  }
}


void TIM2_IRQHandler(void) {
    HAL_TIM_IRQHandler(&timerInit);
}
