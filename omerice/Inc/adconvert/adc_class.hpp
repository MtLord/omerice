/*
 * ADCclass.hpp
 *
 *  Created on: 2018/08/11
 *      Author: —T‘¿
 */

#ifndef ADC_ADCCLASS_HPP_
#define ADC_ADCCLASS_HPP_

#include "stm32f4xx_hal.h"

class convert
{
protected:
	//const unsigned int ADCbuffer=4;
	const int ADC_BUFFER_LENGTH = 4 ;
	uint32_t g_ADCBuffer[ADC_BUFFER_LENGTH];
public:

	convert(ADC_HandleTypeDef *adc_dma)
	{
		HAL_ADC_Start_DMA(adc_dma, (uint32_t)g_ADCBuffer,ADC_BUFFER_LENGTH);
	}

};

class sensor:public convert
{

public:
	using convert::convert;
	long sensor1(){
		return g_ADCBuffer[0];
	}
	long sensor2(){
		return g_ADCBuffer[1];
	}
	long sensor3(){
		return g_ADCBuffer[2];
	}
	long interrupter();
};




#endif /* ADC_ADCCLASS_HPP_ */
