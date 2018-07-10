/*
 * encoderB.hpp
 *
 *  Created on: 2018/06/07
 *      Author: 裕汰
 */

#ifndef ENCODER_ENCODERB_HPP_
#define ENCODER_ENCODERB_HPP_
#include "encoders.hpp"
#include "stm32f4xx_hal.h"
class encoderB
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
	encoderB(TIM_HandleTypeDef *htim3,uint16_t stddev,float d):pulse(stddev*4),diameter(d)
	{
		over_count=1;
		HAL_TIM_Encoder_Start(htim3, TIM_CHANNEL_ALL);
		 TIM3->CNT=0;
	}
	long getcount();
	float getdistance();
	float getangle();//読んだ時点での角度を返す 単位「rad」
	float getvelocity();//角速度を返す
};




#endif /* ENCODER_ENCODERB_HPP_ */
