#include "adcTermo.h"
/*
#include "timerInit.h"
#include "pwmSetPulse.h"
#include "initShim.h"
#include "initTim4.h"
*/


GPIO_InitTypeDef GPIO_ADCInitStruct;
ADC_HandleTypeDef adcStruct;
ADC_ChannelConfTypeDef adcConfig;



void initAdc(void) {

	__HAL_RCC_ADC1_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	
	
	GPIO_ADCInitStruct.Pin = GPIO_PIN_1; 
	GPIO_ADCInitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_ADCInitStruct.Pull = GPIO_NOPULL;
	GPIO_ADCInitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOC, &GPIO_ADCInitStruct); 
	
	
	adcStruct.Instance = ADC1;
	adcStruct.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adcStruct.Init.Resolution = ADC_RESOLUTION12b;
	adcStruct.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	//disable for 4-9 task lr 5-6
	//adcStruct.Init.ScanConvMode = DISABLE;
	adcStruct.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	//adcStruct.Init.ContinuousConvMode = DISABLE;
	adcStruct.Init.ContinuousConvMode = ENABLE;
	
	//adcStruct.Init.NbrOfConversion = 1;
	adcStruct.Init.DiscontinuousConvMode = DISABLE;
	//adcStruct.Init.NbrOfDiscConversion = 0;
	adcStruct.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	adcStruct.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	//disable for 4-9 task lr 5-6
	//adcStruct.Init.DMAContinuousRequests = DISABLE;
	
		// task 13, need modificate adcStruct
	adcStruct.Init.ScanConvMode = DISABLE; // turn on scan for task 13
	adcStruct.Init.ContinuousConvMode = ENABLE; 

	adcStruct.Init.NbrOfConversion = 1; // number of channels
	adcStruct.Init.DMAContinuousRequests = DISABLE; // enable DMA
	
	
  HAL_ADC_Init(&adcStruct);
    

	adcConfig.Channel = ADC_CHANNEL_1; // sootvetstvyet PC1
	adcConfig.Rank = 1;
	adcConfig.SamplingTime = ADC_SAMPLETIME_144CYCLES;
	
	HAL_ADC_ConfigChannel(&adcStruct, &adcConfig);
    
		
	
	//HAL_ADC_Start(&adcStruct);
	
	// ne nado dlya dma
	HAL_NVIC_EnableIRQ(ADC_IRQn);
	
	//HAL_ADC_Start_IT(&adcStruct);
	
	
	
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
	//(adcVar > 1000) ? (pwmSetPulse(1000, timerFour)) : (pwmSetPulse(adcVar, timerFour));
	// this code can be transfered to main, like id was made for 117 line
	
	if (hadc == &adcStruct) {
			/*
        // obrabotka dannix from ADC for first channel ( red diode )
        uint16_t adc_value_red = (uint16_t)adc_buffer[0];
        // yarkost' of red diod controlled with SHIM
				(adc_value_red > 1000) ? (pwmSetPulse(1000, timerFour)) : (pwmSetPulse(adc_value_red, timerFour));
        
        // obrabotka dannix form ADC for second channel (green diode)
        uint16_t adc_value_green = (uint16_t)adc_buffer[1];
        if (adc_value_green > 500) {
            HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
        }
		 */
    }
	
	
}

void ADC_IRQHandler(void){
	HAL_ADC_IRQHandler(&adcStruct);	
}
