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
	int cnt1=0;
	int cnt2=0;

	uint16_t pulse;
	float diameter;

public:


	encoderA(TIM_HandleTypeDef *_htim2,uint16_t stddev):pulse(stddev*4)//encoderA(encoderhandle,pulse per return)
	{
		HAL_TIM_Encoder_Start(_htim2, TIM_CHANNEL_ALL);
		TIM2->CNT=2147483647;
		this->Setdiameter(4.8);
	}
	long getcount();
	double getdistance();
	float getangle();//return current angleuradv
	float getvelocity();//Šp‘¬“x‚ğ•Ô‚·
	void  Setdiameter(float d);


};




#endif /* ENCODER_ENCODERA_HPP_ */
