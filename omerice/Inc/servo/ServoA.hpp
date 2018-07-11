/*
 * ServoA.hpp
 *
 *  Created on: 2018/05/28
 *      Author: —T‘¿
 */

#ifndef SERVO_SERVOA_HPP_
#define SERVO_SERVOA_HPP_
#include "Servos.hpp"

class ServoA
{
	TIM_HandleTypeDef *htim2;
	long map(float x, long in_min, long in_max, long out_min, long out_max)//’l‚Ì”ÍˆÍ‚Ì•ÏŠ·ŠÖ”
			{
			  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
			}
public:
	ServoA(TIM_HandleTypeDef *_htim8):htim2(_htim8){}
	void begin();
	void set_pulse(float pulse);
	//void set_angle(float ag);–¢À‘•

};




#endif /* SERVO_SERVOA_HPP_ */
