/*
 * encoderB.cpp
 *
 *  Created on: 2018/06/07
 *      Author: 裕汰
 */
#include "encoderB.hpp"
long encoderB::getcount()
{
	CNT=TIM3->CNT;
	return CNT;
}

void encoderB::setcount(unsigned c)
{
	htim3->Init.Period=c;
}
