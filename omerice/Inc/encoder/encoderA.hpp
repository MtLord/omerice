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

	float diameter;
public:
uint16_t pulse;
unsigned short CNT=0;
unsigned long temp=0;
unsigned short over_count;

	encoderA(TIM_HandleTypeDef *_htim2,uint16_t stddev,float d):pulse(stddev*4),diameter(d)
	{
		over_count=1;
		HAL_TIM_Encoder_Start(_htim2, TIM_CHANNEL_ALL);
		 TIM2->CNT=0;
	}
	long getcount();
	float getdistance();
	float getangle();//return current angleuradv
	float getvelocity();//Šp‘¬“x‚ğ•Ô‚·

};




#endif /* ENCODER_ENCODERA_HPP_ */
