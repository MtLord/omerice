/*
 * encoderC.cpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */

#include "encoderC.hpp"
long encoderC::getcount()
{
	CNT=TIM4->CNT;
	return CNT;
}

void encoderC::setcount(unsigned c)
{
	htim4->Init.Period=c;
}

