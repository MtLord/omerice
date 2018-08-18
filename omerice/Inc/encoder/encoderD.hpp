/*
 * encoderD.hpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */

#ifndef ENCODER_ENCODERD_HPP_
#define ENCODER_ENCODERD_HPP_
#include "stm32f4xx_hal.h"
#include "encoders.hpp"
class encoderD
{
private:
	int cnt1=0;
	int cnt2=0;

	uint16_t pulse;
	float diameter;

public:


	encoderD(TIM_HandleTypeDef *_htim5,uint16_t stddev,float d):pulse(stddev*4),diameter(d)//encoderA(encoderhandle,pulse per return,revolutional diameter)
	{
		HAL_TIM_Encoder_Start(_htim5, TIM_CHANNEL_ALL);
		TIM5->CNT=2147483647;

	}
	long getcount();
	double getdistance();
	float getangle();//return current angleuradv
	float getvelocity();//Šp‘¬“x‚ğ•Ô‚·



};



#endif /* ENCODER_ENCODERD_HPP_ */
