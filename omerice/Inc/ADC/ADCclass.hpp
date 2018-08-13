/*
 * ADCclass.hpp
 *
 *  Created on: 2018/08/11
 *      Author: —T‘¿
 */

#ifndef ADC_ADCCLASS_HPP_
#define ADC_ADCCLASS_HPP_
#include "stm32f4xx_hal.h"

class adc
{
private:
	//const unsigned int ADCbuffer=4;
	enum{ ADC_BUFFER_LENGTH = 2 };
	uint16_t g_ADCBuffer[ADC_BUFFER_LENGTH];
public:
	adc(ADC_HandleTypeDef *adc_dma)
	{
		HAL_ADC_Start_DMA(adc_dma, (uint32_t)g_ADCBuffer,ADC_BUFFER_LENGTH);
	}



};




#endif /* ADC_ADCCLASS_HPP_ */
