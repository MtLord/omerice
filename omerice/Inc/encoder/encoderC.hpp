/*
 * encoderC.hpp
 *
 *  Created on: 2018/08/10
 *      Author: óTëø
 */

#ifndef ENCODER_ENCODERC_HPP_
#define ENCODER_ENCODERC_HPP_
#include "stm32f4xx_hal.h"
#include "encoders.hpp"
class encoderC
{
private:

	MotorD *m_d;
		MotorE *m_e;
		MotorF *m_f;
	unsigned short CNT=0;
	unsigned long temp=0;


	TIM_HandleTypeDef *htim4;
public:
	int flag=0;

	encoderC(TIM_HandleTypeDef *_htim4):htim4(_htim4)
	{

		HAL_TIM_Encoder_Start(_htim4, TIM_CHANNEL_ALL);
		 TIM4->CNT=0x8000;

	}
	void begin(MotorD *_motord,MotorE *_motore,MotorF *_motorf)
		{
			m_d=_motord;
			m_e=_motore;
			m_f=_motorf;
		}
	long getcount();
	void setcount(unsigned int c);
	 void InterruptIventCallback();

	 ~encoderC(){}
	//float getdistance();
	//float getangle();//return current angleÅuradÅv
	//float getvelocity();//äpë¨ìxÇï‘Ç∑


};




#endif /* ENCODER_ENCODERC_HPP_ */
