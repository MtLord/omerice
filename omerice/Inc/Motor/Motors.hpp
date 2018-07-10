/*
 * Motors.hpp
 *
 *  Created on: 2018/05/27
 *      Author: —T‘¿
 */

#ifndef MOTOR_MOTORS_HPP_
#define MOTOR_MOTORS_HPP_


#include "stm32f4xx_hal.h"
class Motors
{
private:

protected:
	long map(float x, long in_min, long in_max, long out_min, long out_max)
	{
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}

	 const float max_rad;
public:

	Motors():max_rad(720){};
};



#endif /* MOTOR_MOTORS_HPP_ */
