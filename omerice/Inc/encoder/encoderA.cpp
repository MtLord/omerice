#include "encoderA.hpp"



long encoderA::getcount()
{
	TIM2->CR1&=0<<1;
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

TIM2->CR1|=0x1<<1;

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

TIM2->CR1^=0b0000000000000010;
}
