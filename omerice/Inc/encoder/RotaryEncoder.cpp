/*
 * RotaryEncoder.cpp
 *
 *  Created on: 2018/12/22
 *      Author: —T‘¿
 */

#include "RotaryEncoder.hpp"

long Encoder::getcount()
{
	return htim->Instance->CNT-this->offset;
}

long IntEncoder::getcount()
{
	return _htim->Instance->CNT-this->offset;
}
