/*
 * encoderC.hpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */

#ifndef ENCODER_ENCODERC_HPP_
#define ENCODER_ENCODERC_HPP_
#include "stm32f4xx_hal.h"
#include "encoders.hpp"
class encoderC
{
private:

	long count=0;
	int cnt1=0;
	int cnt2=0;
	unsigned short CNT=0;
	unsigned long temp=0;

	uint16_t pulse;
	float diameter;
	TIM_HandleTypeDef *htim4;
public:
	int flag=0;

	encoderC(TIM_HandleTypeDef *_htim4,uint16_t stddev,float d):pulse(stddev*4),diameter(d),htim4(_htim4)
	{

		HAL_TIM_Encoder_Start(_htim4, TIM_CHANNEL_ALL);
		 TIM4->CNT=0x8000;
		 HAL_TIM_Base_Start_IT(_htim4);
	}
	long getcount();
	void setcount(unsigned int c);
	 void InterruptIventCallback();

	 ~encoderC(){}
	//float getdistance();
	//float getangle();//return current angleuradv
	//float getvelocity();//Šp‘¬“x‚ğ•Ô‚·


};




#endif /* ENCODER_ENCODERC_HPP_ */
