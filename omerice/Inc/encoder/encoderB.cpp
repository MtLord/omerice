/*
 * encoderB.cpp
 *
 *  Created on: 2018/06/07
 *      Author: —T‘¿
 */
#include "encoderB.hpp"
long encoderB::getcount()
{
	CNT=TIM3->CNT;

	return temp|CNT;
}

float encoderB::getangle()
{
	return this->getcount()*2*pi/pulse;
}
float encoderB::getvelocity()
{
	cnt1=this->getangle();
	HAL_Delay(sptim);
	cnt2=this->getangle();
	return (cnt2-cnt1)*1000/sptim;
}

float encoderB::getdistance(){
	return getcount()*pi*diameter/pulse;
}
