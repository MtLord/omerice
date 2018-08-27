/*
 * encoderB.hpp
 *
 *  Created on: 2018/06/07
 *      Author: —T‘¿
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
	unsigned short CNT=0;
	unsigned long temp=0;

	uint16_t pulse;
	float diameter;
	TIM_HandleTypeDef *htim3;
public:
	int flag=0;

	encoderB(TIM_HandleTypeDef *_htim3,uint16_t stddev,float d):pulse(stddev*4),diameter(d),htim3(_htim3)
	{

		HAL_TIM_Encoder_Start(_htim3, TIM_CHANNEL_ALL);
		 TIM3->CNT=0x8000;
		HAL_TIM_Base_Start_IT(_htim3);

	}
	long getcount();
	void setcount(unsigned int c);
	 void InterruptIventCallback();


	//float getdistance();
	//float getangle();//return current angleuradv
	//float getvelocity();//Šp‘¬“x‚ğ•Ô‚·


};


#endif /* ENCODER_ENCODERB_HPP_ */
