#include "encoderA.hpp"

extern TIM_HandleTypeDef htim13;

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
	return ((float)this->getcount()*pi*diameter)/(float)pulse;

}


volatile void encoderA::Increment()
{

if(flag==0)
{

						if((this->CNT)<32500&&this->CNT>=0)// この瞬間はアンダーフロー
						{


							over_count--;
							temp=over_count<<16;//overcount�ｿｽﾍシ�ｿｽt�ｿｽg�ｿｽ�ｿｽ�ｿｽ�ｿｽ
							flag=1;

						}
						else if(this->CNT>32500&&this->CNT<=65535)
						{

							over_count++;
							temp=over_count<<16;
							flag=1;
						}

						HAL_TIM_Base_Start_IT(&htim13);
}
}
