#include "encoderA.hpp"



long encoderA::getcount()
{

	return TIM2->CNT-2147483647;

}

float encoderA::getvelocity()
{
	cnt1=this->getangle();
	HAL_Delay(sptim);
	cnt2=this->getangle();
	return (cnt2-cnt1)*1000/sptim;
}


