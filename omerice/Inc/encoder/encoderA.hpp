/*
 * encoderA.hpp
 *
 *  Created on: 2018/05/28
 *      Author: —T‘¿
 */

#ifndef ENCODER_ENCODERA_HPP_
#define ENCODER_ENCODERA_HPP_
#include "stm32f4xx_hal.h"
#include "encoders.hpp"

class encoderA
{
private:

	long count=0;
	int cnt1=0;
	int cnt2=0;
	unsigned short CNT=0;
	unsigned long temp=0;
	int flag=0;
	uint16_t pulse;
	float diameter;

public:
	unsigned short over_count;

	encoderA(TIM_HandleTypeDef *_htim2,uint16_t stddev,float d):pulse(stddev*4),diameter(d)//encoderA(encoderhandle,pulse per return,revolutional diameter)
	{
		over_count=0;
		HAL_TIM_Encoder_Start(_htim2, TIM_CHANNEL_ALL);
		 TIM2->CNT=0;

		 HAL_TIM_Base_Start_IT(_htim2);
	}
	long getcount();
	float getdistance();
	float getangle();//return current angleuradv
	float getvelocity();//Šp‘¬“x‚ğ•Ô‚·

	volatile void Increment();//overflow counter
};




#endif /* ENCODER_ENCODERA_HPP_ */
