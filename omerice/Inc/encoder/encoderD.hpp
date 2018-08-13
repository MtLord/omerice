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

	long count=0;
	int cnt1=0;
	int cnt2=0;
	unsigned short CNT=0;
	unsigned long temp=0;

	uint16_t pulse;
	float diameter;
	TIM_HandleTypeDef *htim5;
public:


	encoderD(TIM_HandleTypeDef *_htim5,uint16_t stddev,float d):pulse(stddev*4),diameter(d),htim5(_htim5)
	{

		HAL_TIM_Encoder_Start(_htim5, TIM_CHANNEL_ALL);
		 TIM5->CNT=0;

	}
	long getcount();
	void setcount(unsigned int c);//interrupt count value
	void InterruptIventCallback();

	 ~encoderD(){}
	//float getdistance();
	//float getangle();//return current angleuradv
	//float getvelocity();//Šp‘¬“x‚ğ•Ô‚·


};




#endif /* ENCODER_ENCODERD_HPP_ */
