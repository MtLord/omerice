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

	uint16_t pulse=1024;
	float diameter;

public:


	encoderD(TIM_HandleTypeDef *_htim5)//encoderA(encoderhandle,pulse per return,revolutional diameter)
	{
		HAL_TIM_Encoder_Start(_htim5, TIM_CHANNEL_ALL);
		TIM5->CNT=2147483647;
		this->Setdiameter(4.8);
	}
	long getcount();
	double getdistance();
	float getangle();//return current angleuradv
	float getvelocity();//Šp‘¬“x‚ğ•Ô‚·
	void  Setdiameter(float d);
	void Setpulse(float p);

};



#endif /* ENCODER_ENCODERD_HPP_ */
