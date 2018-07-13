/*
 * Serbos.hpp
 *
 *  Created on: 2018/05/28
 *      Author: —T‘¿
 */

#ifndef SERVO_SERVOS_HPP_
#define SERVO_SERVOS_HPP_
#include "stm32f4xx_hal.h"

class serovo{
public:

	long map(float x, long in_min, long in_max, long out_min, long out_max)//’l‚Ì”ÍˆÍ‚Ì•ÏŠ·ŠÖ”
				{
				  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
				}

};














#endif /* SERVO_SERVOS_HPP_ */
