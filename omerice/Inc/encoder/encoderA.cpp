#include "encoderA.hpp"



long encoderA::getcount()
{

	return TIM2->CNT-2147483647;

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


double encoderA::getdistance()
{
	return ((double)this->getcount()*pi*diameter)/(double)pulse;

}

void encoderA::Setdiameter(float d)
{
	diameter=d;
}

void encoderA::Setpulse(float p)
{
	pulse=p;
}
