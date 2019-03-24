/*
 * ADCclass.hpp
 *
 *  Created on: 2018/08/11
 *      Author: —T‘¿
 */

#ifndef ADC_ADCCLASS_HPP_
#define ADC_ADCCLASS_HPP_

#include "stm32f4xx_hal.h"




class Sensor
{
	ADC_HandleTypeDef *adchandle;
		long Getadcvalue=0;
public:
		Sensor(ADC_HandleTypeDef *adc_dma):adchandle(adc_dma){

		}
	long sensor1()
	{
		HAL_ADC_Start(adchandle);
		 if(HAL_ADC_PollForConversion(adchandle,1000)==HAL_OK)
			  {

			 	 Getadcvalue= HAL_ADC_GetValue(adchandle);
			  }
		 HAL_ADC_Stop(adchandle);
		 return Getadcvalue;
	}
		 void interrupter1();
		 void interrupter2();
	void interrupter3();
};




#endif /* ADC_ADCCLASS_HPP_ */
