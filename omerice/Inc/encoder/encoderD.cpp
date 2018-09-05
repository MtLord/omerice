/*
 * enocderD.cpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */
#include "encoderD.hpp"




long encoderD::getcount()
{

	return TIM5->CNT-2147483647;

}

float encoderD::getangle()
{
	return this->getcount()*2*pi/pulse;
}

float encoderD::getvelocity()
{
	cnt1=this->getangle();
	HAL_Delay(sptim);
	cnt2=this->getangle();
	return (cnt2-cnt1)*1000/sptim;
}


double encoderD::getdistance()
{
	return ((double)this->getcount()*pi*diameter)/((double)pulse*4);

}

void encoderD::Setdiameter(float d)
{
	diameter=d;
}
void encoderD::Setpulse(float p)
{
	pulse=p;
}
