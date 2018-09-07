/*
 * enocderD.cpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */
#include "encoderD.hpp"
#include "Robot.hpp"
#include "math.h"
extern Robot *Robo;

long encoderD::getcount()
{

	return TIM5->CNT-2147483647;

}









