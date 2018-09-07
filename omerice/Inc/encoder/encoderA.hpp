/*
 * encoderA.hpp
 *
 *  Created on: 2018/05/28
 *      Author: �T��
 */

#ifndef ENCODER_ENCODERA_HPP_
#define ENCODER_ENCODERA_HPP_
#include "stm32f4xx_hal.h"
#include "encoders.hpp"

class encoderA
{
private:
	const float pi=3.141592;
	int cnt1=0;
	int cnt2=0;
float sptim;


public:


	encoderA(TIM_HandleTypeDef *_htim2)//encoderA(encoderhandle,pulse per return)
	{
		HAL_TIM_Encoder_Start(_htim2, TIM_CHANNEL_ALL);
		TIM2->CNT=2147483647;

	}
	long getcount();

	float getangle();//return current angle�urad�v
	float getvelocity();//�p���x��Ԃ�

};




#endif /* ENCODER_ENCODERA_HPP_ */
