/*
 * enocderD.cpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */
#include "encoderD.hpp"
long encoderD::getcount()
{
	CNT=TIM5->CNT;
	return CNT;
}

void encoderD::setcount(unsigned c)
{
	htim5->Init.Period=c;
}



