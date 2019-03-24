/*
 * RotaryEncoder.hpp
 *
 *  Created on: 2018/12/22
 *      Author: —T‘¿
 */

#ifndef ENCODER_ROTARYENCODER_HPP_
#define ENCODER_ROTARYENCODER_HPP_
#include "stm32f4xx_hal.h"
#include "tim.h"

class Encoder
{
protected:
	const unsigned long offset=0x80000000;
	TIM_HandleTypeDef *htim;
public:
	Encoder(TIM_HandleTypeDef *tim):htim(tim)
	{
		htim->Instance->CNT=offset;
		HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
	}

	 long getcount();
};

class IntEncoder
{
	const unsigned short offset=0x8000;
	TIM_HandleTypeDef *_htim;
public:
	IntEncoder(TIM_HandleTypeDef *_tim):_htim(_tim)
	{
		_htim->Instance->CNT=offset;
		HAL_TIM_Encoder_Start(_htim, TIM_CHANNEL_ALL);
	}

	long getcount();
};



#endif /* ENCODER_ROTARYENCODER_HPP_ */
