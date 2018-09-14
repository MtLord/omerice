/*
 * encoderB.hpp
 *
 *  Created on: 2018/06/07
 *      Author: —T‘¿
 */

#ifndef ENCODER_ENCODERB_HPP_
#define ENCODER_ENCODERB_HPP_
#include "encoders.hpp"
#include "Motor/MotorD.hpp"
#include "Motor/MotorE.hpp"
#include "Motor/MotorF.hpp"
#include "Motor/MotorC.hpp"

#include "stm32f4xx_hal.h"
class encoderB
{
private:
	MotorD *m_d;
	MotorE *m_e;
	MotorF *m_f;
	MotorC *m_c;
	unsigned short CNT=0;

	TIM_HandleTypeDef *htim3;
public:
	int flag=0;
	void begin(MotorC *motord,MotorD *_motord,MotorE *_motore,MotorF *_motorf)
	{
		m_d=_motord;
		m_e=_motore;
		m_f=_motorf;
		m_c=motord;
	}
	encoderB(TIM_HandleTypeDef *_htim3):htim3(_htim3)
	{

		HAL_TIM_Encoder_Start(_htim3, TIM_CHANNEL_ALL);
		 TIM3->CNT=0x8000;


	}
	long getcount();
	void setcount(unsigned int c);
	 void InterruptIventCallback();


	//float getdistance();
	//float getangle();//return current angleuradv
	//float getvelocity();//Šp‘¬“x‚ğ•Ô‚·


};


#endif /* ENCODER_ENCODERB_HPP_ */
