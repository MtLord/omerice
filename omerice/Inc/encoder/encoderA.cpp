#include "encoderA.hpp"



long encoderA::getcount()
{
	CNT=TIM2->CNT;

	return temp|CNT;
}

float encoderA::getangle()
{
	return this->getcount()*2*pi/pulse;
}

float encoderA::getvelocity()
{
	cnt1=this->getangle();
	HAL_Delay(sptim);
	cnt2=this->getangle();
	return (cnt2-cnt1)*1000/sptim;
}


float encoderA::getdistance()
{
	return getcount()*pi*diameter/pulse;
}

