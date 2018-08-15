/*
 * encoderB.cpp
 *
 *  Created on: 2018/06/07
 *      Author: 裕汰
 */
#include "encoderB.hpp"
extern TIM_HandleTypeDef htim14;
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
	return (getcount()*pi*diameter)/pulse;
}

 void encoderB::Increment()
{
	 if(flag==0)
	 {

									if(CNT<32768){//�ｿｽA�ｿｽ�ｿｽ�ｿｽ_�ｿｽ[�ｿｽt�ｿｽ�ｿｽ�ｿｽ[
										over_count--;
										flag=1;
									}
									else if(CNT>32768){//�ｿｽI�ｿｽ[�ｿｽo�ｿｽ[�ｿｽt�ｿｽ�ｿｽ�ｿｽ[
										over_count++;
										flag=1;
									}
										temp=over_count<<16;//overcount�ｿｽﾍシ�ｿｽt�ｿｽg�ｿｽ�ｿｽ�ｿｽ�ｿｽ
										HAL_TIM_Base_Start_IT(&htim14);
	 }
}
